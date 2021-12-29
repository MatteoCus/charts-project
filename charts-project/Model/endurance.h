#ifndef ENDURANCE_H
#define ENDURANCE_H

#include "training.h"

class Endurance : public Training
{
private:
    double distance;
    TimeSpan duration;
public:
    Endurance(double, double, const TimeSpan&);
    double getDistance() const;
    virtual TimeSpan Pace() const = 0;         //calculate the pace of the training; it can be measured in min/km or min/10km
    TimeSpan Duration() const override;
    void setDistance(double);
    void setDuration(const TimeSpan&);
    virtual ~Endurance() = default;
};

#endif // ENDURANCE_H
