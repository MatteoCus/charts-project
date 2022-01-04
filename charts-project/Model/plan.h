#ifndef PLAN_H
#define PLAN_H

#include "training.h"
#include "endurance.h"
#include "repetition.h"
#include "action.h"
#include "exercisecreator.h"
#include <string>
#include <list>

class Plan
{
private:
    std::list<Training* > trainings;
    static std::list<Training* > copy(const Plan& plan);
    static void destroy(const Plan& plan);
public:
    Plan() = default;
    void addTraining(Training* training);
    void insertTraining(Training* training, unsigned int pos);
    void removeTraining(unsigned int pos);
    Training* getTraining(unsigned int pos) const;
    std::list<Training*> getTrainings() const;
    unsigned int getSize() const;
    bool isEmpty() const;
    void setTraining(unsigned int pos, double weight, double distance = 0.0, const TimeSpan& duration= TimeSpan(),
                     unsigned int exPos= 0, action operation= nothing, const std::string& exName="",
                     const TimeSpan& exDuration= TimeSpan(), const TimeSpan& exRecovery = TimeSpan());

    Plan(const Plan& plan);
    Plan& operator=(const Plan& plan);
    ~Plan();
};

#endif // PLAN_H
