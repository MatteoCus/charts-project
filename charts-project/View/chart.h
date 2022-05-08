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

#include <vector>
#include "DateTime/datetime.h"

QT_CHARTS_USE_NAMESPACE

class chart : public QWidget
{
    Q_OBJECT
protected:
    QChartView *chartView;
    QChart * graph;
    virtual void connect() = 0;
    static QTime *convertTime(Time* time);
    static QDateTime *convertDateTime(DateTime* dateTime);
public:
    explicit chart(QWidget *parent = nullptr);
    virtual QChartView *getChartView() const;
    virtual void addAxes(const std::string& x, const std::string& y) = 0;
    virtual void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) = 0;
};

#endif // CHART_H
