#include "controller.h"
#include <iostream>
using namespace std;

Controller::Controller(QObject *parent) : QObject(parent), view(nullptr), model(nullptr), saved(false), filenameSaved("")
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

void Controller::extractFromViewValues(trainingValues values, DateTime &start, TimeSpan &duration, std::vector<std::string> &exName, std::vector<TimeSpan> &exDuration, std::vector<TimeSpan> &exRecovery) const
{
    std::vector<QString> names = values.exName;
    std::vector<QTime> durations = values.exDuration;
    std::vector<QTime> recoveries = values.exRecovery;

    start = DateTimeConverter::toDateTime(values.start);
    if (values.type == QString("Endurance") || values.type == QString("Ciclismo") || values.type == QString("Corsa")
           || values.type == QString("Camminata"))
        duration = DateTimeConverter::toTime(values.duration);

    for(auto it = names.begin(); it != names.end(); ++it)
        exName.push_back((*it).toStdString());

    for(auto it = durations.begin(); it != durations.end(); ++it)
        exDuration.push_back(DateTimeConverter::toTime(*it));

    for(auto it = recoveries.begin(); it != recoveries.end(); ++it)
        exRecovery.push_back(DateTimeConverter::toTime(*it));
}

std::vector<trainingValues> Controller::extractFromModelValues(const std::list<Training *> *trainings) const
{
    std::vector<trainingValues> vector;
    for(auto it= trainings->begin(); it!=trainings->end();++it)
    {
        if (*it == nullptr)
            throw std::runtime_error("Errore nel riconscimento degli allenamenti!");

        QString type;
        QDateTime start;
        QString name;
        double distance = 0.0;
        QTime duration;
        std::vector<QString> exName;
        std::vector<QTime> exDuration;
        std::vector<QTime> exRecovery;

        start = DateTimeConverter::toQDateTime((*it)->getStart());
        name = QString::fromStdString((*it)->getName());

        bool endurance = false, repetition = false;

        if(dynamic_cast<const Endurance*>(*it))
        {
            endurance = true;
            if(dynamic_cast<const Run*>(*it))
                type = "Corsa";
            else if(dynamic_cast<const Walk*>(*it))
                type = "Camminata";
            else //if(dynamic_cast<const Cycling*>(*it))
                type = "Ciclismo";
        }
        else
        {
            repetition = true;
            if(dynamic_cast<const Tennis*>(*it))
                type = "Tennis";
            else //if(dynamic_cast<const Rugby*>(*it))
                type = "Rugby";
        }

        if(endurance)
        {
            const Endurance* end = static_cast<const Endurance*>(*it);
            duration = DateTimeConverter::toQTime(end->getDuration());
            distance = end->getDistance();
        }
        else if(repetition)
        {
            const Repetition* rep = static_cast<const Repetition*>(*it);
            std::vector<Exercise*> ex = rep->getExercises();

            for(auto it : ex)
            {
                exName.push_back(QString::fromStdString(it->getName()));
                exDuration.push_back(DateTimeConverter::toQTime(it->getDuration()));
                exRecovery.push_back(DateTimeConverter::toQTime(it->getRecoveryTime()));
            }

        }
        else
            throw std::runtime_error("Allenamenti non corretti!");

        trainingValues val(type,start,name,distance,duration,exName,exDuration,exRecovery);

        vector.push_back(val);

    }
    return vector;
}

