#ifndef TRAINING_H
#define TRAINING_H

#include <QDateTime>
#include "clonable.h"

class Training : public Clonable
{
private:
    QDateTime start;
    double weight;
    static double minWeight;
public:
    Training() = default;
    Training(QDateTime , double = minWeight);
    virtual QTime Duration() const =0;
    virtual unsigned short int CaloriesBurned() const =0;
    QDateTime end() const;
    QDateTime getStart() const;
    double getWeight() const;
    virtual ~Training() = default;
};

#endif // TRAINING_H
