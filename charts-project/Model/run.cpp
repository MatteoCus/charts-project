#include "run.h"

Run::Run(double weight, const DateTime& start, double dist, const TimeSpan& dur)
    : Endurance(weight, start, dist, dur){}

/*
 * pace is measured in min/km
*/
TimeSpan Run::Pace() const{
  if(getDistance())
    return Duration()/getDistance();
  throw std::runtime_error("Trying to calculate pace with a null distance");
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
