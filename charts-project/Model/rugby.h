#ifndef RUGBY_H
#define RUGBY_H

#include "repetition.h"

class Rugby : public Repetition
{
public:
    Rugby(double = minWeight);
    double Intensity() const override;
    unsigned int CaloriesBurned() const override;
    Rugby* clone() const override;
};

#endif // RUGBY_H
