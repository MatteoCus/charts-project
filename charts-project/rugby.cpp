#include "rugby.h"

Rugby::Rugby(const QDateTime& begin, double mass)
    :Repetition(begin, mass){}

unsigned int Rugby::Intensity() const {
    return (105 * (totalRecovery().msecsSinceStartOfDay()/(getExercisesNumber() * pausePerExercise)));
}

unsigned int Rugby::CaloriesBurned() const {
    return (1.30 * getWeight() * (Duration().msecsSinceStartOfDay()/(msecInSec * secInMinute)));
}
Rugby* Rugby::clone() const { return new Rugby(*this);}
