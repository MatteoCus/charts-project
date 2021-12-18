#include "exercise.h"

Exercise::Exercise(const std::string& exName, const QTime& exDuration, const QTime& exRecovery)
    : name(exName), duration(exDuration.isValid()? exDuration : throw std::invalid_argument("Invalid value of duration inserted!")),
      recovery(exRecovery.isValid()? exRecovery : throw std::invalid_argument("Invalid value of recovery inserted!")){}

std::string Exercise::getName() const {return name;}
QTime Exercise::getDuration() const {return duration;}
QTime Exercise::getRecoveryTime() const {return recovery;}
/*
clone pattern per migliorare estensibilità codice, qualora
si volesse far diventare virtuale la classe Exercise
proseguendo con derivazioni nella sua gerarchia
*/
void Exercise::setName(const std::string& exName){name = exName;}
void Exercise::setDuration(const QTime& exDuration){
    duration = (exDuration.isValid()? exDuration : throw std::invalid_argument("Invalid value of duration inserted!"));
}
void Exercise::setRecovery(const QTime& exRecovery){
    recovery = (exRecovery.isValid()? exRecovery : throw std::invalid_argument("Invalid value of recovery inserted!"));
}
Exercise* Exercise::clone() const   {return new Exercise(*this);}
