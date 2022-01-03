#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <stdexcept>

class TimeSpan
{
private:
    unsigned int sec;
    static const unsigned int secPerDay;
    static const unsigned int secInHour;
    static const unsigned int secInMinute;
public:
    TimeSpan(unsigned int hours = 0, unsigned int minutes = 0, unsigned int seconds = 0);

    unsigned int getHours() const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;
    void setTime(unsigned int, unsigned int =0, unsigned int =0);
    unsigned int getTotalMinutes() const;
    unsigned int getTotalSeconds() const;
    bool isNull() const;
    TimeSpan operator+(const TimeSpan&) const;
    TimeSpan operator-(const TimeSpan&) const;
    TimeSpan operator* (unsigned int) const;
    TimeSpan operator/(unsigned int) const;
    double operator/(const TimeSpan& ) const;
    bool operator==(const TimeSpan&) const;
    bool operator!=(const TimeSpan&) const;
    bool operator<(const TimeSpan&) const;
    bool operator>(const TimeSpan&) const;
    bool operator<=(const TimeSpan&) const;
    bool operator>=(const TimeSpan&) const;
};

#endif // TIMESPAN_H
