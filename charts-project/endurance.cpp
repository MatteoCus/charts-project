#include "endurance.h"

Endurance::Endurance(QDateTime start, double weight, double dist, QTime dur)
    : Training(start, weight), distance(dist>0? dist : throw std::invalid_argument("Invalid value of distance inserted")),
      duration(dur){}

double Endurance::getDistance() const{return distance;}
QTime Endurance::Duration() const{return duration;}
