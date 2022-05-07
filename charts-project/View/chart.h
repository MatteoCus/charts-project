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
#include <QCategoryAxis>

#include <vector>
#include "DateTime/datetime.h"

QT_CHARTS_USE_NAMESPACE

class chart : public QWidget
{
    Q_OBJECT
private:
    QChart * graph;
public:
    explicit chart(QWidget *parent = nullptr);
    virtual QChart *getChart() const;
    virtual void connect(QChart*  chart) = 0;
    virtual void addAxes(const std::string& x, const std::string& y) = 0;
    virtual void addSeries(const std::vector<int>* values, const std::vector<DateTime*>* start) = 0;
};

#endif // CHART_H
