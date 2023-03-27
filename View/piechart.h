#ifndef PIECHART_H
#define PIECHART_H

#include "nonaxedchart.h"
#include <QWidget>

class pieChart : public nonAxedChart
{
protected:
    QPieSeries * series;
    std::vector<QPieSlice *> slices;
    std::vector<QColor> colors;

    void connect() override;
    void setPieSliceStyle();
public:
    pieChart(QWidget *parent = nullptr);
    void addSeries(const std::vector<double>* values, bool repetition, bool endurance) override;
};

#endif // PIECHART_H
