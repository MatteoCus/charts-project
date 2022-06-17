#include "trainingcreator.h"
#include "exercisecreator.h"
#include <iostream>
using namespace std;

Training *trainingCreator::createTraining(const std::string &type,
                                          const std::string &name, const DateTime &start,
                                          double distance, TimeSpan duration,
                                          const std::vector<std::string>* exName,
                                          const std::vector<TimeSpan>* exDuration,
                                          const std::vector<TimeSpan>* exRecovery) {


        if (type == "Ciclismo")
            return new Cycling(name, start, distance, duration);
        else if (type == "Corsa")
            return new Run(name, start, distance, duration);
        else if (type == "Camminata")
            return new Walk(name, start, distance, duration);
        else{

            Repetition* aux = nullptr;
            try {
                if (type == "Rugby")
                    aux = new Rugby(name, start);
                else if (type == "Tennis")
                    aux = new Tennis(name, start);

                if (aux && exName->size() == exDuration->size() && exDuration->size() == exRecovery->size() && exName->size() > 0 && exName->size() < 16) {
                    for (unsigned int i = 0; i < exName->size(); ++i )
                        aux->addExercise(exerciseCreator::createExercise((*exName)[i], (*exDuration)[i], (*exRecovery)[i]));
                }
                else
                    throw std::runtime_error("Tentativo di creazione di una serie di esercizi che non rispettano i vincoli di programma!");

            }   catch (std::runtime_error) {
                delete aux;
                throw;
            }   catch (std::invalid_argument) {
                delete aux;
                throw;
            }
        return aux;
    }
}
