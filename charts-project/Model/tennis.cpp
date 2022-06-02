#include "tennis.h"

Tennis::Tennis(const std::string &name, const DateTime& start)
    :Repetition(name, start){}

const double Tennis::c1 = 1.05;
const unsigned int Tennis::c2 = 100;

unsigned int Tennis::CaloriesBurned() const {
    return (c1 * Intensity()/100 * avgWeight * getDuration().getTotalMinutes()/10);
}

double Tennis::Intensity() const {
    if(totalRecovery() != TimeSpan())
    {
        double res = c2 * (getDuration()/totalRecovery())/4;
        return (res < 100? res : 98.25);
    }
    else
        throw std::runtime_error("Trying to calculate intensity with a null recovery time (division by 0");
}

Tennis* Tennis::clone() const {return new Tennis(*this);}
