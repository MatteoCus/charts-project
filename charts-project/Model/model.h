#ifndef MODEL_H
#define MODEL_H

#include "action.h"
#include "exercisecreator.h"
#include "plan.h"
#include "training.h"
#include "trainingcreator.h"
#include <string>
#include <vector>

class Model {
private:
    Plan *plan;

public:
    Model();
    void addNewTraining(const std::string &type, const std::string &name,
                        const DateTime &start, double distance = 0.0,
                        const TimeSpan &duration = TimeSpan(),
                        const std::vector<std::string>* exName = nullptr,
                        const std::vector<TimeSpan>* exDuration = nullptr,
                        const std::vector<TimeSpan>* exRecovery = nullptr) const;

    void removeTraining(unsigned int pos) const;
    Training *getTraining(unsigned int pos) const;
    const std::list<Training *>* getTrainings() const;

    void setTraining(unsigned int pos, const std::string &name, const DateTime &start,
                     double distance = 0.0, const TimeSpan &duration = TimeSpan(),
                     unsigned int exPos = 0, action operation = nothing,
                     const std::vector<std::string>* exName = nullptr,
                     const std::vector<TimeSpan>* exDuration = nullptr,
                     const std::vector<TimeSpan>* exRecovery = nullptr) const;

    unsigned int getPlanSize() const;
    bool isEmpty() const;

    Model(const Model &model);
    Model &operator=(const Model &model);
    ~Model();
};

#endif // MODEL_H
