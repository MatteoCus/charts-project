#include "model.h"

Model::Model() : plan(new Plan()) {}

void Model::addNewTraining(const std::string &type, const std::string &name,
                           const DateTime &start, double distance,
                           const TimeSpan &duration, const std::string &exName,
                           const TimeSpan &exDuration,
                           const TimeSpan &exRecovery) const {
    trainingCreator *creator = new trainingCreator();
    Training *tr =
        creator->createTraining(type, name, start, distance, duration, exName,
                                exDuration, exRecovery);
    plan->insertTraining(tr);
    delete creator;
}

void Model::removeTraining(unsigned int pos) const {
    plan->removeTraining(pos);
}

Training *Model::getTraining(unsigned int pos) const {
    return plan->getTraining(pos);
}

const std::list<Training *>& Model::getTrainings() const {
  return plan->getTrainings();
}

void Model::setTraining(unsigned int pos, const std::string &name, const DateTime &start,
                        double distance, const TimeSpan &duration,
                        unsigned int exPos, action operation,
                        const std::string &exName, const TimeSpan &exDuration,
                        const TimeSpan &exRecovery) const {
    plan->setTraining(pos, name, start, distance, duration, exPos, operation,
                      exName, exDuration, exRecovery);
}

unsigned int Model::getPlanSize() const { return plan->getSize(); }

bool Model::isEmpty() const { return plan->isEmpty(); }

// rule of three
Model::Model(const Model &model) : plan(new Plan(*model.plan)) {}

Model &Model::operator=(const Model &model) {
  if (this != &model) {
    delete plan;
    plan = new Plan(*model.plan);
  }
  return *this;
}

Model::~Model() { delete plan; }
