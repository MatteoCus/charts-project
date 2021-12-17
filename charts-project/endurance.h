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
    Endurance(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime (0,0)),
              double = minWeight, double = 0.0, const QTime& = QTime(0,0));
    double getDistance() const;
    virtual QTime Pace() const = 0;
    QTime Duration() const override;
    virtual ~Endurance() = default;
};

#endif // ENDURANCE_H
