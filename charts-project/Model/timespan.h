#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <stdexcept>

class TimeSpan
{
private:
    unsigned int sec;

public:
    TimeSpan(unsigned int = 0, unsigned int = 0, unsigned int = 0);

    static const unsigned int secInHour;
    static const unsigned int secInMinute;
    unsigned int getHours() const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;
    unsigned int getTotalMinutes() const;
    unsigned int getTotalSeconds() const;
    bool isNull() const;
    TimeSpan operator+(const TimeSpan&) const;
    TimeSpan operator-(const TimeSpan&) const;
    TimeSpan operator* (double) const;
    TimeSpan operator/(double) const;
    double operator/(const TimeSpan& ) const;
    bool operator==(const TimeSpan&) const;
};

#endif // TIMESPAN_H
