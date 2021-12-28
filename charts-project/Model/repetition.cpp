#include "repetition.h"

Repetition::Repetition(double mass)
    : Training(mass), exercises(){}

void Repetition::addExercise(Exercise* ex){exercises.push_back(ex);}

void Repetition::insertExercise(Exercise* ex, unsigned int pos){
    if(pos == exercises.size())
        exercises.push_back(ex);
    else if(pos > exercises.size())
        throw std::out_of_range("Invalid exercise's entry index");
    else exercises.insert(exercises.begin() + pos, ex);
}

Exercise* Repetition::removeExercise(unsigned int pos){
    if(pos >= exercises.size())
        throw std::out_of_range("Invalid exercise's removal index");
    Exercise* aux = nullptr;
    if(pos == exercises.size()-1)
    {
        aux = *(--exercises.end());
        exercises.pop_back();
    }
    else
    {
        aux = *(exercises.begin() + pos);
        exercises.erase(exercises.begin()+pos);
    }
    return aux;
}

Exercise* Repetition::getExercise(unsigned int pos) const{
    if(pos >= exercises.size())
        throw std::out_of_range("Invalid index for requested-exercise");
    return exercises[pos];
}
void Repetition::setExercise(unsigned int pos, const string& name, const TimeSpan& duration, const TimeSpan& recovery){
    if(pos >= exercises.size())
        throw std::out_of_range("Invalid exercise's modification index");
    if (name!="")
        exercises[pos]->setName(name);
    exercises[pos]->setDuration(duration);
    exercises[pos]->setRecovery(recovery);
}

unsigned int Repetition::getSize() const { return exercises.size(); }

TimeSpan Repetition::totalRecovery() const{
    TimeSpan recovery;
    for(auto it = exercises.begin(); it != exercises.end(); ++it)
        recovery = recovery + ((*it)->getRecoveryTime());
    return recovery;
}

bool Repetition::isEmpty() const { return exercises.empty(); }

TimeSpan Repetition::Duration() const {
    TimeSpan duration(0,0);
    for(auto it = exercises.begin(); it != exercises.end(); ++it)
        duration = duration + ((*it)->getDuration());
    return duration;
}

/*
 preso un const Repetition&, ne copia il vector (fatto di Exercise*);
 clone serve per il clone pattern, cioè per poter copiare oggetti in
 modo polimorfo -> usato in "Plan"
*/

std::vector<Exercise* > Repetition::copy(const Repetition& rep){
    std::vector<Exercise* > aux;
    for(auto it = rep.exercises.begin() ; it != rep.exercises.end() ; ++it)
        aux.push_back((*it)->clone());  //clone pattern su gerarchia di Exercise
    return aux;
}

//preso const Repetition&, dealloca gli oggetti del suo vector uno ad uno
void Repetition::destroy(const Repetition& rep){
    for(auto it = rep.exercises.begin() ; it!= rep.exercises.end() ; ++it)
        delete (*it);
}

//rule of three
Repetition::Repetition(const Repetition& rep)
    :Training(rep), exercises(copy(rep)){}

Repetition& Repetition::operator=(const Repetition& rep){
    if(this != &rep){
        Training::operator=(rep);
        destroy(*this);
        exercises = copy(rep);
    }
    return *this;
}

Repetition::~Repetition(){ destroy(*this); }
