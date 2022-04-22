#include "endurance.h"

Endurance::Endurance()
    :Training(), distance(1), duration(){}

Endurance::Endurance(const std::string &name, const DateTime& start, double dist, const TimeSpan& dur)
    : Training(name, start),
      distance(dist > 0? dist : throw std::invalid_argument("Invalid value of distance inserted")),
      duration(!dur.isNull()? dur : throw std::invalid_argument("Invalid value of training duration inserted")){}

double Endurance::getDistance() const{return distance;}

TimeSpan Endurance::getDuration() const{return duration;}

void Endurance::setDistance(double dist){
    distance = (dist > 0? dist : throw std::invalid_argument("Invalid value of distance inserted"));
}

void Endurance::setDuration(const TimeSpan& dur) {
    duration = (!dur.isNull()? dur : throw std::invalid_argument("Invalid value of training duration inserted"));
}
