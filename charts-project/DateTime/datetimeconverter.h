#ifndef DateTimeConverter_H
#define DateTimeConverter_H

#include "QDateTime"
#include "datetime.h"

class DateTimeConverter
{
public:
    DateTimeConverter();
    DateTime toDateTime(const QDateTime& dateTime) const;
    QDateTime toQDateTime(const DateTime& dateTime) const;
    Date toDate(const QDate& date) const;
    QDate toQDate(const Date& date) const;
    Time toTime(const QTime& time) const;
    QTime toQTime(const TimeSpan& time) const;
};

#endif // DateTimeConverter_H
