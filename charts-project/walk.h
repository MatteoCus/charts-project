#ifndef WALK_H
#define WALK_H

#include "endurance.h"

class Walk : public Endurance
{
public:
    Walk(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime (0,0)),
         double = minWeight, double = 0.0, const QTime& = QTime(0,0));
    QTime Pace() const override;
    unsigned int CaloriesBurned() const override;
    Walk* clone() const override;
};

#endif // WALK_H
