#include "dialogvalues.h"

dialogValues::dialogValues(const QString &type, const QDateTime &start, const QString &name, double distance, const QTime &duration, std::vector<QString> exName, std::vector<QTime> exDuration, std::vector<QTime> exRecovery, int pos, action exAct, int exPos)
    : trainingValues(type,start,name,distance,duration,exName,exDuration,exRecovery), pos(pos), exAct(exAct), exPos(exPos){}
