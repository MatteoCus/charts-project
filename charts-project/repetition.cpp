#include "repetition.h"

Repetition::Repetition(const QDateTime& begin, double mass)
    : Training(begin, mass), exercises(){}

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
void Repetition::setExercise(unsigned int pos, const string& name, const QTime& duration, const QTime& recovery){
    if(pos >= exercises.size())
        throw std::out_of_range("Invalid exercise's modification index");
    if (name!="")
        exercises[pos]->setName(name);
    if(!duration.isValid())
    {
        if(duration != QTime())
            throw std::invalid_argument("Invalid exercise's duration time inserted");
    }
    else
        exercises[pos]->setDuration(duration);
    if(!recovery.isValid())
    {
        if(recovery!= QTime())
            throw std::invalid_argument("Invalid exercise's recovery time inserted");
    }
    else
        exercises[pos]->setRecovery(recovery);
}

unsigned int Repetition::getSize() const { return exercises.size(); }

QTime Repetition::totalRecovery() const{
    QTime recovery(0,0);
    for(auto it = exercises.begin(); it != exercises.end(); ++it)
    {
        recovery = recovery.addMSecs((*it)->getRecoveryTime().msecsSinceStartOfDay());
        if(!(recovery.isValid()))
            throw std::runtime_error("Invalid recovery time value");
    }
    return recovery;
}

bool Repetition::isEmpty() const { return exercises.empty(); }

QTime Repetition::Duration() const {
    QTime duration(0,0);
    for(auto it = exercises.begin(); it != exercises.end(); ++it)
    {
        duration = duration.addMSecs((*it)->getDuration().msecsSinceStartOfDay());
        if(!(duration.isValid()))
            throw std::runtime_error("Invalid duration time value");
    }
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
