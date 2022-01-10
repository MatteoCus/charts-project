#ifndef RUGBY_H
#define RUGBY_H

#include "repetition.h"

class Rugby : public Repetition
{
private:
    static const double c1;
    static const unsigned int c2;
public:
    Rugby() = default;
    Rugby(const std::string &name, const DateTime& start);
    unsigned int CaloriesBurned() const override;
    double Intensity() const override;
    Rugby* clone() const override;
};

#endif // RUGBY_H
