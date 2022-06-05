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

    void extractFromViewValues(trainingValues values, DateTime& start, TimeSpan& duration,std::vector<std::string>& exName,
                std::vector<Time>& exDuration,std::vector<Time>& exRecovery) const;
    std::vector<trainingValues> extractFromModelValues(const std::list<Training*>* trainings) const;

public:
    explicit Controller(QObject *parent = nullptr);
    void setView(chartViewer* v);
    void setModel(Model* m);

public slots:
    void add() const;
    void set() const;
    void remove() const;
    void save() const;
};

#endif // CONTROLLER_H
