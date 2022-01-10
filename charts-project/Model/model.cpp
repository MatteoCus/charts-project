#include "model.h"

Model::Model() : plan(new Plan()) {}

Plan *Model::copy(const Model &model) { return new Plan(*model.plan); }

void Model::destroy(const Model &model) { delete model.plan; }

void Model::addNewTraining(const std::string &type, const std::string &name,
                           const DateTime &start, double distance,
                           const TimeSpan &duration, const std::string &exName,
                           const TimeSpan &exDuration,
                           const TimeSpan &exRecovery) const {
  try {
    trainingCreator *creator = new trainingCreator();
    Training *tr =
        creator->createTraining(type, name, start, distance, duration, exName,
                                exDuration, exRecovery);
    plan->insertTraining(tr);
    delete creator;
  } catch (DateException &ex) {
    throw ex;
  } catch (std::invalid_argument &e) {
    throw e; // re-throw of the exception
  }
}

void Model::removeTraining(unsigned int pos) const {
  try {
    plan->removeTraining(pos);
  } catch (std::out_of_range &e) {
    throw e;
  }
}

Training *Model::getTraining(unsigned int pos) const {
  try {
    return plan->getTraining(pos);
  } catch (std::out_of_range &e) {
    throw e;
  }
}

std::list<Training *> Model::getTrainings() const {
  return plan->getTrainings();
}

void Model::setTraining(unsigned int pos, const std::string &name, const DateTime &start,
                        double distance, const TimeSpan &duration,
                        unsigned int exPos, action operation,
                        const std::string &exName, const TimeSpan &exDuration,
                        const TimeSpan &exRecovery) const {
  try {
    plan->setTraining(pos, name, start, distance, duration, exPos, operation,
                      exName, exDuration, exRecovery);
  } catch (DateException &ex) {
    throw ex;
  } catch (std::invalid_argument &e) {
    throw e;
  } catch (std::out_of_range &ex) {
    throw ex;
  }
}

unsigned int Model::getPlanSize() const { return plan->getSize(); }

bool Model::isEmpty() const { return plan->isEmpty(); }

// rule of three
Model::Model(const Model &model) : plan(copy(model)) {}

Model &Model::operator=(const Model &model) {
  if (this != &model) {
    destroy(*this);
    plan = copy(model);
  }
  return *this;
}

Model::~Model() { destroy(*this); }
