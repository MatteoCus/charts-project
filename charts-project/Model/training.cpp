#include "training.h"

Training::Training(double mass)
    : weight(mass >= minWeight? mass : throw std::invalid_argument("Invalid value of weight inserted!")){}

const double Training::minWeight = 20;

double Training::getWeight() const  {return weight;}

void Training::setWeight(double mass){
    weight = (mass >= minWeight? mass : throw std::invalid_argument("Invalid value of weight inserted!"));
}
