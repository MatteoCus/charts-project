#include "tennis.h"

Tennis::Tennis(const QDateTime& begin, double mass)
    :Repetition(begin, mass){}

unsigned int Tennis::Intensity() const {
    return (100 * (totalRecovery().msecsSinceStartOfDay()/(getExercisesNumber() * pausePerExercise)));
}

unsigned int Tennis::CaloriesBurned() const {
    return (1.10 * getWeight() * (Duration().msecsSinceStartOfDay()/(msecInSec * secInMinute)));
}
Tennis* Tennis::clone() const { return new Tennis(*this);}
