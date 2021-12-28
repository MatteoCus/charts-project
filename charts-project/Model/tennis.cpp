#include "tennis.h"

Tennis::Tennis(double mass)
    :Repetition(mass){}

double Tennis::Intensity() const {
    return ((Duration())/(totalRecovery())/4 * 100);
}

unsigned int Tennis::CaloriesBurned() const {
    return (1.75 * Intensity()/100 * getWeight() * Duration().getTotalMinutes()/10);
}
Tennis* Tennis::clone() const {return new Tennis(*this);}
