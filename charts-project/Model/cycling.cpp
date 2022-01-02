#include "cycling.h"

Cycling::Cycling(double weight, double dist, const TimeSpan& dur)
    : Endurance(weight, dist, dur){}

const unsigned int Cycling::MET = 9;

const double Cycling::c2 = 0.0175;

/*
 * pace is measured in min/10km
*/

TimeSpan Cycling::Pace() const{
    return ((Duration()/getDistance()) * 10);
}

/*
 * Calories calculation formula:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 * WALK: Cal = MET * weight (in kg) * c2 * distance (in km)
 */

unsigned int Cycling::CaloriesBurned() const{ return (MET * getWeight() * c2 * Duration().getTotalMinutes()); }

Cycling* Cycling::clone() const{ return new Cycling(*this);}