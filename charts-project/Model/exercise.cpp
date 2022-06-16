#include "exercise.h"

Exercise::Exercise()
    : name(""), duration(), recovery(){}

Exercise::Exercise(const std::string& exName, const TimeSpan& exDuration, const TimeSpan& exRecovery)
    : name(exName != ""? exName : throw std::invalid_argument("Tentativo di creazione di un esercizio usando un nome nullo!")),
      duration(!exDuration.isNull()? exDuration : throw std::invalid_argument("Tentativo di creazione di un esercizio usando una durata nulla!")),
      recovery(!exRecovery.isNull()? exRecovery : throw std::invalid_argument("Tentativo di creazione di un esercizio usando un tempo di recupero nullo!")){}

std::string Exercise::getName() const {return name;}

TimeSpan Exercise::getDuration() const {return duration;}

TimeSpan Exercise::getRecoveryTime() const {return recovery;}

void Exercise::setName(const std::string& exName){
    name = exName != ""? exName : throw std::invalid_argument("Tentativo di modifica di un esercizio usando un nome nullo!");
}

void Exercise::setDuration(const TimeSpan& exDuration) {
    duration = (!exDuration.isNull()? exDuration : throw std::invalid_argument("Tentativo di modifica di un esercizio usando una durata nulla!"));
}

void Exercise::setRecovery(const TimeSpan& exRecovery) {
    recovery = (!exRecovery.isNull()? exRecovery : throw std::invalid_argument("Tentativo di modifica di un esercizio usando un tempo di recupero nullo!"));
}

Exercise* Exercise::clone() const   {return new Exercise(*this);}
