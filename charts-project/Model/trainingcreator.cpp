#include "trainingcreator.h"
#include "exercisecreator.h"

Training *trainingCreator::createTraining(const std::string &type,
                                          const std::string &name, const DateTime &start,
                                          double distance, TimeSpan duration,
                                          const std::vector<std::string>* exName,
                                          const std::vector<TimeSpan>* exDuration,
                                          const std::vector<TimeSpan>* exRecovery) const {
    if (type == "Cycling")
        return new Cycling(name, start, distance, duration);
     else if (type == "Run")
        return new Run(name, start, distance, duration);
     else if (type == "Walk")
        return new Walk(name, start, distance, duration);

    Repetition *aux = nullptr;
    if (type == "Rugby")
        aux = new Rugby(name, start);
     else if (type == "Tennis")
        aux = new Tennis(name, start);

    if (aux && exName->size() == exDuration->size() && exDuration->size() == exRecovery->size() && exName->size() > 0 && exName->size() < 16) {
        exerciseCreator *creator = new exerciseCreator();
        for (unsigned int i = 0; i < exName->size(); ++i )
            aux->addExercise(creator->createExercise((*exName)[i], (*exDuration)[i], (*exRecovery)[i]));

        delete creator;
        return aux;
    } else
        throw std::runtime_error("errore");
}
