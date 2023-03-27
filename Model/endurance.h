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
    Endurance(const std::string &name, const DateTime& start, double distance, const TimeSpan& duration);
    double getDistance() const;
    TimeSpan getDuration() const override;
    void setDistance(double distance);
    void setDuration(const TimeSpan& duration);
    virtual ~Endurance() = default;
};

#endif // ENDURANCE_H
