#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "../trainingvalues.h"
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

public:
    explicit Controller(QObject *parent = nullptr);
    void setView(chartViewer* v);
    void setModel(Model* m);
    void extractValues(trainingValues values, DateTime& start, TimeSpan& duration,std::vector<std::string>& exName,
                std::vector<Time>& exDuration,std::vector<Time>& exRecovery) const;
public slots:
    void add() const;
    void set() const;
    void remove() const;
};

#endif // CONTROLLER_H
