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
#include <vector>

class trainingCreator {
public:
    static Training *createTraining(const std::string &type, const std::string &name,
                             const DateTime &start, double distance = 0.0,
                             TimeSpan duration = TimeSpan(),
                             const std::vector<std::string>* exName = nullptr,
                             const std::vector<TimeSpan>* exDuration = nullptr,
                             const std::vector<TimeSpan>* exRecovery = nullptr);
};

#endif // TRAININGCREATOR_H
