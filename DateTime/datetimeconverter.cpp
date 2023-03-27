#include "datetimeconverter.h"

DateTimeConverter::DateTimeConverter()
{}

DateTime DateTimeConverter::toDateTime(const QDateTime &dateTime) const
{
    QDate date= dateTime.date();
    QTime time = dateTime.time();
    return DateTime(toDate(date),toTime(time));
}

QDateTime DateTimeConverter::toQDateTime(const DateTime &dateTime) const
{
    Date date = dateTime.getDate();
    Time time = dateTime.getTime();
    return QDateTime(toQDate(date),toQTime(time));
}

Date DateTimeConverter::toDate(const QDate &date) const
{
    return Date(date.day(),date.month(), date.year());
}

QDate DateTimeConverter::toQDate(const Date &date) const
{
    return QDate(date.getYear(),date.getMonth(), date.getDay());
}

TimeSpan DateTimeConverter::toTime(const QTime &time) const
{
    return Time(time.hour(), time.minute(), time.second());
}

QTime DateTimeConverter::toQTime(const TimeSpan &time) const
{
    return QTime(time.getHours(),time.getMinutes(),time.getSeconds());
}
