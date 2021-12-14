#ifndef ENDURANCE_H
#define ENDURANCE_H

#include <QDateTime>
#include "training.h"

class Endurance : public Training
{
private:
    double distance;
    QTime duration;
public:
    Endurance() = default;
    Endurance(QDateTime, double, double, QTime);
    double getDistance() const;
    virtual QTime Pace() const = 0;
    QTime Duration() const override;
    virtual ~Endurance() = default;
};

#endif // ENDURANCE_H
