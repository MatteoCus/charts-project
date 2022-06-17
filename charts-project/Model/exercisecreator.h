#ifndef EXERCISECREATOR_H
#define EXERCISECREATOR_H

#include "exercise.h"
#include "DateTime/timespan.h"
#include <string>

class exerciseCreator {
public:
    static Exercise *createExercise(const std::string &name, const TimeSpan &duration,
                             const TimeSpan &recovery);
};

#endif // EXERCISECREATOR_H
