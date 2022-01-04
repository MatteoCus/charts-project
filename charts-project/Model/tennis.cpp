#include "tennis.h"

Tennis::Tennis(double mass, const DateTime& start)
    :Repetition(mass, start){}

double Tennis::Intensity() const {
    if(totalRecovery() != TimeSpan())
        return (100 * (Duration()/totalRecovery())/4);
    throw std::runtime_error("Trying to calculate intensity with a null recovery time (division by 0");
}

unsigned int Tennis::CaloriesBurned() const {
    return (1.75 * Intensity()/100 * getWeight() * Duration().getTotalMinutes()/10);
}
Tennis* Tennis::clone() const {return new Tennis(*this);}
