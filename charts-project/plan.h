#ifndef PLAN_H
#define PLAN_H

#include "training.h"
#include <string>
#include <list>

using std::string;

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
    //void setTraining(unsigned int, const string& ="", const QTime& = QTime(), const QTime& = QTime());
    unsigned int getSize() const;
    bool isEmpty() const;
    QTime getTotalDuration() const;
    unsigned int getTotalCaloriesBurned() const;

    Plan(const Plan&);
    Plan& operator=(const Plan&);
    ~Plan();
};

#endif // PLAN_H
