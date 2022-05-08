#ifndef LINECHART_H
#define LINECHART_H

#include "chart.h"
#include <QWidget>

class lineChart : public chart
{

private:
    QLineSeries* series;
    QDateTimeAxis* axisX;
    QAbstractAxis* axisY;
    QValueAxis* axisYInt;
    QDateTimeAxis* axisYDateTime;
    QPen pen;

protected:
    void connect() override;

public:
    lineChart(QWidget *parent = nullptr);
    void addAxes(const std::string& x, const std::string& y) override;
    void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) override;
};

#endif // LINECHART_H
