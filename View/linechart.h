#ifndef LINECHART_H
#define LINECHART_H

#include "axedchart.h"
#include <QWidget>

class lineChart : public axedChart
{

protected:
    QLineSeries* series;
    QDateTimeAxis* axisX;
    QAbstractAxis* axisY;
    QValueAxis* axisYInt;
    QDateTimeAxis* axisYDateTime;
    QPen pen;

    void connect() override;

public:
    lineChart(QWidget *parent = nullptr);
    void setAxes(const std::string& x, const std::string& y) override;
    void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) override;
};

#endif // LINECHART_H
