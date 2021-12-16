#include "repetition.h"


Repetition::Repetition(QDateTime begin, double mass, std::vector<Exercise*> ex)
    : Training(begin, mass), exercises(ex){}
void Repetition::addExercise(Exercise* ex){exercises.push_back(ex);}
/*
Un utente potrebbe non tenere a mente il numero di esercizi che ha già inserito,
per questo vale anche se inserisce un numero troppo alto (coi negativi invece non vale)
ELIMINARE QUESTO COMMENTO O FARNE UNO MIGLIORE
*/
void Repetition::insertExercise(Exercise* ex, unsigned int pos){
    if(pos >= exercises.size())
        exercises.push_back(ex);
    else
        exercises.insert(exercises.begin() + pos, ex);
}

Exercise* Repetition::removeExercise(unsigned int pos){
    if(pos >= exercises.size())
        throw std::out_of_range("Invalid exercise's removing index");
    Exercise* aux = nullptr;
    if(pos == exercises.size()-1)
    {
        aux = *(--exercises.end());
        exercises.pop_back();
    }
    else
        aux = *(exercises.erase(exercises.begin() + pos));
    return aux;
}
Exercise* Repetition::getExercise(unsigned int pos) const{
    if(pos >= exercises.size())
        throw std::out_of_range("Invalid index for requested-exercise");
    return exercises[pos];
}

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

/*
 preso un const Repetition&, ne copia il vector di Exercise*
 la clone() per le sottoclassi deve richiamare la copy(oggetto da copiare)
 in particolare , ogni classe avrà "clone() {return new Classe(copy(*this));}"
 clone serve per il clone pattern, cioè per poter copiare oggetti in
 modo polimorfo -> usato nel trainingCreator
*/

std::vector<Exercise* > Repetition::copy(const Repetition& rep){
    std::vector<Exercise* > aux;
    for(auto it = rep.exercises.begin() ; it != rep.exercises.end() ; ++it)
        aux.push_back((*it)->clone());  //clone pattern usato, utile se si dovesse estendere gerarchia di Exercise
    return aux;
}

//preso un vector di Exercise*, dealloca gli oggetti puntati uno ad uno
void Repetition::destroy(std::vector<Exercise* > exList){
    for(auto it = exList.begin() ; it!= exList.end() ; ++it)
        delete (*it);
}
//rule of three
Repetition::Repetition(const Repetition& repTraining)
    :Training(repTraining), exercises(copy(repTraining)){}

Repetition& Repetition::operator=(const Repetition& repTraining){
    if(this != &repTraining){
        Training::operator=(repTraining);
        destroy(exercises);
        exercises = copy(repTraining);
    }
    return *this;
}
Repetition::~Repetition(){ destroy(exercises); }
