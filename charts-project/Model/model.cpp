#include "model.h"

Model::Model() : plan(new Plan()) {}

void Model::addNewTraining(const std::string &type, const std::string &name,
                           const DateTime &start, double distance,
                           const TimeSpan &duration, const std::vector<std::string>* exName,
                           const std::vector<TimeSpan>* exDuration,
                           const std::vector<TimeSpan>* exRecovery) const {

    plan->insertTraining(trainingCreator::createTraining(type, name, start, distance, duration, exName,exDuration, exRecovery));
}

void Model::removeTraining(unsigned int pos) const {
    plan->removeTraining(pos);
}

Training *Model::getTraining(unsigned int pos) const {
    return plan->getTraining(pos);
}

const std::list<Training *>* Model::getTrainings() const {
    return plan->getTrainings();
}

void Model::setTraining(unsigned int pos, const std::string &name, const DateTime &start,
                        double distance, const TimeSpan &duration,
                        unsigned int exPos, action operation,
                        const std::vector<std::string>* exName,
                        const std::vector<TimeSpan>*exDuration,
                        const std::vector<TimeSpan>* exRecovery) const {
    plan->setTraining(pos, name, start, distance, duration, exPos, operation,
                      exName, exDuration, exRecovery);
}

unsigned int Model::getPlanSize() const { return plan->getSize(); }

bool Model::isEmpty() const { return plan->isEmpty(); }

void Model::removeTrainings() const
{
    plan->clear();
}

Model::Model(const Model &model) : plan(new Plan(*model.plan)) {}

Model &Model::operator=(const Model &model) {
    if (this != &model) {
        delete plan;
        plan = new Plan(*model.plan);
    }
    return *this;
}

Model::~Model() { delete plan; }
