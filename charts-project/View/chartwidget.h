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
#include <./Model/endurance.h>
#include <./Model/repetition.h>
#include "linechart.h"

class chartWidget : public QWidget
{
    Q_OBJECT
private:
    chart* visibleChart;
    lineChart* line;


    const std::list<const Training*>* trainings;

    QChartView *chartView;
    QComboBox* chartBox;
    QComboBox* dataBox;
    QVBoxLayout * mainLayout;

    void addDefaultChart(QVBoxLayout * mainLayout);
    void addControls(QVBoxLayout * mainLayout);
    void hideDataEntry(int x);
    void unhideDataEntry(int x);

    void checkDataBoxValue(bool enduranceFound, bool repetitionFound);

    void checkDataBoxValues();

public:
    explicit chartWidget(QWidget *parent = nullptr);
    void showData(const std::string& chart, const std::string& data);
    void setData(const std::list<const Training *> *data);

signals:

};

#endif // CHARTWIDGET_H
