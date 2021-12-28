#include "exercise.h"

Exercise::Exercise(const std::string& exName, const TimeSpan& exDuration, const TimeSpan& exRecovery)
    : name(exName), duration(exDuration),
      recovery(exRecovery){}

std::string Exercise::getName() const {return name;}

TimeSpan Exercise::getDuration() const {return duration;}

TimeSpan Exercise::getRecoveryTime() const {return recovery;}

void Exercise::setName(const std::string& exName){name = exName;}

void Exercise::setDuration(const TimeSpan& exDuration) {duration = exDuration;}

void Exercise::setRecovery(const TimeSpan& exRecovery) {recovery = exRecovery;}

//clone pattern to improve code extensibility
Exercise* Exercise::clone() const   {return new Exercise(*this);}
