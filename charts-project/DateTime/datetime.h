#ifndef DATETIME_H
#define DATETIME_H

#include "timespan.h"
#include "date.h"
#include <stdexcept>

#define Time TimeSpan

class DateTime
{
private:
    Date date;
    Time time;                                                 //timespan used as Time
    static const unsigned int hoursPerDay;
    void setTime(const Time& time);
    void setDate(const Date& date);
public:
    DateTime();
    DateTime(const Date& date, const Time& time);

    Date getDate() const;
    Time getTime() const;
    std::string toString() const;
    void setDateTime(const Date& date, const Time& time);
    DateTime operator+(const TimeSpan& time) const;
    DateTime operator-(const TimeSpan& time) const;
    bool operator==(const DateTime& dateTime) const;
    bool operator!=(const DateTime& dateTime) const;
    bool operator<(const DateTime& dateTime) const;
    bool operator>(const DateTime& dateTime) const;
    bool operator<=(const DateTime& dateTime) const;
    bool operator>=(const DateTime& dateTime) const;
};

#endif // DATETIME_H
