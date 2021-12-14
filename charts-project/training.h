#ifndef TRAINING_H
#define TRAINING_H

#include <QDateTime>

class Training
{
private:
    QDateTime start;
    double weight;
    static double minWeight;
public:
    Training(QDateTime = QDateTime(QDate(2000,01,01)), double = minWeight);
    virtual QTime Duration() const =0;
    virtual unsigned short int CaloriesBurned() const =0;
    QDateTime end() const;
    QDateTime getStart() const;
    double getWeight() const;
    virtual ~Training() = default;
};

#endif // TRAINING_H
