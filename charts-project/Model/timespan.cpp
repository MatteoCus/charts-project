#include "timespan.h"

TimeSpan::TimeSpan(unsigned int h, unsigned int m, unsigned int s, bool valid)
    :sec(h * secInHour + m * secInMinute + s), valid(valid){}

TimeSpan::TimeSpan(const QTime& time)
    :sec (!time.isValid()? throw std::invalid_argument("Invalid value of time passed to construct TimeSpan")
                         : time.hour() * secInHour + time.minute() * secInMinute + time.second()),
    valid(true){}

const unsigned int TimeSpan::secInHour = 3600;

const unsigned int TimeSpan::secInMinute = 60;

unsigned int TimeSpan::getTotalMinutes() const {return sec/secInMinute;}

unsigned int TimeSpan::getTotalSeconds() const {return sec;}

unsigned int TimeSpan::getHours() const {return sec/secInHour;}

unsigned int TimeSpan::getMinutes() const {return (sec-(getHours() * secInHour))/secInMinute;}

unsigned int TimeSpan::getSeconds() const {return (sec - (getHours() * secInHour) - (getMinutes() * secInMinute)); }

bool TimeSpan::isValid() const {return valid;}

TimeSpan TimeSpan::operator+(const TimeSpan& time) const {return sec + time.sec; }

TimeSpan TimeSpan::operator-(const TimeSpan& time) const {return sec - time.sec;}

TimeSpan TimeSpan::operator* (double n) const {return TimeSpan()+(sec * n);}

TimeSpan TimeSpan::operator/(double n) const {return TimeSpan() +(sec / n);}

double TimeSpan::operator/(const TimeSpan& time) const {return sec / time.sec;}

bool TimeSpan::operator==(const TimeSpan& time) const {return sec == time.sec;}
