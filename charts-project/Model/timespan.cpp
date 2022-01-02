#include "timespan.h"

TimeSpan::TimeSpan(unsigned int h, unsigned int m, unsigned int s)
    :sec(h * secInHour + m * secInMinute + s){}

const unsigned int TimeSpan::secInHour = 3600;

const unsigned int TimeSpan::secInMinute = 60;

unsigned int TimeSpan::getTotalMinutes() const {return sec/secInMinute;}

unsigned int TimeSpan::getTotalSeconds() const {return sec;}

unsigned int TimeSpan::getHours() const {return sec/secInHour;}

unsigned int TimeSpan::getMinutes() const {return (sec - (getHours() * secInHour))/secInMinute;}

unsigned int TimeSpan::getSeconds() const {return (sec - (getHours() * secInHour) - (getMinutes() * secInMinute)); }

bool TimeSpan::isNull() const {return sec;}

TimeSpan TimeSpan::operator+(const TimeSpan& time) const {return sec + time.sec; }

TimeSpan TimeSpan::operator-(const TimeSpan& time) const {return sec - time.sec;}

TimeSpan TimeSpan::operator* (double n) const {return TimeSpan()+(sec * n);}

TimeSpan TimeSpan::operator/(double n) const {return TimeSpan() +(sec / n);}

double TimeSpan::operator/(const TimeSpan& time) const {
    if(time.sec != 0)
        return sec / time.sec;
    throw std::invalid_argument("Invalid timespan passed to divide a timespan");
}

bool TimeSpan::operator==(const TimeSpan& time) const {return sec == time.sec;}
