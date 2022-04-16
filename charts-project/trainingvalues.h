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
    trainingValues(const QString& type, const QDateTime& start, const QString& name,double distance,
                   const QTime& duration,std::vector<QString> exName, std::vector<QTime> exDuration, std::vector<QTime> recovery, action exAct = nothing);
                   QString type;
                   QDateTime start;
                   QString name;
                   double distance;
                   QTime duration;
                   std::vector<QString> exName;
                   std::vector<QTime> exDuration;
                   std::vector<QTime> recovery;
                   action exAct;
};

#endif // TRAININGVALUES_H
