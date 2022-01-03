#include "timespan.h"
#include <iostream>

TimeSpan::TimeSpan(unsigned int h, unsigned int m, unsigned int s)
    :sec((m < 60 && s < 60)? h * secInHour + m * secInMinute + s :
                             throw std::invalid_argument("Invalid timespan inserted")){}

const unsigned int TimeSpan::secPerDay = secInHour * 24;

const unsigned int TimeSpan::secInHour = 3600;

const unsigned int TimeSpan::secInMinute = 60;

unsigned int TimeSpan::getTotalMinutes() const {return sec/secInMinute;}

unsigned int TimeSpan::getTotalSeconds() const {return sec;}

unsigned int TimeSpan::getHours() const {return sec/secInHour;}

unsigned int TimeSpan::getMinutes() const {return (sec % secInHour)/secInMinute;}

unsigned int TimeSpan::getSeconds() const {return sec % secInMinute; }

void TimeSpan::setTime(unsigned int h, unsigned int m, unsigned int s){
    sec = (m < 60 && s < 60)? h * secInHour + m * secInMinute + s :
                              throw std::invalid_argument("Invalid timespan setted");
}

bool TimeSpan::isNull() const {return sec;}

TimeSpan TimeSpan::operator+(const TimeSpan& time) const {
    unsigned int totSec = sec + time.sec;
    unsigned int h = totSec/secInHour, m = (totSec % secInHour)/secInMinute, s = totSec % secInMinute;
    return TimeSpan(h, m, s);
}

TimeSpan TimeSpan::operator-(const TimeSpan& time) const {
    int seconds = sec, tsec=time.sec;
    int totSec = (seconds - tsec);
    while(totSec < 0)
        totSec += (secPerDay); //module doesn't work with negative numbers
    unsigned int h = totSec/secInHour, m = (totSec % secInHour)/secInMinute, s = totSec % secInMinute;
    return TimeSpan(h, m, s);
}

TimeSpan TimeSpan::operator* (unsigned int n) const {
    unsigned int totSec = sec * n;
    unsigned int h = totSec/(secInHour), m = (totSec % secInHour)/secInMinute, s = totSec % secInMinute;
    return TimeSpan(h, m, s);
}

TimeSpan TimeSpan::operator/(unsigned int n) const {return (*this)*(1/n);}

double TimeSpan::operator/(const TimeSpan& time) const {return sec / time.sec;}

bool TimeSpan::operator==(const TimeSpan& time) const {return sec == time.sec;}

bool TimeSpan::operator!=(const TimeSpan& time) const {return sec != time.sec;}

bool TimeSpan::operator<(const TimeSpan& time) const {return sec < time.getTotalSeconds();}

bool TimeSpan::operator>(const TimeSpan& time) const {return sec > time.getTotalSeconds();}

bool TimeSpan::operator<=(const TimeSpan& time) const {return sec <= time.getTotalSeconds();}

bool TimeSpan::operator>=(const TimeSpan& time) const {return sec >= time.getTotalSeconds();}
