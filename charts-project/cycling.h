#ifndef CYCLING_H
#define CYCLING_H

#include "endurance.h"

class Cycling : public Endurance
{
private:
    static const unsigned int MET;
    static const double c2; //constant to calculate calories burned
public:
    Cycling(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime (0,0)),
            double = minWeight, double = 0.0, const QTime& = QTime(0,0));
    QTime Pace() const override;
    unsigned int CaloriesBurned() const override;
    Cycling* clone() const override;
};

#endif // CYCLING_H
