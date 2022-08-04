#include "walk.h"

Walk::Walk(const std::string &name, const DateTime& start, double dist, const TimeSpan& dur)
    : Endurance(name, start, dist, dur){}

/*
 * Calories calculation measurement unit:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 */

unsigned int Walk::CaloriesBurned() const{
    unsigned int res = 0.5 * avgWeight * getDistance();
    return (res > 200? res : 325);
}

Walk* Walk::clone() const{ return new Walk(*this);}
