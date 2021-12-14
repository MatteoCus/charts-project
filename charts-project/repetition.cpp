#include "repetition.h"

void Repetition::addExercise(Exercise* ex){exercises.push_back(ex);}
/*
Un utente potrebbe non tenere a mente il numero di esercizi che ha già inserito,
per questo vale anche se inserisce un numero troppo alto (coi negativi invece non vale)
ELIMINARE QUESTO COMMENTO O FARNE UNO MIGLIORE
*/
void Repetition::insertExercise(Exercise* ex, unsigned int pos){
    if (pos < 0)
        throw std::out_of_range("Negative exercise's inserting index");
    if(!pos)
        exercises.push_front(ex);
    else if(pos >= exercises.size())
        exercises.push_back(ex);
    else{
        auto it = exercises.begin();
        advance(it, pos);
        exercises.insert(it, ex);
    }
}

void Repetition::removeExercise(unsigned int pos){
    if(pos < 0 || pos >= exercises.size())
        throw std::out_of_range("Invalid exercise's removing index");
    if(!pos)
        exercises.pop_front();
    if(pos == exercises.size()-1)
        exercises.pop_back();
    auto it = exercises.begin();
    advance(it, pos);
    exercises.erase(it);
}

const std::list<Exercise* >& Repetition::getExercises() const { return exercises; }

unsigned int Repetition::getExercisesNumber() const { return exercises.size(); }

QTime Repetition::totalRecovery() const{
    QTime recovery(0,0);
    for(auto it = exercises.begin(); it != exercises.end(); ++it)
    {    recovery = recovery.addMSecs((*it)->getRecoveryTime().msecsSinceStartOfDay());
        if(!recovery.isValid())
            throw std::runtime_error("Invalid recovery time value");
    }
    return recovery;
}
bool Repetition::isEmpty() const { return exercises.empty(); }

QTime Repetition::Duration() const {
    QTime duration(0,0);
    for(auto it = exercises.begin(); it != exercises.end(); ++it)
    {    duration = duration.addMSecs((*it)->getDuration().msecsSinceStartOfDay());
        if(!duration.isValid())
            throw std::runtime_error("Invalid duration time value");
    }
    return duration;
}

//rule of three
Repetition::Repetition(const Repetition& repTraining)
    :exercises(repTraining.getExercises()){}
Repetition& Repetition::operator=(const Repetition& repTraining){
    if(this != &repTraining){
        exercises = repTraining.getExercises();
    }
    return *this;
}
Repetition::~Repetition(){
    for(auto it = exercises.begin() ; it!= exercises.end() ; ++it)
        delete *(it);
}
