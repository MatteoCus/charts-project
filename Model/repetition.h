#ifndef REPETITION_H
#define REPETITION_H

#include "exercise.h"
#include "training.h"
#include <string>
#include <vector>

using std::string;

class Repetition : public Training {
private:
  std::vector<Exercise *> exercises;
  static std::vector<Exercise *> copy(const Repetition &repTraining);
  static void destroy(const Repetition &repTraining);
  bool isEmpty() const;

public:
  Repetition() = default;
  Repetition(const std::string &name, const DateTime &start);
  void addExercise(Exercise *exercise);
  void insertExercise(unsigned int position, Exercise *exercise);
  void removeExercise(unsigned int position);
  Exercise *getExercise(unsigned int position) const;
  std::vector<Exercise *> getExercises() const;
  void setExercise(unsigned int position, Exercise *ex);
  unsigned int getSize() const;
  TimeSpan totalRecovery() const;
  TimeSpan getDuration() const override;
  virtual double Intensity() const = 0; // calculate the intensity of a specific
                                        // training (value in % format)

  Repetition(const Repetition &repTraining);
  Repetition &operator=(const Repetition &repTraining);
  virtual ~Repetition();
};

#endif // REPETITION_H
