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
#include <QFont>

class chartWidget : public QWidget
{
    Q_OBJECT
private:
    QChart *chart;
    QLineSeries *lineSeries;
    QBarSeries *barSeries;
    QSplineSeries* splineSeries;
    QDateTimeAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView;
    QComboBox* chartBox;
    QComboBox* dataBox;
    QVBoxLayout * mainLayout;

    void addDefaultChart(QVBoxLayout * mainLayout);
    void addControls(QVBoxLayout * mainLayout);

public:
    explicit chartWidget(QWidget *parent = nullptr);

signals:

};

#endif // CHARTWIDGET_H
