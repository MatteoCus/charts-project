#include "repetition.h"

Repetition::Repetition(double weight, const DateTime &start)
    : Training(weight, start), exercises() {}

void Repetition::addExercise(Exercise *ex) { exercises.push_back(ex); }

void Repetition::insertExercise(unsigned int pos, Exercise *ex) {
  if (pos == exercises.size())
    exercises.push_back(ex);
  else if (pos > exercises.size())
    throw std::out_of_range("Invalid exercise's entry index");
  else
    exercises.insert(exercises.begin() + pos, ex);
}

void Repetition::removeExercise(unsigned int pos) {
  if (pos >= exercises.size())
    throw std::out_of_range("Invalid exercise's removal index");
  if (pos == exercises.size() - 1)
    exercises.pop_back();
  else
    exercises.erase(exercises.begin() + pos);
}

Exercise *Repetition::getExercise(unsigned int pos) const {
  if (pos >= exercises.size())
    throw std::out_of_range("Invalid index for requested-exercise");
  return exercises[pos];
}

std::vector<Exercise *> Repetition::getExercises() const { return exercises; }

void Repetition::setExercise(unsigned int pos, Exercise *ex) {
  if (pos >= exercises.size())
    throw std::out_of_range("Invalid exercise's modification index");
  exercises[pos]->setName(ex->getName()); // if name=="", nothing changed
  try {
    exercises[pos]->setDuration(ex->getDuration());
    exercises[pos]->setRecovery(ex->getRecoveryTime());
  } catch (std::invalid_argument &e) {
    throw e;
  }
}

unsigned int Repetition::getSize() const { return exercises.size(); }

TimeSpan Repetition::totalRecovery() const {
  TimeSpan recovery;
  for (auto it = exercises.begin(); it != exercises.end(); ++it)
    recovery = recovery + ((*it)->getRecoveryTime());
  return recovery;
}

bool Repetition::isEmpty() const { return exercises.empty(); }

TimeSpan Repetition::Duration() const {
  TimeSpan duration;
  for (auto it = exercises.begin(); it != exercises.end(); ++it)
    duration = duration + ((*it)->getDuration()) + ((*it)->getRecoveryTime());
  return duration;
}

std::vector<Exercise *> Repetition::copy(const Repetition &rep) {
  std::vector<Exercise *> aux;
  for (auto it = rep.exercises.begin(); it != rep.exercises.end(); ++it)
    aux.push_back((*it)->clone()); // clone pattern su gerarchia di Exercise
  return aux;
}

void Repetition::destroy(const Repetition &rep) {
  for (auto it = rep.exercises.begin(); it != rep.exercises.end(); ++it)
    delete (*it);
}

// rule of three
Repetition::Repetition(const Repetition &rep)
    : Training(rep), exercises(copy(rep)) {}

Repetition &Repetition::operator=(const Repetition &rep) {
  if (this != &rep) {
    Training::operator=(rep);
    destroy(*this);
    exercises = copy(rep);
  }
  return *this;
}

Repetition::~Repetition() { destroy(*this); }
