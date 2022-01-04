#ifndef MODEL_H
#define MODEL_H

#include "training.h"
#include "exercisecreator.h"
#include "action.h"
#include "plan.h"
#include "trainingcreator.h"
#include <string>

class Model
{
private:
    Plan* plan;
    static Plan* copy(const Model&);
    static void destroy(const Model& );
public:
    Model();
    void addNewTraining(unsigned int pos, const std::string& type, double weight, double distance = 0.0,
                        const TimeSpan& duration= TimeSpan(),const std::string& exName="",
                        const TimeSpan& exDuration= TimeSpan(), const TimeSpan& exRecovery = TimeSpan()) const;

    void removeTraining(unsigned int pos) const;
    Training* getTraining(unsigned int pos) const;
    std::list<Training*> getTrainings() const;

    void setTraining(unsigned int pos, double weight, double distance = 0.0, const TimeSpan& duration= TimeSpan(),
                     unsigned int exPos= 0, action operation= nothing, const std::string& exName="",
                     const TimeSpan& exDuration= TimeSpan(), const TimeSpan& exRecovery = TimeSpan()) const;

    unsigned int getPlanSize() const;
    bool isEmpty() const;

    //rule of three
    Model(const Model& model);
    Model& operator=(const Model& model);
    ~Model();
};

#endif // MODEL_H
