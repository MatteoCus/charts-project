#include "trainingvalues.h"

trainingValues::trainingValues(const QString& type, const QDateTime& start, const QString& name,double distance,
                               const QTime& duration,std::vector<QString> exName, std::vector<QTime> exDuration, std::vector<QTime> exRecovery)
    : type(type), start(start), name(name), distance(distance), duration(duration), exName(exName), exDuration(exDuration), exRecovery(exRecovery){}
