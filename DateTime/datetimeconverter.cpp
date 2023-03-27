#include "datetimeconverter.h"

DateTime DateTimeConverter::toDateTime(const QDateTime &dateTime)
{
    QDate date= dateTime.date();
    QTime time = dateTime.time();
    return DateTime(toDate(date),toTime(time));
}

QDateTime DateTimeConverter::toQDateTime(const DateTime &dateTime)
{
    Date date = dateTime.getDate();
    Time time = dateTime.getTime();
    return QDateTime(toQDate(date),toQTime(time));
}

Date DateTimeConverter::toDate(const QDate &date)
{
    return Date(date.day(),date.month(), date.year());
}

QDate DateTimeConverter::toQDate(const Date &date)
{
    return QDate(date.getYear(),date.getMonth(), date.getDay());
}

TimeSpan DateTimeConverter::toTime(const QTime &time)
{
    return Time(time.hour(), time.minute(), time.second());
}

QTime DateTimeConverter::toQTime(const TimeSpan &time)
{
    return QTime(time.getHours(),time.getMinutes(),time.getSeconds());
}
