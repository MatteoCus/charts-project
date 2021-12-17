#ifndef TRAINING_H
#define TRAINING_H

#include <QDateTime>
#include "clonable.h"

class Training : public Clonable
{
private:
    QDateTime start;
    double weight;
protected:
    static const double minWeight;
public:
    Training(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime(0,0)), double = minWeight);
    virtual QTime Duration() const =0;
    virtual unsigned short int CaloriesBurned() const =0;
    QDateTime end() const;
    QDateTime getStart() const;
    double getWeight() const;
    virtual ~Training() = default;
};

#endif // TRAINING_H
