#include "exercisecreator.h"

Exercise* exerciseCreator::createExercise(const std::string& name, const TimeSpan& duration, const TimeSpan& recovery) const{
    Exercise* aux = new Exercise(name, duration, recovery);
    return aux;
}
