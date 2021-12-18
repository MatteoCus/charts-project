#ifndef RUN_H
#define RUN_H

#include "endurance.h"

class Run : public Endurance
{
public:
    Run(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime (0,0)),
        double = minWeight, double = 0.0, const QTime& = QTime(0,0));
    QTime Pace() const override;
    unsigned int CaloriesBurned() const override;
    Run* clone() const override;
};

#endif // RUN_H
