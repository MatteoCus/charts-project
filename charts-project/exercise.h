#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <QTime>
#include "clonable.h"

class Exercise : public Clonable
{
private:
    std::string name;
    QTime duration;
    QTime recovery;
public:
    Exercise(const std::string& ="", const QTime& = QTime(0,0), const QTime& = QTime(0,0));
    std::string getName() const;
    QTime getDuration() const;
    QTime getRecoveryTime() const;
    void setName(const std::string&);
    void setDuration(const QTime&);
    void setRecovery(const QTime&);
    Exercise* clone() const override;
    virtual ~Exercise() = default;
};

#endif // EXERCISE_H
