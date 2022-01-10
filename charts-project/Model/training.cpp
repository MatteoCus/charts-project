#include "training.h"

Training::Training()
    : name("Generic training"), start(){}

Training::Training(const std::string &trName, const DateTime& start)
    : name(trName != ""? trName : throw std::invalid_argument("Invalid training name inserted!")),
        start(start){}

const double Training::avgWeight = 75;

double Training::getWeight() const  {return avgWeight;}

DateTime Training::getStart() const {return start;}

DateTime Training::getEnd() const {return start + Duration();}

void Training::setName(const std::string &trName){
    name = trName != "" ? trName : throw std::invalid_argument("Invalid training name inserted!");
}

void Training::setStart(const DateTime& dateTime) {
    try {
          start.setDateTime(dateTime.getDate(), dateTime.getTime());
    }
    catch(DateException& ex){
        throw ex;
    }
    catch (std::invalid_argument& e) {
        throw e;
    }
}
