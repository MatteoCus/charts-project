#include "exercise.h"

Exercise::Exercise(std::string exName, QTime exDuration, QTime exRecovery)
    : name(exName), duration(exDuration), recovery(exRecovery){}

std::string Exercise::getName() const {return name;}
QTime Exercise::getDuration() const {return duration;}
QTime Exercise::getRecoveryTime() const {return recovery;}
/*
clone pattern per migliorare estensibilità codice, qualora
si volesse far diventare virtuale la classe Exercise
proseguendo con derivazioni nella sua gerarchia
*/
Exercise* Exercise::clone() const   {return new Exercise(*this);}
