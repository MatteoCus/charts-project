#include "walk.h"

Walk::Walk(const std::string &name, const DateTime& start, double dist, const TimeSpan& dur)
    : Endurance(name, start, dist, dur){}

/*
 * pace is measured in min/km
*/
TimeSpan Walk::Pace() const{
    if(getDistance())
      return getDuration()/getDistance();
    throw std::runtime_error("Trying to calculate pace with a null distance");
}

/*
 * Calories calculation formula:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 * WALK: Cal = 0.5 * weight (in kg) * distance (in km)
 */

unsigned int Walk::CaloriesBurned() const{ return (0.5 * getWeight() * getDistance()); }

Walk* Walk::clone() const{ return new Walk(*this);}
