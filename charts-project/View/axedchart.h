#ifndef AXEDCHART_H
#define AXEDCHART_H

#include "chart.h"


class axedChart : public chart
{
    Q_OBJECT
public:
    explicit axedChart(QWidget *parent = nullptr);
    virtual void setAxes(const std::string& x, const std::string& y) = 0;
    virtual void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) = 0;
};

#endif // AXEDCHART_H
