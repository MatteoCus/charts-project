#ifndef DATETIME_H
#define DATETIME_H

#include "timespan.h"
#include "Date.h"
#include <stdexcept>

#define TimeStamp TimeSpan

class DateTime
{
private:
    Date date;
    TimeStamp time;                                                 //timespan used as timestamp
    static const unsigned int hoursPerDay;
    void setTime(const TimeStamp& time);
    void setDate(const Date& date);
public:
    DateTime();                                                     //constructs 1-1-2000 00:00
    DateTime(const Date& date, const TimeStamp& time);

    Date getDate() const;
    TimeStamp getTime() const;
    void setDateTime(const Date& date, const TimeStamp& time);
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
