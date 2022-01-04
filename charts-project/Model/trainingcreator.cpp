#include "trainingcreator.h"
#include "exercisecreator.h"

Training *trainingCreator::createTraining(const std::string &type,
                                          double weight, const DateTime &start,
                                          double distance, TimeSpan duration,
                                          const std::string &exName,
                                          const TimeSpan &exDuration,
                                          const TimeSpan &exRecovery) const {
  try {
    if (type == "Cycling") {
      return new Cycling(weight, start, distance, duration);
    } else if (type == "Run") {
      return new Run(weight, start, distance, duration);
    } else if (type == "Walk") {
      return new Walk(weight, start, distance, duration);
    }

    Repetition *aux = nullptr;
    if (type == "Rugby") {
      aux = new Rugby(weight, start);
    } else if (type == "Tennis") {
      aux = new Tennis(weight, start);
    }
    if (aux) {
      exerciseCreator *creator = new exerciseCreator();
      aux->addExercise(creator->createExercise(exName, exDuration, exRecovery));
      return aux;
    } else
      throw std::runtime_error("Invalid type of training inserted");
  } catch (DateException &ex) {
    throw ex;
  } catch (std::invalid_argument &e) {
    throw e; // re-throw of the exception
  }

  throw std::invalid_argument("Invalid creation request");
}
