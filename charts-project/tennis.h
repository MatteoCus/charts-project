#ifndef TENNIS_H
#define TENNIS_H

#include "repetition.h"
class Tennis : public Repetition
{
public:
    Tennis(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime(0,0)), double = minWeight);
    double Intensity() const override;
    unsigned int CaloriesBurned() const override;
    Tennis* clone() const override;
};

#endif // TENNIS_H
