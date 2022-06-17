#include "plan.h"
#include <iostream>
using namespace std;

bool Plan::check(Training *training) {
    if (!training)
        throw std::invalid_argument("Tentativo di verifica di correttezza di un allenamento inesistente!");
    DateTime start = training->getStart();
    auto it = trainings.begin();
    while (it != trainings.end() && (start > (*it)->getEnd())) {
        ++it;
    }
    if (training->getDuration() <= TimeSpan(20) &&
            (it == trainings.end() || (training->getEnd() < (*it)->getStart())))
    {
        auto aux = dynamic_cast<Repetition*>(training);
        if (aux==nullptr || (aux->getSize() < 16 && aux->getSize() > 0))
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
    }
    else
    {
        delete training;
        throw std::invalid_argument("L'allenamento non rispetta i vincoli di programma!");
    }
}

void Plan::removeTraining(unsigned int pos) {
    if (pos >= trainings.size())
        throw std::out_of_range("Tentativo di rimozione di un allenamento usando un indice non valido!");
    auto it = trainings.begin();
    std::advance(it, pos);
    delete *it;
    trainings.erase(it);
}

Training *Plan::getTraining(unsigned int pos) const {
    if (pos >= trainings.size())
        throw std::out_of_range("Richiesta di un allenamento effettuata usando un indice non valido!");
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
        throw std::out_of_range("Tentativo di modifica di un allenamento in una posizione non valida!");

    auto it = trainings.begin();
    std::advance(it, pos);
    Training * newTraining = (*it)->clone();
    Training * oldTraining = (*it)->clone();
    trainings.erase(it);

    try {
        newTraining->setName(name);
        newTraining->setStart(start);
        if (dynamic_cast<Endurance *>(newTraining)) {
            Endurance *endur = static_cast<Endurance *>(newTraining);
            endur->setDistance(distance);
            endur->setDuration(duration);
        } else if (dynamic_cast<Repetition *>(newTraining)) {
            unsigned int size = exName->size();
            if (size != exRecovery->size() || size != exDuration->size())
                throw std::runtime_error("Tentativo di modifica di un allenamento con valori errati!");

            Repetition *rep = static_cast<Repetition *>(newTraining);
            Exercise *aux = nullptr;

            switch (operation) {
            case add:
                if (size != 1)
                    throw std::runtime_error("Tentativo di aggiunta di più di un esercizio alla volta!");
                aux = exerciseCreator::createExercise(exName->at(0), exDuration->at(0), exRecovery->at(0));
                rep->addExercise(aux);
                break;

            case insert:
                if (size != 1)
                    throw std::runtime_error("Tentativo di inserimento di più di un esercizio alla volta!");
                aux = exerciseCreator::createExercise(exName->at(0), exDuration->at(0), exRecovery->at(0));
                rep->insertExercise(exPos, aux);
                break;

            case set:
                if (size != rep->getSize())
                    throw std::runtime_error("Tentativo di modifica di esercizi di un allenamento usando un numero di dati errato!");
                for (unsigned int i = 0; i < rep->getSize(); ++i)
                {
                    aux = exerciseCreator::createExercise(exName->at(i), exDuration->at(i), exRecovery->at(i));
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
                            "Tentativo di effettuare un'azione non valida sugli esercizi di un allenamento!");
            }
        } else
            throw std::invalid_argument("Tentativo di modifica di un allenamento di tipo non valido!");
        if (check(newTraining)) {
            delete oldTraining;
            insertTraining(newTraining);
        } else
            throw std::invalid_argument("Tentativo di modifica di un allenamento con valori non validi!");

    }  catch (std::runtime_error) {
        insertTraining(oldTraining);
        delete newTraining;
        throw;
    } catch (std::invalid_argument e) {
        insertTraining(oldTraining);
        delete newTraining;
        throw;
    } catch(std::out_of_range){
        insertTraining(oldTraining);
        delete newTraining;
        throw;
    }
}

unsigned int Plan::getSize() const { return trainings.size(); }

bool Plan::isEmpty() const { return trainings.empty(); }

void Plan::clear()
{
    for (auto values : trainings)
        delete values;
    trainings.erase(trainings.begin(), trainings.end());
}

const std::list<Training *>* Plan::getTrainings() const { return &trainings; }

std::list<Training *> Plan::copy(const Plan &plan) {
    std::list<Training *> aux;
    for (auto it = plan.trainings.begin(); it != plan.trainings.end(); ++it)
        aux.push_back((*it)->clone());
    return aux;
}

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
