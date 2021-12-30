#ifndef REPETITION_H
#define REPETITION_H

#include <vector>
#include <string>
#include "training.h"
#include "exercise.h"

using std::string;

class Repetition : public Training
{
private:
    std::vector<Exercise* > exercises;
    static std::vector<Exercise* > copy(const Repetition&);
    static void destroy(const Repetition& );
public:
    Repetition(double = minWeight);
    void addExercise(Exercise* );
    void insertExercise(Exercise* , unsigned int );
    Exercise* removeExercise(unsigned int);
    Exercise* getExercise(unsigned int) const;
    void setExercise(unsigned int, double, const string&, const TimeSpan& , const TimeSpan&);
    unsigned int getSize() const;
    TimeSpan totalRecovery() const;
    bool isEmpty() const;
    TimeSpan Duration() const override;
    virtual double Intensity() const=0;             //calculate the intensity of a specific training (value in % format)

    Repetition(const Repetition&);
    Repetition& operator=(const Repetition&);
    virtual ~Repetition();
};

#endif // REPETITION_H
