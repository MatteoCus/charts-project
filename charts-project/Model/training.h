#ifndef TRAINING_H
#define TRAINING_H

#include "DateTime/datetime.h"
#include "DateTime/timespan.h"
#include <stdexcept>

class Training {
private:
  double weight;
  DateTime start;

protected:
  static const double minWeight;

public:
  Training();
  Training(double weight, const DateTime &start);
  virtual TimeSpan Duration() const = 0;
  virtual unsigned int CaloriesBurned() const = 0;
  double getWeight() const;
  DateTime getStart() const;
  DateTime getEnd() const;
  void setWeight(double weight);
  void setStart(const DateTime &dateTime);
  virtual Training *clone() const = 0;
  virtual ~Training() = default;
};

#endif // TRAINING_H
