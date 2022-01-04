#include "trainingcreator.h"

Training* trainingCreator::createTraining(const std::string& type,double weight, double distance,
                                            TimeSpan duration, const std::string& exName, TimeSpan exDuration,
                                            TimeSpan exRecovery) const{
    try
    {
        if(type == "Cycling") { return new Cycling(weight, distance, duration);}
        else if(type == "Run") { return new Run(weight, distance, duration);}
        else if(type == "Walk") { return new Walk(weight, distance, duration);}

        //from here, there will be just a Repetition training creation (or an error)
        exerciseCreator* creator = new exerciseCreator();
        Exercise* ex = creator->createExercise(exName, exDuration, exRecovery);
        delete creator;
        if(type == "Rugby") {
             Rugby* r = new Rugby(weight);
             r->addExercise(ex);
             return r;
        }
        else if(type == "Tennis") {
            Tennis* t = new Tennis(weight);
            t->addExercise(ex);
            return t;
       }
    }
    catch (std::invalid_argument) {
        throw;                          //re-throw of the exception
    }

    throw std::invalid_argument("Invalid creation request");
}
