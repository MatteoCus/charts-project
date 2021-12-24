#include "plan.h"

void Plan::addTraining(Training* tr){ trainings.push_back(tr);
                                    }
void Plan::insertTraining(Training* tr, unsigned int pos){
    if(pos == trainings.size())
        trainings.push_back(tr);
    else if(pos > trainings.size())
        throw std::out_of_range("Invalid training's entry index");
    else
    {
        auto it = trainings.begin();
        std::advance(it, pos);
        trainings.insert(it, tr);
    }
}
Training* Plan::removeTraining(unsigned int pos){
    if(pos >= trainings.size())
        throw std::out_of_range("Invalid training's removal index");
    Training* aux = nullptr;
    if(pos == trainings.size()-1)
    {
        aux = *(--trainings.end());
        trainings.pop_back();
    }
    else if(pos == 0)
    {
        aux = *(trainings.begin());
        trainings.pop_front();
    }
    else
    {
        auto it = trainings.begin();
        std::advance(it, pos);
        aux = *it;
        trainings.erase(it);
    }
    return aux;
}
Training* Plan::getTraining(unsigned int pos) const{
    if(pos >= trainings.size())
        throw std::out_of_range("Invalid index for requested-training");
    auto it = trainings.begin();
    std::advance(it, pos);
    return *it;
}
//void Plan::setTraining(unsigned int, const string& ="", const QTime& = QTime(), const QTime& = QTime());
unsigned int Plan::getSize() const  { return trainings.size(); }

bool Plan::isEmpty() const  { return trainings.empty(); }

QTime Plan::getTotalDuration() const{                                               //creare classe orario e data-ora
    QTime duration = QTime(0,0);
    for(auto it = trainings.begin(); it != trainings.end(); ++it)
        duration = duration.addMSecs((*it)->Duration().msecsSinceStartOfDay());
    return duration;
}

unsigned int Plan::getTotalCaloriesBurned() const{
    unsigned int calories = 0;
    for(auto it = trainings.begin(); it != trainings.end(); ++it)
        calories += (*it)->CaloriesBurned();
    return calories;
}

std::list<Training* > Plan::copy(const Plan& plan){
    std::list<Training* > aux;
    for(auto it = plan.trainings.begin() ; it != plan.trainings.end() ; ++it)
        aux.push_back((*it)->clone());  //clone pattern su gerarchia di Training
    return aux;
}

//preso const Plan&, dealloca gli oggetti della list uno ad uno
void Plan::destroy(const Plan& plan){
    for(auto it = plan.trainings.begin() ; it!= plan.trainings.end() ; ++it)
        delete (*it);
}

Plan::Plan(const Plan& plan)
    : trainings(copy(plan)){}

Plan& Plan::operator=(const Plan& plan){
    if(this != &plan){
        destroy(*this);
        trainings = copy(plan);
    }
    return *this;
}

Plan::~Plan()   { destroy(*this); }