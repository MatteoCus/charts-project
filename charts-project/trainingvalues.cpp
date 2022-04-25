#include "trainingvalues.h"

trainingValues::trainingValues(const QString& type, const QDateTime& start, const QString& name,double distance,
                               const QTime& duration,std::vector<QString> exName, std::vector<QTime> exDuration, std::vector<QTime> recovery, action act, int pos, action exAct, int exPos)
    : type(type), start(start), name(name), distance(distance), duration(duration), exName(exName), exDuration(exDuration), recovery(recovery), act(act), pos(pos), exAct(exAct), exPos(exPos){}
