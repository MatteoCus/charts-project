#include "exercise.h"

Exercise::Exercise(const std::string& exName, const TimeSpan& exDuration, const TimeSpan& exRecovery)
    : name(exName != ""? exName : throw std::invalid_argument("Invalid exercise name inserted")),
      duration(exDuration.isNull()? throw std::invalid_argument("Invalid (null) exercise's duration inserted") : exDuration),
      recovery(exRecovery.isNull()? throw std::invalid_argument("Invalid (null) exercise's recovery inserted") : exRecovery){}

std::string Exercise::getName() const {return name;}

TimeSpan Exercise::getDuration() const {return duration;}

TimeSpan Exercise::getRecoveryTime() const {return recovery;}

void Exercise::setName(const std::string& exName){
    if (exName != "")
        name = exName;
}

void Exercise::setDuration(const TimeSpan& exDuration) {
    if(!exDuration.isNull())
        duration = exDuration;
}

void Exercise::setRecovery(const TimeSpan& exRecovery) {
    if(!exRecovery.isNull())
        recovery = exRecovery;
}

//clone pattern to improve code extensibility
Exercise* Exercise::clone() const   {return new Exercise(*this);}
