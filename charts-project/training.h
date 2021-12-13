#ifndef TRAINING_H
#define TRAINING_H
#include <QDateTime>

class Training
{
private:
    QDateTime start;
    double weight;
    static double weightLimit;
public:
    Training(QDateTime = QDateTime(), double =0.0);    //1, 2 parameters costructor
    virtual QTime Duration() const =0;
    virtual unsigned short int CaloriesBurned() const =0;
    QDateTime end() const;
    QDateTime getStart() const;
    double getWeight() const;
    virtual ~Training() = default;
};

#endif // TRAINING_H
