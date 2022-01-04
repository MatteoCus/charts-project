#ifndef TRAININGCREATOR_H
#define TRAININGCREATOR_H

#include "cycling.h"
#include "DateTime/datetime.h"
#include "rugby.h"
#include "run.h"
#include "tennis.h"
#include "walk.h"
#include <stdexcept>
#include <string>

class trainingCreator {
public:
  Training *createTraining(const std::string &type, double weight,
                           const DateTime &start, double distance = 0.0,
                           TimeSpan duration = TimeSpan(),
                           const std::string &exName = "",
                           const TimeSpan &exDuration = TimeSpan(),
                           const TimeSpan &exRecovery = TimeSpan()) const;
};

#endif // TRAININGCREATOR_H
