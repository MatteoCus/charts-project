#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <QtCharts>
#include <QLineSeries>
#include <QBarSeries>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QBarSet>
#include <QCategoryAxis>
#include <QDateTimeAxis>
#include <DateTime/datetime.h>

#include <vector>
QT_CHARTS_USE_NAMESPACE

class chart : public QWidget
{
protected:
    QChartView *chartView;
    QChart * graph;
    virtual void connect() = 0;
public:
    explicit chart(QWidget *parent = nullptr);
    QChartView *getChartView() const;
};

#endif // CHART_H
