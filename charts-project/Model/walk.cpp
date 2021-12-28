#include "walk.h"

Walk::Walk(double weight, double dist, const TimeSpan& dur)
    : Endurance(weight, dist, dur){}

/*
 * pace is measured in min/km
*/
TimeSpan Walk::Pace() const{
    return Duration()/getDistance();
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
