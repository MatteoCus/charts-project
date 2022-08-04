#include "exercisecreator.h"

Exercise* exerciseCreator::createExercise(const std::string& name, const TimeSpan& duration, const TimeSpan& recovery){
    return new Exercise(name, duration, recovery);
}
