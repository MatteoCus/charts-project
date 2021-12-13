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
    Endurance(QDateTime = QDateTime(), double = 0.0, double = 0.0, QTime = QTime());
    double getDistance() const;
    virtual QTime Pace() const = 0;
    QTime Duration() const override;
    virtual ~Endurance() = default;
};

#endif // ENDURANCE_H
