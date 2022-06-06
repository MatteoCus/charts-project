#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include "../trainingvalues.h"
#include "xmlfilehandler.h"
#include "../DateTime/datetimeconverter.h"
#include "../DateTime/datetime.h"
#include "../View/chartviewer.h"
#include "../Model/model.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    chartViewer* view;
    Model* model;
    bool saved;
    QString filenameSaved;

    void extractFromViewValues(trainingValues values, DateTime& start, TimeSpan& duration,std::vector<std::string>& exName,
                std::vector<Time>& exDuration,std::vector<Time>& exRecovery) const;
    std::vector<trainingValues> extractFromModelValues(const std::list<Training*>* trainings) const;

public:
    explicit Controller(QObject *parent = nullptr);
    void setView(chartViewer* v);
    void setModel(Model* m);

public slots:
    void add();
    void set();
    void remove();
    void newPlan();
    void save();        //modifica i campi "saved" e "filenameSaved"
    void saveAs() const;
    void open();
};

#endif // CONTROLLER_H
