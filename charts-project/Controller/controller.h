#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include "../dialogvalues.h"
#include "xmlfilehandler.h"
#include "../DateTime/datetimeconverter.h"
#include "../DateTime/datetime.h"
#include "../View/chartviewer.h"
#include "../View/initialdialog.h"
#include "../Model/model.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    chartViewer* view;
    Model* model;
    bool saved, firstResponse;
    QString filenameSaved;

    void extractFromViewValues(dialogValues values, DateTime& start, TimeSpan& duration,std::vector<std::string>& exName,
                std::vector<Time>& exDuration,std::vector<Time>& exRecovery, int& pos, action& exAct, int& exPos) const;
    std::vector<trainingValues> extractFromModelValues(const std::list<Training*>* trainings) const;

public:
    explicit Controller(QObject *parent = nullptr);
    void setView(chartViewer* v);
    void setModel(Model* m);
    bool startView();
    ~Controller();

public slots:
    void add();
    void set();
    void remove();
    void newPlan();
    void save();
    void saveAs() const;
    void open();
    void first_response();
};

#endif // CONTROLLER_H
