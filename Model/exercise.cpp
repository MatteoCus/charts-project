#include "exercise.h"

Exercise::Exercise()
    : name(""), duration(), recovery(){}

Exercise::Exercise(const std::string& exName, const TimeSpan& exDuration, const TimeSpan& exRecovery)
    : name(exName != ""? exName : throw std::invalid_argument("Nome dell'esercizio non valido!")),
      duration(!exDuration.isNull()? exDuration : throw std::invalid_argument("Invalid value of training duration inserted")),
      recovery(!exRecovery.isNull()? exRecovery : throw std::invalid_argument("Invalid value of training duration inserted")){}

std::string Exercise::getName() const {return name;}

TimeSpan Exercise::getDuration() const {return duration;}

TimeSpan Exercise::getRecoveryTime() const {return recovery;}

void Exercise::setName(const std::string& exName){
    name = exName != ""? exName : throw std::invalid_argument("Nome dell'esercizio non valido!");
}

void Exercise::setDuration(const TimeSpan& exDuration) {
    duration = (!exDuration.isNull()? exDuration : throw std::invalid_argument("Invalid value of training duration inserted"));
}

void Exercise::setRecovery(const TimeSpan& exRecovery) {
    recovery = (!exRecovery.isNull()? exRecovery : throw std::invalid_argument("Invalid value of training duration inserted"));
}

Exercise* Exercise::clone() const   {return new Exercise(*this);}
