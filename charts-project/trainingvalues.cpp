#include "trainingvalues.h"

trainingValues::trainingValues(QString type, QDateTime start, QString name, double distance, QTime duration, QString exName, QTime exDuration, QTime recovery)
    : type(type), start(start), name(name), distance(distance), duration(duration), exName(exName), exDuration(exDuration), recovery(recovery){}
