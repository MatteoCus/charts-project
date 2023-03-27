#ifndef TRAINING_H
#define TRAINING_H

#include "DateTime/datetime.h"
#include "DateTime/timespan.h"
#include <stdexcept>

class Training {
private:
  std::string name;
  DateTime start;

protected:
  static const double avgWeight;

public:
  Training();
  Training(const std::string &name, const DateTime &start);
  virtual TimeSpan getDuration() const = 0;
  virtual unsigned int CaloriesBurned() const = 0;
  std::string getName() const;
  DateTime getStart() const;
  DateTime getEnd() const;
  void setName(const std::string &newName);
  void setStart(const DateTime &newStart);
  virtual Training *clone() const = 0;
  virtual ~Training() = default;
};

#endif // TRAINING_H
