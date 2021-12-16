#include "training.h"
#include <stdexcept>
Training::Training(QDateTime begin, double mass)
    : start(begin.isValid()? begin : throw std::invalid_argument("Invalid value of start date inserted!") ), weight(mass >= minWeight? mass : throw std::invalid_argument("Invalid value of weight inserted!")){}
double Training::minWeight = 20;
QDateTime Training::end() const{ return start.addMSecs(Duration().msecsSinceStartOfDay());}
QDateTime Training::getStart() const    {return start;}
double Training::getWeight() const  {return weight;}
