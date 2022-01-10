#ifndef CYCLING_H
#define CYCLING_H

#include "endurance.h"

class Cycling : public Endurance
{
private:
    static const unsigned int MET;      //parameter to calculate calories burned (here used as a constant, with default value)
    static const double c2;             //constant to calculate calories burned
public:
    Cycling() = default;
    Cycling(const std::string &name, const DateTime& start, double distance, const TimeSpan& duration);
    TimeSpan Pace() const override;
    unsigned int CaloriesBurned() const override;
    Cycling* clone() const override;
};

#endif // CYCLING_H
