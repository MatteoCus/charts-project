#ifndef LINECHART_H
#define LINECHART_H

#include "chart.h"
#include <QWidget>

class lineChart : public chart
{

private:
    QLineSeries* series;
    QCategoryAxis* axisX;
    QValueAxis* axisY;
    QPen pen;

public:
    lineChart(QWidget *parent = nullptr);
    void connect(QChart*  chart) override;
    void addAxes(const std::string& x, const std::string& y) override;
    void addSeries(const std::vector<int>* values, const std::vector<DateTime*>* start) override;
};

#endif // LINECHART_H
