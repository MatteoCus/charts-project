#ifndef REPETITION_H
#define REPETITION_H

#include <vector>
#include <string>
#include <QTime>
#include "training.h"
#include "exercise.h"

class Repetition : public Training
{
private:
    std::vector<Exercise* > exercises;
    static std::vector<Exercise* > copy(const Repetition&);
    static void destroy(const Repetition& );
public:
    Repetition(const QDateTime& = QDateTime(QDate(2000, 1, 1), QTime(0,0)), double = minWeight);
    void addExercise(Exercise* );
    void insertExercise(Exercise* , unsigned int );
    Exercise* removeExercise(unsigned int);
    Exercise* getExercise(unsigned int) const;
    unsigned int getExercisesNumber() const;
    QTime totalRecovery() const;
    bool isEmpty() const;
    QTime Duration() const override;
    virtual double Intensity() const=0;             //calculate the intensity of a specific training (value in % format)

    Repetition(const Repetition&);
    Repetition& operator=(const Repetition&);
    virtual ~Repetition();
};

#endif // REPETITION_H
