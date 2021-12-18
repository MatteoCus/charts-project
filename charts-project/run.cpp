#include "run.h"

Run::Run(const QDateTime& start, double weight, double dist, const QTime& dur)
    : Endurance(start, weight, dist, dur){}

/*
 * pace is measured in min/km
*/
QTime Run::Pace() const{
    QTime pace = QTime(0,0);
    pace = pace.addMSecs((Duration().msecsSinceStartOfDay())/getDistance());
    return pace;
}

/*
 * Calories calculation formula:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 * RUN: Cal = 0.9 * weight (in kg) * distance (in km)
 * pace don't make any difference until 22km/h,
 * under 3:00 min/km, barely impossible to
 * achieve if you're not a pro runner
 */

unsigned int Run::CaloriesBurned() const{ return (0.9 * getWeight() * getDistance()); }

Run* Run::clone() const{ return new Run(*this);}