void Controller::add()
{
    try {
        trainingValues values = view->showAddDialog();
        DateTime start;
        TimeSpan duration;
        std::vector<std::string> exName;
        std::vector<Time> exDuration;
        std::vector<Time> exRecovery;
        extractFromViewValues(values,start,duration,exName,exDuration,exRecovery);
        model->addNewTraining(values.type.toStdString(),values.name.toStdString(),
                              start,values.distance,duration,&exName,&exDuration,&exRecovery);
        saved = false;
        view->showData();
    }  catch (std::runtime_error e) {
            view->showWarning(QString::fromStdString(e.what()));
    }
       catch (std::invalid_argument e){
            view->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::set()
{
    try {
        trainingValues values = view->showSetDialog();
        DateTime start;
        TimeSpan duration;
        std::vector<std::string> exName;
        std::vector<Time> exDuration;
        std::vector<Time> exRecovery;

        extractFromViewValues(values,start,duration,exName,exDuration,exRecovery);

        model->setTraining(values.pos,values.name.toStdString(),start,values.distance,duration,values.exPos,values.exAct
                           ,&exName,&exDuration, &exRecovery);
        saved = false;
        view->showData();
    }  catch (std::runtime_error e) {
        view->showWarning(QString::fromStdString(e.what()));
    }
    catch (std::invalid_argument e){
        view->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::remove()
{
    try {
        trainingValues values = view->showRemoveDialog();
        model->removeTraining(values.pos);
        saved = false;
        view->showData();
    }  catch (std::runtime_error e) {
            view->showWarning(QString::fromStdString(e.what()));
    }
       catch (std::invalid_argument e){
            view->showWarning(QString::fromStdString(e.what()));
    }
}

void Controller::newPlan()
{
    try {
        if(!saved && QMessageBox::information(view,"Salvataggio", "I dati non sono salvati, salvare?", QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
            save();
        model->removeTrainings();
        saved = false;
        view->showData();

    }  catch (std::runtime_error e) {
        view->showWarning(e.what());
    }
}

void Controller::save()
{
    try{
        if(!saved && filenameSaved=="")
            filenameSaved = xmlFileHandler::getWriteFileName();
        QFile file(filenameSaved);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(view, tr("QXmlStream"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(QDir::toNativeSeparators(filenameSaved),
                                      file.errorString()));
            throw std::runtime_error("Errore all'apertura del file!");
        }

        std::vector<trainingValues> trainings = extractFromModelValues(model->getTrainings());
        xmlFileHandler::write(&file,trainings);

        QMessageBox::information(view,"Salvataggio","Salvataggio avvenuto correttamente!");
        saved = true;

    }  catch (std::runtime_error e) {
        if(!saved)
            filenameSaved = "";

        view->showWarning(e.what());
    }
}

void Controller::saveAs() const
{
    try {

        QString fileName = xmlFileHandler::getWriteFileName();
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(view, tr("QXmlStream"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(QDir::toNativeSeparators(fileName),
                                      file.errorString()));
            throw std::runtime_error("Errore all'apertura del file!");
        }

        std::vector<trainingValues> trainings = extractFromModelValues(model->getTrainings());
        xmlFileHandler::write(&file,trainings);

        QMessageBox::information(view,"Salvataggio","Salvataggio avvenuto correttamente!");
    }  catch (std::runtime_error e) {
        view->showWarning(e.what());
    }

}

void Controller::open()
{
    try {
        if(!saved && QMessageBox::information(view,"Salvataggio", "I dati non sono salvati, salvare?", QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
            save();
        model->removeTrainings();
        saved = false;

        QString fileName = xmlFileHandler::getReadFileName();
        QFile file(fileName);

        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(view, tr("QXmlStream"),
                                 tr("Cannot read file %1:\n%2.")
                                 .arg(QDir::toNativeSeparators(fileName),
                                      file.errorString()));
            throw std::runtime_error("Errore all'apertura del file!");
        }

        std::vector<trainingValues> values = xmlFileHandler::read(&file);


        for(auto it : values)
        {
            DateTime start;
            TimeSpan duration;
            std::vector<std::string> exName;
            std::vector<Time> exDuration;
            std::vector<Time> exRecovery;

            extractFromViewValues(it,start,duration,exName,exDuration,exRecovery);
            model->addNewTraining(it.type.toStdString(),it.name.toStdString(),
                              start,it.distance,duration,&exName,&exDuration,&exRecovery);
        }
        saved = false;
        view->showData();

    }  catch (std::runtime_error e) {
        view->showWarning(e.what());
    }
}
