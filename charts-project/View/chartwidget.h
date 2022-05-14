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


    const std::list<const Training*>* trainings;

    QComboBox* chartBox;
    QComboBox* dataBox;
    QVBoxLayout * mainLayout;
    QHBoxLayout * controlsLayout;

    void addDefaultChart(QVBoxLayout * mainLayout);
    void addControls(QVBoxLayout * mainLayout);
    void hideDataEntry(int x);
    void unhideDataEntry(int x);

    void checkDataBoxValue(bool enduranceFound, bool repetitionFound);

    void checkDataBoxValues();

    void extractValues1(std::vector<double>& values, std::vector<DateTime*>& start, const std::string& data);

    void extractValues2(std::vector<double>& values, const std::string& data);

public:
    explicit chartWidget(QWidget *parent = nullptr);
    void showData(std::string chart = "", std::string data = "");
    void setData(const std::list<const Training *> *data);

signals:

};

#endif // CHARTWIDGET_H
