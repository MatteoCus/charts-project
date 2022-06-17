#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <stdexcept>
#include "DateTime/timespan.h"

class Exercise
{
private:
    std::string name;
    TimeSpan duration;
    TimeSpan recovery;
public:
    Exercise();
    Exercise(const Exercise& ex);
    Exercise(const std::string& name, const TimeSpan& duration, const TimeSpan& recovery);
    std::string getName() const;
    TimeSpan getDuration() const;
    TimeSpan getRecoveryTime() const;
    void setName(const std::string& name);
    void setDuration(const TimeSpan& duration);
    void setRecovery(const TimeSpan& recovery);
    virtual Exercise* clone() const;
    virtual ~Exercise() = default;
};

#endif // EXERCISE_H
