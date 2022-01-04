#ifndef TRAININGCREATOR_H
#define TRAININGCREATOR_H

#include "exercisecreator.h"
#include "cycling.h"
#include "rugby.h"
#include "run.h"
#include "tennis.h"
#include "walk.h"
#include "DateTime/timespan.h"
#include <string>
#include <stdexcept>

class trainingCreator
{
public:
    Training* createTraining(const std::string& type, double weight, double distance= 0.0,
                             TimeSpan duration= TimeSpan(), const std::string& exName="",
                             TimeSpan exDuration =TimeSpan(), TimeSpan exRecovery = TimeSpan()) const;
};

#endif // TRAININGCREATOR_H
