#include "training.h"
#include <stdexcept>
Training::Training(QDateTime begin, double mass)
    : start(begin.isValid()? begin : throw std::invalid_argument("Invalid value of starting date inserted")), weight(mass > weightLimit? mass : throw std::invalid_argument("Invalid value of weight inserted!")){}
QDateTime Training::end() const{ return start.addSecs(Duration().msecsSinceStartOfDay());}
QDateTime Training::getStart() const{ return start;}
double Training::getWeight() const{ return weight;}
