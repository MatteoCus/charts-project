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
    duration = converter.toTime(values.duration);

    for(auto it = names.end()--; it != names.begin()--; --it)
        exName.push_back((*it).toStdString());

    for(auto it = durations.end()--; it != durations.begin()--; --it)
        exDuration.push_back(converter.toTime(*it));

    for(auto it = recoveries.end()--; it != recoveries.begin()--; --it)
        exRecovery.push_back(converter.toTime(*it));
}

void Controller::add() const
{
    trainingValues values = view->showAddDialog();

    DateTimeConverter converter;
    DateTime start;
    TimeSpan duration;
    std::vector<std::string> exName;
    std::vector<Time> exDuration;
    std::vector<Time> exRecovery;

    extractValues(values,start,duration,exName,exDuration,exRecovery);

    try {
        model->addNewTraining(values.type.toStdString(),values.name.toStdString(),
                              start,values.distance,duration,&exName,&exDuration,&exRecovery);

    }  catch (std::runtime_error e) {
            view->showWarning(QString::fromStdString(e.what()));
            cout<<"Cosa?"<<endl;
    }
       catch (std::invalid_argument e){
            view->showWarning(QString::fromStdString(e.what()));
    }
    view->showData();
}

void Controller::set() const
{
    trainingValues values = view->showSetDialog();
    DateTimeConverter converter;
    DateTime start;
    TimeSpan duration;
    std::vector<std::string> exName;
    std::vector<Time> exDuration;
    std::vector<Time> exRecovery;

    extractValues(values,start,duration,exName,exDuration,exRecovery);

    try {
        model->setTraining(values.pos,values.name.toStdString(),start,values.distance,duration,values.exPos,values.exAct
                           ,&exName,&exDuration, &exRecovery);
    }  catch (std::runtime_error e) {
        view->showWarning(QString::fromStdString(e.what()));
    }
    catch (std::invalid_argument e){
        view->showWarning(QString::fromStdString(e.what()));
    }
    view->showData();
}

void Controller::remove() const
{
    trainingValues values = view->showRemoveDialog();
    try {
        model->removeTraining(values.pos);

    }  catch (std::runtime_error e) {
            view->showWarning(QString::fromStdString(e.what()));
    }
       catch (std::invalid_argument e){
            view->showWarning(QString::fromStdString(e.what()));
    }
    view->showData();
}
