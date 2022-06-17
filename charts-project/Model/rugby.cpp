#include "rugby.h"

Rugby::Rugby(const std::string &name, const DateTime& start)
    :Repetition(name, start){}

const double Repetition::c1 = 1.15;
const unsigned int Repetition::c2 = 105;

unsigned int Rugby::CaloriesBurned() const {
    return (c1 * Intensity()/100 * avgWeight * (getDuration().getTotalMinutes())/10);
}

double Rugby::Intensity() const {
    if(!totalRecovery().isNull())
    {
        double res = c2 * (getDuration()/totalRecovery())/4;
        return (res < 100? res : 98.25);
    }
    else
        throw std::runtime_error("Tentativo di calcolo dell'intensità di un allenamento usando una durata nulla!");
}
Rugby* Rugby::clone() const { return new Rugby(*this);}
