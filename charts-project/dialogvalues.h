#ifndef DIALOGVALUES_H
#define DIALOGVALUES_H

#include "trainingvalues.h"

class dialogValues : public trainingValues
{
public:
    int pos;
    action exAct;
    int exPos;

    dialogValues(const QString& type, const QDateTime& start, const QString& name,double distance,
                 const QTime& duration,std::vector<QString> exName, std::vector<QTime> exDuration,
                 std::vector<QTime> exRecovery, int pos, action exAct, int exPos);
};

#endif // DIALOGVALUES_H
