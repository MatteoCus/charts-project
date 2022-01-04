#include "exercisecreator.h"

Exercise* exerciseCreator::createExercise(const std::string& name, const TimeSpan& duration, const TimeSpan& recovery) const{
    try {
        Exercise* aux = new Exercise(name, duration, recovery);
        return aux;
    }  catch (std::invalid_argument& e) {
        throw e;
    }
}
