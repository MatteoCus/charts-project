#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <stdexcept>
#include "timespan.h"

//invariante: !duration.isNull() && !recovery.isNull() (non nel costruttore di default)
class Exercise
{
private:
    std::string name;
    TimeSpan duration;
    TimeSpan recovery;
public:
    Exercise();
    Exercise(const std::string& , const TimeSpan&, const TimeSpan&);
    std::string getName() const;
    TimeSpan getDuration() const;
    TimeSpan getRecoveryTime() const;
    void setName(const std::string&);
    void setDuration(const TimeSpan&);
    void setRecovery(const TimeSpan&);
    virtual Exercise* clone() const;       //clone pattern
    virtual ~Exercise() = default;
};

#endif // EXERCISE_H