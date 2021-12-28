#include "rugby.h"

Rugby::Rugby(double mass)
    :Repetition(mass){}

double Rugby::Intensity() const {
    return (105 * (Duration()/totalRecovery()) / 4);
}

unsigned int Rugby::CaloriesBurned() const {
    return (1.85 * Intensity()/100 * getWeight() * (Duration().getTotalMinutes())/10);
}
Rugby* Rugby::clone() const { return new Rugby(*this);}
