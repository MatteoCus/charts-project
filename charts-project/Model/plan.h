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
    static std::list<Training* > copy(const Plan&);
    static void destroy(const Plan& );
public:
    Plan() = default;
    void addTraining(Training* );
    void insertTraining(Training* , unsigned int );
    Training* removeTraining(unsigned int);
    Training* getTraining(unsigned int) const;

    unsigned int getSize() const;
    bool isEmpty() const;
    void setTraining(unsigned int,  double, double = 0.0, const TimeSpan& = TimeSpan(), unsigned int = 0, action = nothing, const std::string& ="", const TimeSpan& = TimeSpan(),const TimeSpan& = TimeSpan());
    template<class T>
    std::list<T*> filter() const;

    Plan(const Plan&);
    Plan& operator=(const Plan&);
    ~Plan();
};

#endif // PLAN_H
