#ifndef TENNIS_H
#define TENNIS_H

#include "repetition.h"

class Tennis : public Repetition
{
private:
    static const double c1;
    static const unsigned int c2;
public:
    Tennis() = default;
    Tennis(const std::string &name, const DateTime& start);
    unsigned int CaloriesBurned() const override;
    double Intensity() const override;
    Tennis* clone() const override;
};

#endif // TENNIS_H
