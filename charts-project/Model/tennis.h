#ifndef TENNIS_H
#define TENNIS_H

#include "repetition.h"

class Tennis : public Repetition
{
public:
    Tennis() = default;
    Tennis(double weight, const DateTime& start);
    double Intensity() const override;
    unsigned int CaloriesBurned() const override;
    Tennis* clone() const override;
};

#endif // TENNIS_H
