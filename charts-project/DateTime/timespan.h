#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <stdexcept>
#include "string"

class TimeSpan {
private:
    unsigned int sec;
    static const unsigned int secPerDay;
    static const unsigned int secInHour;
    static const unsigned int secInMinute;

public:
    explicit TimeSpan(unsigned int hours = 0, unsigned int minutes = 0,
                      unsigned int seconds = 0);

    unsigned int getHours() const;
    unsigned int getMinutes() const;
    unsigned int getSeconds() const;
    void setTime(unsigned int hours, unsigned int minutes = 0,
                 unsigned int seconds = 0);
    unsigned int getTotalMinutes() const;
    unsigned int getTotalSeconds() const;
    bool isNull() const;
    std::string toString() const;
    TimeSpan operator+(const TimeSpan &time) const;
    TimeSpan operator-(const TimeSpan &time) const;
    TimeSpan operator*(unsigned int n) const;
    TimeSpan operator/(double n) const;
    double operator/(const TimeSpan &time) const;
    bool operator==(const TimeSpan &time) const;
    bool operator!=(const TimeSpan &time) const;
    bool operator<(const TimeSpan &time) const;
    bool operator>(const TimeSpan &time) const;
    bool operator<=(const TimeSpan &time) const;
    bool operator>=(const TimeSpan &time) const;
};

#endif // TIMESPAN_H
