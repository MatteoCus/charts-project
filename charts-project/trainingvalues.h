#ifndef TRAININGVALUES_H
#define TRAININGVALUES_H

#include <QString>
#include <QTime>
#include <QDateTime>
#include <vector>
#include "action.h"

class trainingValues
{
public:
    QString type;
    QDateTime start;
    QString name;
    double distance;
    QTime duration;
    std::vector<QString> exName;
    std::vector<QTime> exDuration;
    std::vector<QTime> exRecovery;

    trainingValues(const QString& type, const QDateTime& start, const QString& name,double distance,
                   const QTime& duration,std::vector<QString> exName, std::vector<QTime> exDuration,
                   std::vector<QTime> exRecovery);
};

#endif // TRAININGVALUES_H
