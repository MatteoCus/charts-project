#ifndef RUGBY_H
#define RUGBY_H

#include "repetition.h"

class Rugby : public Repetition
{
public:
    Rugby(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime(0,0)), double = minWeight);
    double Intensity() const override;
    unsigned int CaloriesBurned() const override;
    Rugby* clone() const override;
};

#endif // RUGBY_H
