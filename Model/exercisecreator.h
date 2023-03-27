#ifndef EXERCISECREATOR_H
#define EXERCISECREATOR_H

#include "exercise.h"
#include "DateTime/timespan.h"
#include <string>

class exerciseCreator {
public:
  Exercise *createExercise(const std::string &name, const TimeSpan &duration,
                           const TimeSpan &recovery) const;
};

#endif // EXERCISECREATOR_H
