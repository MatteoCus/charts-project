#include "run.h"

Run::Run(double weight, double dist, const TimeSpan& dur)
    : Endurance(weight, dist, dur){}

/*
 * pace is measured in min/km
*/
TimeSpan Run::Pace() const{
  return Duration()/getDistance();
}

/*
 * Calories calculation formula:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 * RUN: Cal = 0.9 * weight (in kg) * distance (in km)
 * pace don't make any difference until 22km/h,
 * under 3:00 min/km, barely impossible to
 * achieve if not a pro runner
 */

unsigned int Run::CaloriesBurned() const{ return (0.9 * getWeight() * getDistance()); }

Run* Run::clone() const{ return new Run(*this);}
