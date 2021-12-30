#ifndef TRAINING_H
#define TRAINING_H

#include "timespan.h"
#include <stdexcept>

class Training
{
private:
    double weight;
protected:
    static const double minWeight;
public:
    Training(double = minWeight);
    virtual TimeSpan Duration() const =0;
    virtual unsigned int CaloriesBurned() const =0;
    double getWeight() const;
    void setWeight(double);
    virtual Training* clone() const = 0;
    virtual ~Training() = default;
};

#endif // TRAINING_H
