#include "repetition.h"

Repetition::Repetition(const std::string &name, const DateTime &start)
    : Training(name, start), exercises() {}

void Repetition::addExercise(Exercise *ex) { exercises.push_back(ex); }

void Repetition::insertExercise(unsigned int pos, Exercise *ex) {
    if (pos == exercises.size())
        exercises.push_back(ex);
    else if (pos > exercises.size())
        throw std::out_of_range("Tentativo di inserimento di un esercizio in una posizione non esistente!");
    else
        exercises.insert(exercises.begin() + pos, ex);
}

void Repetition::removeExercise(unsigned int pos) {
    if (pos >= exercises.size())
        throw std::out_of_range("Tentativo di rimozione di un esercizio da una posizione non esistente!");
    if (pos == exercises.size() - 1)
        exercises.pop_back();
    else
        exercises.erase(exercises.begin() + pos);
}

Exercise *Repetition::getExercise(unsigned int pos) const {
    if (pos >= exercises.size())
        throw std::out_of_range("Richiesta di un esercizio in una posizione non esistente!");
    return exercises[pos];
}

std::vector<Exercise *> Repetition::getExercises() const { return exercises; }

void Repetition::setExercise(unsigned int pos, Exercise *ex) {
    if (pos >= exercises.size())
        throw std::out_of_range("Tentativo di modifica di un esercizio in una posizione non esistente!");
    exercises[pos]->setName(ex->getName());
    exercises[pos]->setDuration(ex->getDuration());
    exercises[pos]->setRecovery(ex->getRecoveryTime());
}

unsigned int Repetition::getSize() const { return exercises.size(); }

TimeSpan Repetition::totalRecovery() const {
    TimeSpan recovery;
    for (auto it = exercises.begin(); it != exercises.end(); ++it)
        recovery = recovery + ((*it)->getRecoveryTime());
    return recovery;
}

bool Repetition::isEmpty() const { return exercises.empty(); }

TimeSpan Repetition::getDuration() const {
    TimeSpan duration;
    for (auto it = exercises.begin(); it != exercises.end(); ++it)
        duration = duration + ((*it)->getDuration()) + ((*it)->getRecoveryTime());
    return duration;
}

std::vector<Exercise *> Repetition::copy(const Repetition &rep) {
    std::vector<Exercise *> aux;
    for (auto it = rep.exercises.begin(); it != rep.exercises.end(); ++it)
        aux.push_back((*it)->clone());
    return aux;
}

void Repetition::destroy(const Repetition &rep) {
    for (auto it = rep.exercises.begin(); it != rep.exercises.end(); ++it)
        delete (*it);
}

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
