#include "axedchart.h"

axedChart::axedChart(QWidget *parent) : chart(parent)
{
    axisYDateTime = new QDateTimeAxis(this);
    axisYDateTime->setFormat("hh:mm:ss");

    axisYInt = new QValueAxis(this);
    axisYInt->setMin(0);

    axisY = axisYDateTime;
}
