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
    void addNewTraining(unsigned int, const std::string&, double, double = 0.0, const TimeSpan& = TimeSpan(),
                        const std::string& ="", const TimeSpan& = TimeSpan(), const TimeSpan& = TimeSpan()) const;

    void removeTraining(unsigned int) const;
    Training* getTraining(unsigned int) const;
    std::list<Training*> getTrainings() const;

    void setTraining(unsigned int, double, double = 0.0, const TimeSpan& = TimeSpan(), unsigned int = 0,
          action = nothing, const std::string& ="", const TimeSpan& = TimeSpan(),const TimeSpan& = TimeSpan()) const;

    unsigned int getPlanSize() const;
    bool isEmpty() const;

    //rule of three
    Model(const Model&);
    Model& operator=(const Model&);
    ~Model();
};

#endif // MODEL_H
