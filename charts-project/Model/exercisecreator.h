#ifndef EXERCISECREATOR_H
#define EXERCISECREATOR_H

#include "exercise.h"
#include "timespan.h"
#include <string>

class exerciseCreator
{
public:
    Exercise* createExercise(const std::string&, const TimeSpan&, const TimeSpan&);
};

#endif // EXERCISECREATOR_H
