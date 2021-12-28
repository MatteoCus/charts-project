#ifndef RUN_H
#define RUN_H

#include "endurance.h"

class Run : public Endurance
{
public:
    Run(double = minWeight, double = 0.0, const TimeSpan& = TimeSpan());
    TimeSpan Pace() const override;
    unsigned int CaloriesBurned() const override;
    Run* clone() const override;
};

#endif // RUN_H
