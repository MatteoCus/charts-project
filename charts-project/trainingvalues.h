#ifndef TRAININGVALUES_H
#define TRAININGVALUES_H

#include <QString>
#include <QTime>
#include <QDateTime>

class trainingValues
{
public:
    trainingValues(QString type, QDateTime start, QString name,double distance,
                   QTime duration, QString exName, QTime exDuration, QTime recovery);
                   QString type;
                   QDateTime start;
                   QString name;
                   double distance;
                   QTime duration;
                   QString exName;
                   QTime exDuration;
                   QTime recovery;
};

#endif // TRAININGVALUES_H
