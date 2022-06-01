#include "controller.h"
#include <iostream>
using namespace std;

Controller::Controller(QObject *parent) : QObject(parent), view(nullptr), model(nullptr)
{}

void Controller::setView(chartViewer *v)
{
    view  = v;
    if (view != nullptr && model != nullptr)
        view->setData(model->getTrainings());
}

void Controller::setModel(Model *m)
{
    model = m;
    if (view != nullptr && model != nullptr)
        view->setData(model->getTrainings());
}

void Controller::extractValues(trainingValues values, DateTime &start, TimeSpan &duration, std::vector<std::string> &exName, std::vector<TimeSpan> &exDuration, std::vector<TimeSpan> &exRecovery) const
{
    std::vector<QString> names = values.exName;
    std::vector<QTime> durations = values.exDuration;
    std::vector<QTime> recoveries = values.exRecovery;

    DateTimeConverter converter;
    start = converter.toDateTime(values.start);
    if (values.type == QString("Endurance") || values.type == QString("Ciclismo") || values.type == QString("Corsa")
           || values.type == QString("Camminata"))
        duration = converter.toTime(values.duration);

    for(auto it = names.begin(); it != names.end(); ++it)
        exName.push_back((*it).toStdString());

    for(auto it = durations.begin(); it != durations.end(); ++it)
        exDuration.push_back(converter.toTime(*it));

    for(auto it = recoveries.begin(); it != recoveries.end(); ++it)
        exRecovery.push_back(converter.toTime(*it));
}

void Controller::add() const
{
    try {
        trainingValues values = view->showAddDialog();
        DateTimeConverter converter;
        DateTime start;
        TimeSpan duration;
        std::vector<std::string> exName;
        std::vector<Time> exDuration;
        std::vector<Time> exRecovery;
        extractValues(values,start,duration,exName,exDuration,exRecovery);
        model->addNewTraining(values.type.toStdString(),values.name.toStdString(),
                              start,values.distance,duration,&exName,&exDuration,&exRecovery);

        view->showData();
    }  catch (std::runtime_error e) {
            view->showWarning(QString::fromStdString(e.what()));
    }
       catch (std::invalid_argument e){
            view->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::set() const
{
    try {
        trainingValues values = view->showSetDialog();
        DateTimeConverter converter;
        DateTime start;
        TimeSpan duration;
        std::vector<std::string> exName;
        std::vector<Time> exDuration;
        std::vector<Time> exRecovery;

        extractValues(values,start,duration,exName,exDuration,exRecovery);

        model->setTraining(values.pos,values.name.toStdString(),start,values.distance,duration,values.exPos,values.exAct
                           ,&exName,&exDuration, &exRecovery);
        view->showData();
    }  catch (std::runtime_error e) {
        view->showWarning(QString::fromStdString(e.what()));
    }
    catch (std::invalid_argument e){
        view->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::remove() const
{
    try {
        trainingValues values = view->showRemoveDialog();
        model->removeTraining(values.pos);
        view->showData();
    }  catch (std::runtime_error e) {
            view->showWarning(QString::fromStdString(e.what()));
    }
       catch (std::invalid_argument e){
            view->showWarning(QString::fromStdString(e.what()));
    }
}
