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
  virtual TimeSpan Duration() const = 0;
  virtual unsigned int CaloriesBurned() const = 0;
  double getWeight() const;
  DateTime getStart() const;
  DateTime getEnd() const;
  void setName(const std::string &name);
  void setStart(const DateTime &dateTime);
  virtual Training *clone() const = 0;
  virtual ~Training() = default;
};

#endif // TRAINING_H
