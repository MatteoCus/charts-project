#ifndef BARCHART_H
#define BARCHART_H

#include "chart.h"
#include <QWidget>

class barChart : public chart
{

private:
    QBarSeries* series;
    QBarSet* set;
    QDateTimeAxis* axisX;
    QAbstractAxis* axisY;
    QValueAxis* axisYInt;
    QDateTimeAxis* axisYDateTime;

protected:
    void connect() override;
public:
    barChart(QWidget *parent = nullptr);
    void addAxes(const std::string& x, const std::string& y) override;
    void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) override;
};

#endif // BARCHART_H
