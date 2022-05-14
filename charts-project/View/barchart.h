#ifndef BARCHART_H
#define BARCHART_H

#include "axedchart.h"
#include <QWidget>

class barChart : public axedChart
{

protected:
    QBarSeries* series;
    QBarSet* set;
    QStringList categories;
    QBarCategoryAxis* axisX;
    QAbstractAxis* axisY;
    QValueAxis* axisYInt;
    QDateTimeAxis* axisYDateTime;

    void connect() override;

public:
    barChart(QWidget *parent = nullptr);
    void setAxes(const std::string& x, const std::string& y) override;
    void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) override;
};

#endif // BARCHART_H
