#include "plan.h"

bool Plan::check(Training *training) {
  if (!training)
    throw std::invalid_argument("Null training passed to check ");
  DateTime start = training->getStart();
  auto it = trainings.begin();
  while (it != trainings.end() && //(start > (*it)->getStart()) &&
         (start > (*it)->getEnd())) {
    ++it;
  }
  if (training->getDuration() <= TimeSpan(10) && (it == trainings.end() ||
      (training->getEnd() < (*it)->getStart())))
  {
      auto aux = dynamic_cast<Repetition*>(training);
      if (!aux || (aux && aux->getSize() < 16))
          return true;
      else
          return false;
  }
  else
    return false;
}

void Plan::insertTraining(Training *training) {
  if (check(training)) {
    auto it = trainings.begin();
    while (it != trainings.end() && (training->getStart() > (*it)->getStart()))
      ++it;
    trainings.insert(it, training);
  } else
    throw std::invalid_argument(
        "Conflict of trainings' durations during insertion operation");
}

void Plan::removeTraining(unsigned int pos) {
  if (pos >= trainings.size())
    throw std::out_of_range("Invalid training's removal index");
  if (pos == trainings.size() - 1)
    trainings.pop_back();
  else if (pos == 0)
    trainings.pop_front();
  else {
    auto it = trainings.begin();
    std::advance(it, pos);
    trainings.erase(it);
  }
}

Training *Plan::getTraining(unsigned int pos) const {
  if (pos >= trainings.size())
    throw std::out_of_range("Invalid index for requested-training");
  auto it = trainings.begin();
  std::advance(it, pos);
  return *it;
}

void Plan::setTraining(unsigned int pos, const std::string &name, const DateTime &start,
                       double distance, const TimeSpan &duration,
                       unsigned int exPos, action operation,
                       const std::vector<std::string>* exName,
                       const std::vector<TimeSpan>*exDuration,
                       const std::vector<TimeSpan>* exRecovery) {
  if (pos >= getSize())
    throw std::out_of_range("Invalid modify index");

  auto it = trainings.begin();
  std::advance(it, pos);
  Training *backup = (*it)->clone();

  try {
    (*it)->setName(name);
    if (dynamic_cast<Endurance *>(*it)) {
      Endurance *endur = static_cast<Endurance *>(*it);
      endur->setDistance(distance);
      endur->setDuration(duration);
    } else if (dynamic_cast<Repetition *>(*it)) {
        unsigned int size = exName->size();
        if (size != exRecovery->size() || size != exDuration->size())
            throw std::runtime_error("Impossibile modificare l'allenamento: errore negli esercizi!");

      Repetition *rep = static_cast<Repetition *>(*it);
      exerciseCreator *creator = new exerciseCreator();
      Exercise *aux = nullptr;
      switch (operation) {
      case add:
        if (size != 1)
              throw std::runtime_error("Impossibile aggiungere l'esercizio");
        aux = creator->createExercise((*exName)[0], (*exDuration)[0], (*exRecovery)[0]);
        rep->addExercise(aux);
        break;

      case insert:
        if (size != 1)
              throw std::runtime_error("Impossibile inserire l'esercizio");
        aux = creator->createExercise((*exName)[0], (*exDuration)[0], (*exRecovery)[0]);
        rep->insertExercise(exPos, aux);
        break;

      case set:
        if (size != rep->getSize())
            throw std::runtime_error("Impossibile modificare gli esercizi");
        for (unsigned int i = 0; i < rep->getSize(); ++i)
        {
            aux = creator->createExercise((*exName)[i], (*exDuration)[i], (*exRecovery)[i]);
            rep->setExercise(i, aux);
        }
        break;

      case eliminate:
        rep->removeExercise(exPos);
        break;

      case nothing:
        break;

      default:
        throw std::invalid_argument(
            "Invalid action on the exercises of a repetition training");
      }
      delete creator;
    } else
      throw std::invalid_argument("Invalid type of training passed");
    (*it)->setStart(start);
    Training *tr = (*it)->clone();
    trainings.erase(it);
    if (check(tr)) {
      delete backup;
      insertTraining(tr);           //qualora dovessero essere state modificate le date (di inizio e/o di fine)
    } else {
      delete tr;
      throw std::invalid_argument(
          "Conflict of trainings' durations during modify operation");
    }

  } catch (std::invalid_argument &e) {
    insertTraining(backup); // ritorna all'ultimo stato corretto --> messo qui perchè l'errore invalid_argument può avvenire anche sopra e non solo qui con check
    throw e;
  }
}

unsigned int Plan::getSize() const { return trainings.size(); }

bool Plan::isEmpty() const { return trainings.empty(); }

const std::list<Training *>& Plan::getTrainings() const { return trainings; }

std::list<Training *> Plan::copy(const Plan &plan) {
  std::list<Training *> aux;
  for (auto it = plan.trainings.begin(); it != plan.trainings.end(); ++it)
    aux.push_back((*it)->clone()); // clone pattern su gerarchia di Training
  return aux;
}

// preso const Plan&, dealloca gli oggetti della list uno ad uno
void Plan::destroy(const Plan &plan) {
  for (auto it = plan.trainings.begin(); it != plan.trainings.end(); ++it)
    delete (*it);
}

Plan::Plan(const Plan &plan) : trainings(copy(plan)) {}

Plan &Plan::operator=(const Plan &plan) {
  if (this != &plan) {
    destroy(*this);
    trainings = copy(plan);
  }
  return *this;
}

Plan::~Plan() { destroy(*this); }
