#include "cycling.h"

Cycling::Cycling(const QDateTime& start, double weight, double dist, const QTime& dur)
    : Endurance(start, weight, dist, dur){}

const unsigned int Cycling::MET = 9;

const double Cycling::c2 = 0.0175;

/*
 * pace is measured in min/10km
*/

QTime Cycling::Pace() const{
    QTime pace = QTime(0,0);
    pace = pace.addMSecs(10 * (Duration().msecsSinceStartOfDay())/getDistance());
    return pace;
}

/*
 * Calories calculation formula:
 *  Calorie (capital 'c') = "great calorie",
 *  calorie (lowercase 'c') = "small calorie"
 * 1 Cal = 1kcal
 * WALK: Cal = MET * weight (in kg) * c2 * distance (in km)
 */

unsigned int Cycling::CaloriesBurned() const{ return (MET * getWeight() * c2 * Duration().msecsSinceStartOfDay()/(msecInSec * secInMinute)); }

Cycling* Cycling::clone() const{ return new Cycling(*this);}
