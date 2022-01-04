#include "training.h"

Training::Training()
    : weight(minWeight), start(){}

Training::Training(double mass, const DateTime& start)
    : weight(mass >= minWeight? mass : throw std::invalid_argument("Invalid value of weight inserted!")),
        start(start){}

const double Training::minWeight = 20;

double Training::getWeight() const  {return weight;}

DateTime Training::getStart() const {return start;}

DateTime Training::getEnd() const {return start + Duration();}

void Training::setWeight(double mass){
    weight = (mass >= minWeight? mass : throw std::invalid_argument("Invalid value of weight inserted!"));
}

void Training::setStart(const DateTime& dateTime) {
    try {
          start.setDateTime(dateTime);
    }
    catch(DateException& ex){
        throw ex;
    }
    catch (std::invalid_argument& e) {
        throw e;
    }
}
