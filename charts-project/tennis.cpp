#include "tennis.h"

Tennis::Tennis(const QDateTime& begin, double mass)
    :Repetition(begin, mass){}

double Tennis::Intensity() const {
    return (100 * (Duration().msecsSinceStartOfDay()/4)/(totalRecovery().msecsSinceStartOfDay()+1));
}

unsigned int Tennis::CaloriesBurned() const {
    return (1.75 * Intensity()/100 * getWeight() * (Duration().msecsSinceStartOfDay()/(msecInSec * secInMinute))/10);
}
Tennis* Tennis::clone() const {return new Tennis(*this);}
