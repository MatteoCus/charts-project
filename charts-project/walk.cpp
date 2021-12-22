#include "walk.h"

Walk::Walk(const QDateTime& start, double weight, double dist, const QTime& dur)
    : Endurance(start, weight, dist, dur){}

/*
 * pace is measured in min/km
*/
QTime Walk::Pace() const{
    QTime pace = QTime(0,0);
    return pace.addMSecs((Duration().msecsSinceStartOfDay())/getDistance());
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
