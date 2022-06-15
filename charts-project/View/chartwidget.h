#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsEffect>
#include <QSizePolicy>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>
#include <QFont>
#include <./DateTime/datetime.h>
#include <./Model/walk.h>
#include <./Model/cycling.h>
#include <./Model/run.h>
#include <./Model/tennis.h>
#include <./Model/rugby.h>
#include "linechart.h"
#include "barchart.h"
#include "piechart.h"

class chartWidget : public QWidget
{
    Q_OBJECT
private:
    chart* visibleChart;
    lineChart* line;
    barChart* bar;
    pieChart* pie;


    const std::list<Training*>* trainings;

    QComboBox* chartBox;
    QComboBox* dataBox;
    QVBoxLayout * mainLayout;

    void addDefaultChart();
    void addControls();
    void hideDataBoxEntry(int x);
    void unhideDataBoxEntry(int x);

    void checkDataBoxValues();

    void extractValues(std::vector<double>& values, std::vector<DateTime*>& start, const std::string& data);

    void extractValues(std::vector<double>& values, const std::string& data);

public:
    explicit chartWidget(QWidget *parent = nullptr);
    void showData(std::string chart = "", std::string data = "");
    void setData(const std::list<Training *> *data);
    chart* getVisibleChart() const;
    void setChartsSize(int w, int h);
    chartWidget *clone() const;

    
signals:

};

#endif // CHARTWIDGET_H
