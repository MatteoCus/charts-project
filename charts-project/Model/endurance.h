#ifndef ENDURANCE_H
#define ENDURANCE_H

#include "training.h"

class Endurance : public Training
{
private:
    double distance;
    TimeSpan duration;
public:
    Endurance();
    Endurance(double weight, double distance, const TimeSpan& duration);
    double getDistance() const;
    virtual TimeSpan Pace() const = 0;         //calculate the pace of the training; it can be measured in min/km or min/10km
    TimeSpan Duration() const override;
    void setDistance(double distance);
    void setDuration(const TimeSpan& duration);
    virtual ~Endurance() = default;
};

#endif // ENDURANCE_H
