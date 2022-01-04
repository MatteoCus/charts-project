#include "model.h"

Model::Model()
    : plan(new Plan()){}

Plan* Model::copy(const Model& model){ return new Plan(*model.plan); }

void Model::destroy(const Model& model){ delete model.plan;}

void Model::addNewTraining(unsigned int pos, const std::string& type, double weight, double distance,
                           const TimeSpan& duration, const std::string& exName,
                           const TimeSpan& exDuration, const TimeSpan& exRecovery) const{
    Training* tr = nullptr;
    trainingCreator* creator = nullptr;
    try {
        creator = new trainingCreator();
        tr = creator->createTraining(type, weight, distance, duration, exName, exDuration, exRecovery);
        if(pos >= plan->getSize())
            plan->addTraining(tr);
        else
            plan->insertTraining(tr, pos);
        delete creator;
    }
    catch (std::invalid_argument& e) {
        throw e;
    }
    catch (std::out_of_range& ex) {
        throw ex;
    }
}

void Model::removeTraining(unsigned int pos) const {
    try {
        plan->removeTraining(pos);
    }  catch (std::out_of_range& e) {
        throw e;
    }
}

Training* Model::getTraining(unsigned int pos) const {
    try {
        return plan->getTraining(pos);
    }  catch (std::out_of_range& e) {
        throw e;
    }
}

std::list<Training*> Model::getTrainings() const { return plan->getTrainings(); }

void Model::setTraining(unsigned int pos,  double weight, double distance, const TimeSpan& duration,
                        unsigned int exPos, action operation, const std::string& exName,
                        const TimeSpan& exDuration, const TimeSpan& exRecovery) const{
    try {
        plan->setTraining(pos, weight, distance, duration, exPos, operation, exName, exDuration, exRecovery);
    }
    catch (std::invalid_argument& e) {
        throw e;
    }
    catch (std::out_of_range& ex) {
        throw ex;
    }
}

unsigned int Model::getPlanSize() const { return plan->getSize(); }

bool Model::isEmpty() const { return plan->isEmpty(); }

//rule of three
Model::Model(const Model& model)
    : plan(copy(model)){}

Model& Model::operator=(const Model& model){
    if(this != &model)
    {
        destroy(*this);
        plan = copy(model);
    }
    return *this;
}

Model::~Model(){ destroy(*this);}
