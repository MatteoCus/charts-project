#ifndef DateTimeConverter_H
#define DateTimeConverter_H

#include "QDateTime"
#include "datetime.h"

class DateTimeConverter
{
public:
    explicit DateTimeConverter() = delete;
    explicit DateTimeConverter(const DateTimeConverter&) = delete;

    static DateTime toDateTime(const QDateTime& dateTime) ;
    static QDateTime toQDateTime(const DateTime& dateTime) ;
    static Date toDate(const QDate& date) ;
    static QDate toQDate(const Date& date) ;
    static Time toTime(const QTime& time) ;
    static QTime toQTime(const TimeSpan& time) ;
};

#endif // DateTimeConverter_H
