#include "cycling.h"

Cycling::Cycling(const std::string &name, const DateTime& start, double dist, const TimeSpan& dur)
    : Endurance(name, start, dist, dur){}

const unsigned int Cycling::MET = 9;

const double Cycling::c2 = 0.0175;

/*
 * Calories calculation measurement unit:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 */

unsigned int Cycling::CaloriesBurned() const{
    unsigned int res = MET * avgWeight * c2 * getDuration().getTotalMinutes();
    return (res > 200? res : 425);
}

Cycling* Cycling::clone() const{ return new Cycling(*this);}
