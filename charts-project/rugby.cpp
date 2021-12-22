#include "rugby.h"

Rugby::Rugby(const QDateTime& begin, double mass)
    :Repetition(begin, mass){}

double Rugby::Intensity() const {
    return (105 * (Duration().msecsSinceStartOfDay()/4)/(totalRecovery().msecsSinceStartOfDay()+1));
}

unsigned int Rugby::CaloriesBurned() const {
    return (1.85 * Intensity()/100 * getWeight() * (Duration().msecsSinceStartOfDay()/(msecInSec * secInMinute))/10);
}
Rugby* Rugby::clone() const { return new Rugby(*this);}
