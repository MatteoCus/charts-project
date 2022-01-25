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

class chartWidget : public QWidget
{
    Q_OBJECT
    void addDefaultChart(QVBoxLayout * mainLayout);

    void addControls(QVBoxLayout * mainLayout);

public:
    explicit chartWidget(QWidget *parent = nullptr);

signals:

};

#endif // CHARTWIDGET_H
