#include "training.h"
#include <stdexcept>
Training::Training(const QDateTime& begin, double mass)
    : start(begin.isValid()? begin : throw std::invalid_argument("Invalid value of start date inserted!") ),
      weight(mass >= minWeight? mass : throw std::invalid_argument("Invalid value of weight inserted!")){}
const double Training::minWeight = 20;
QDateTime Training::end() const{ return start.addMSecs(Duration().msecsSinceStartOfDay());}
QDateTime Training::getStart() const    {return start;}
double Training::getWeight() const  {return weight;}
void Training::setStart(const QDateTime& st){
    start = (st.isValid()? st : throw std::invalid_argument("Invalid value of start date inserted!"));
}
void Training::setWeight(double mass){
    weight = (mass >= minWeight? mass : throw std::invalid_argument("Invalid value of weight inserted!"));
}
