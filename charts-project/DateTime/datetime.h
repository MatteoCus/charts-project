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
    TimeStamp time;     //timespan used ad timestamp
public:
    DateTime();
    DateTime(unsigned int day, unsigned int month, unsigned int year,
             unsigned int hours = 0, unsigned int minutes = 0, unsigned int seconds = 0);

    Date getDate() const;
    TimeStamp getTime() const;
    DateTime getDateTime() const;
    void setTime(unsigned int hours, unsigned int minutes, unsigned int seconds);
    void setDate(unsigned int day, unsigned int month, unsigned int year);
    DateTime operator+(const DateTime&);
    DateTime operator+(const TimeSpan&);
    DateTime operator-(const DateTime&);
    DateTime operator-(const TimeSpan&);
    bool operator==(const DateTime&) const;
    bool operator<(const DateTime&) const;
    bool operator>(const DateTime&) const;
    bool operator<=(const DateTime&) const;
    bool operator>=(const DateTime&) const;
};

#endif // DATETIME_H
