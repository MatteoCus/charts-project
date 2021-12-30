#include "endurance.h"

Endurance::Endurance()
    :Training(), distance(0), duration(){}

Endurance::Endurance(double weight, double dist, const TimeSpan& dur)
    : Training(weight),
      distance(dist >= 0? dist : throw std::invalid_argument("Invalid value of distance inserted")),
      duration(!dur.isNull()? dur : throw std::invalid_argument("Invalid value of training duration inserted")){}

double Endurance::getDistance() const{return distance;}

TimeSpan Endurance::Duration() const{return duration;}

void Endurance::setDistance(double dist){
    distance = (dist > 0? dist : throw std::invalid_argument("Invalid value of distance inserted"));
}

void Endurance::setDuration(const TimeSpan& dur) {
    duration = (!dur.isNull()? dur : throw std::invalid_argument("Invalid value of training duration inserted"));
}
