#include "rugby.h"

Rugby::Rugby(const std::string &name, const DateTime& start)
    :Repetition(name, start){}

const double Rugby::c1 = 1.15;
const unsigned int Rugby::c2 = 105;

unsigned int Rugby::CaloriesBurned() const {
    return (c1 * Intensity()/100 * getWeight() * (Duration().getTotalMinutes())/10);
}

double Rugby::Intensity() const {
    if(totalRecovery() != TimeSpan())
        return (c2 * (Duration()/totalRecovery())/4);
    throw std::runtime_error("Trying to calculate intensity with a null recovery time (division by 0");
}
Rugby* Rugby::clone() const { return new Rugby(*this);}
