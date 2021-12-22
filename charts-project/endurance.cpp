#include "endurance.h"

Endurance::Endurance(const QDateTime& start, double weight, double dist, const QTime& dur)
    : Training(start, weight), distance(dist >= 0? dist : throw std::invalid_argument("Invalid value of distance inserted")),
      duration(dur.isValid()? dur : throw std::invalid_argument("Invalid value of duration inserted")){}

double Endurance::getDistance() const{return distance;}

QTime Endurance::Duration() const{return duration;}

void Endurance::setDistance(double dist){
    distance = (dist > 0? dist : throw std::invalid_argument("Invalid value of distance inserted"));
}

void Endurance::setDuration(const QTime& dur){
   duration = (dur.isValid()? dur : throw std::invalid_argument("Invalid value of duration inserted"));
}
