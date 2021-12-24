#ifndef TRAINING_H
#define TRAINING_H

#include <QDateTime>
#include <stdexcept>

class Training
{
private:
    QDateTime start;
    double weight;
protected:
    static const double minWeight;
    static const unsigned int msecInSec;
    static const unsigned int secInMinute;
public:
    Training(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime(0,0)), double = minWeight);
    virtual QTime Duration() const =0;
    virtual unsigned int CaloriesBurned() const =0;
    QDateTime end() const;
    QDateTime getStart() const;
    double getWeight() const;
    void setStart(const QDateTime&);
    void setWeight(double );
    virtual Training* clone() const = 0;
    virtual ~Training() = default;
};

#endif // TRAINING_H
