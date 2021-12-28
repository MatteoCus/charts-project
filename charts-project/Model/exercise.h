#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include "timespan.h"
#include "clonable.h"

class Exercise : public Clonable
{
private:
    std::string name;
    TimeSpan duration;
    TimeSpan recovery;
public:
    Exercise(const std::string& ="", const TimeSpan& = TimeSpan(), const TimeSpan& = TimeSpan());
    std::string getName() const;
    TimeSpan getDuration() const;
    TimeSpan getRecoveryTime() const;
    void setName(const std::string&);
    void setDuration(const TimeSpan&);
    void setRecovery(const TimeSpan&);
    Exercise* clone() const override;       //clone pattern
    virtual ~Exercise() = default;
};

#endif // EXERCISE_H
