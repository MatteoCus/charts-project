#include "training.h"

Training::Training()
    : name("Generic training"), start(){}

Training::Training(const std::string &trName, const DateTime& start)
    : name(trName != ""? trName : throw std::invalid_argument("Tentativo di creazione di un allenamento usando un nome nullo!")),
      start(start){}

const double Training::avgWeight = 75;

std::string Training::getName() const {return name;}

DateTime Training::getStart() const {return start;}

DateTime Training::getEnd() const {return start + getDuration();}

void Training::setName(const std::string &newName){
    name = newName != "" ? newName : throw std::invalid_argument("Tentativo di modifica di un allenamento usando un nome nullo");
}

void Training::setStart(const DateTime& newStart) {
    start.setDateTime(newStart.getDate(), newStart.getTime());
}
