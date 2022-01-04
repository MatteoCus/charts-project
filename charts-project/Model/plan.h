#ifndef PLAN_H
#define PLAN_H

#include "action.h"
#include "DateTime/datetime.h"
#include "endurance.h"
#include "exercisecreator.h"
#include "repetition.h"
#include "training.h"
#include <list>
#include <string>

class Plan {
private:
  std::list<Training *> trainings;
  static std::list<Training *> copy(const Plan &plan);
  static void destroy(const Plan &plan);

public:
  Plan() = default;
  bool check(Training *training);
  void insertTraining(Training *training);
  void removeTraining(unsigned int pos);
  Training *getTraining(unsigned int pos) const;
  std::list<Training *> getTrainings() const;
  unsigned int getSize() const;
  bool isEmpty() const;
  void setTraining(unsigned int pos, double weight, const DateTime &start,
                   double distance = 0.0, const TimeSpan &duration = TimeSpan(),
                   unsigned int exPos = 0, action operation = nothing,
                   const std::string &exName = "",
                   const TimeSpan &exDuration = TimeSpan(),
                   const TimeSpan &exRecovery = TimeSpan());

  Plan(const Plan &plan);
  Plan &operator=(const Plan &plan);
  ~Plan();
};

#endif // PLAN_H
