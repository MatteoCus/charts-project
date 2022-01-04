#ifndef WALK_H
#define WALK_H

#include "endurance.h"

class Walk : public Endurance
{
public:
    Walk() = default;
    Walk(double weight, const DateTime& start, double distance, const TimeSpan& duration); //to do
    TimeSpan Pace() const override;
    unsigned int CaloriesBurned() const override;
    Walk* clone() const override;
};

#endif // WALK_H
