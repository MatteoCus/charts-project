#ifndef REPETITION_H
#define REPETITION_H

#include <list>
#include <string>
#include <QTime>
#include "training.h"
#include "exercise.h"

class Repetition : public Training
{
private:
    std::list<Exercise* > exercises;
public:
    Repetition() = default;
    void addExercise(Exercise* );
    void insertExercise(Exercise* , unsigned int);
    void removeExercise(unsigned int);
    const std::list<Exercise* >& getExercises() const;
    unsigned int getExercisesNumber() const;
    QTime totalRecovery() const;
    bool isEmpty() const;
    QTime Duration() const override;

    virtual unsigned int Intensity() const=0;
    //rule of three
    Repetition(const Repetition&);
    Repetition& operator=(const Repetition&);
    virtual ~Repetition();
};

#endif // REPETITION_H
