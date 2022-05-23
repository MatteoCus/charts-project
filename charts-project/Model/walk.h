#ifndef WALK_H
#define WALK_H

#include "endurance.h"

class Walk : public Endurance
{
public:
    Walk() = default;
    Walk(const std::string &name, const DateTime& start, double distance, const TimeSpan& duration);
    unsigned int CaloriesBurned() const override;
    Walk* clone() const override;
};

#endif // WALK_H
