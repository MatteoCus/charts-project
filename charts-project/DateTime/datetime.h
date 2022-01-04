#ifndef DATETIME_H
#define DATETIME_H

#include "timespan.h"
#include "dateexception.h"
#include "date.h"

#define TimeStamp TimeSpan

class DateTime
{
private:
    Date date;
    TimeStamp time;                                                 //timespan used as timestamp
    DateTime(const Date& date, const TimeStamp& time);
    static const unsigned int hoursPerDay;
    void setTime(unsigned int hours, unsigned int minutes, unsigned int seconds);
    void setDate(unsigned int day, unsigned int month, unsigned int year);
public:
    DateTime();                                                     //constructs 1-1-2000 00:00
    DateTime(unsigned int day, unsigned int month, unsigned int year,
             unsigned int hours = 0, unsigned int minutes = 0, unsigned int seconds = 0);

    Date getDate() const;
    TimeStamp getTime() const;
    void setDateTime(unsigned int day, unsigned int month, unsigned int year,
                     unsigned int hours, unsigned int minutes, unsigned int seconds =0);
    DateTime operator+(const TimeSpan& time);
    DateTime operator-(const TimeSpan& time);
    bool operator==(const DateTime& dateTime) const;
    bool operator<(const DateTime& dateTime) const;
    bool operator>(const DateTime& dateTime) const;
    bool operator<=(const DateTime& dateTime) const;
    bool operator>=(const DateTime& dateTime) const;
};

#endif // DATETIME_H
