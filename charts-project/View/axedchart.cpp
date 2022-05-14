#include "axedchart.h"

axedChart::axedChart(QWidget *parent) : chart(parent)
{

}

QTime *axedChart::convertTime(TimeSpan *time)
{
    return new QTime(time->getHours(),time->getMinutes(), time->getSeconds());
}

QDateTime *axedChart::convertDateTime(DateTime *dateTime)
{
    Date d = dateTime->getDate();
    Time t = dateTime->getTime();
    return new QDateTime(QDate(d.getYear(), d.getMonth(), d.getDay()),*(convertTime(&t)));
}
