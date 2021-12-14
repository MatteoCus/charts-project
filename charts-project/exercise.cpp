#include "exercise.h"

Exercise::Exercise(std::string exName, QTime exDuration, QTime exRecovery)
    : name(exName), duration(exDuration), recovery(exRecovery){}

std::string Exercise::getName() const {return name;}
QTime Exercise::getDuration() const {return duration;}
QTime Exercise::getRecoveryTime() const {return recovery;}
