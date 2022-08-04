#include "run.h"

Run::Run(const std::string &name, const DateTime& start, double dist, const TimeSpan& dur)
    : Endurance(name, start, dist, dur){}

/*
 * Calories calculation measurement unit:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 */

unsigned int Run::CaloriesBurned() const{
    unsigned int res = 0.9 * avgWeight * getDistance();
    return (res > 200? res : 375);
}

Run* Run::clone() const{ return new Run(*this);}
