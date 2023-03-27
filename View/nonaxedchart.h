#ifndef NONAXEDCHART_H
#define NONAXEDCHART_H

#include "chart.h"
#include <QWidget>

class nonAxedChart : public chart
{
public:
    nonAxedChart(QWidget *parent = nullptr);
    virtual void addSeries(const std::vector<double>* values, bool repetition, bool endurance) = 0;
};

#endif // NONAXEDCHART_H
