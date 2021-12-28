#include "endurance.h"

Endurance::Endurance(double weight, double dist, const TimeSpan& dur)
    : Training(weight), distance(dist >= 0? dist : throw std::invalid_argument("Invalid value of distance inserted")),
      duration(dur){}

double Endurance::getDistance() const{return distance;}

TimeSpan Endurance::Duration() const{return duration;}

void Endurance::setDistance(double dist){
    distance = (dist > 0? dist : throw std::invalid_argument("Invalid value of distance inserted"));
}

void Endurance::setDuration(const TimeSpan& dur) {duration = (dur);}
