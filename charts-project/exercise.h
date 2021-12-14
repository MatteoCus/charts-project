#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <QTime>

class Exercise
{
private:
    std::string name;
    QTime duration;
    QTime recovery;
public:
    Exercise(std::string ="", QTime = QTime(0,0), QTime = QTime(0,0));
    std::string getName() const;
    QTime getDuration() const;
    QTime getRecoveryTime() const;
};

#endif // EXERCISE_H
