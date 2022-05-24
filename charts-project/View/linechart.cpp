#include "linechart.h"
#include <iostream>
using namespace std;

lineChart::lineChart(QWidget *parent) : axedChart(parent)
{
    graph->legend()->hide();
    series = new QLineSeries(this);
    graph->addSeries(series);

    axisX = new QDateTimeAxis(this);
    axisX->setFormat("dd-MM-yyyy hh:mm");

    axisYDateTime = new QDateTimeAxis(this);
    axisYDateTime->setFormat("hh:mm:ss");

    axisYInt = new QValueAxis(this);
    axisYInt->setMin(0);

    axisY = axisYDateTime;

    pen = QPen(QRgb(0xc26110));
    pen.setWidth(3);
    series->setPen(pen);
}

void lineChart::connect()
{
    graph->addSeries(series);
    graph->setAxisX(axisX,series);
    graph->setAxisY(axisY,series);
}

void lineChart::setAxes(const std::string &x, const std::string &y)
{
    axisX->setTitleText(QString::fromStdString(x));
    axisY->setTitleText(QString::fromStdString(y));
}

void lineChart::addSeries(const std::vector<double> *values, const std::vector<DateTime *> *start, bool duration)
{
    if (values->size() != start->size())
        throw std::runtime_error("Impossibile visualizzare i dati!");

    series->clear();
    graph->removeSeries(series);
    axisX->setTickCount(values->size() > 1? values->size() : 2);

    axisY->setTitleVisible(false);
    axisY->setVisible(false);

    if(duration)
    {
        axisY = axisYDateTime;

        unsigned int mx = (*values)[0];
        for(unsigned int i = 0; i < values->size(); ++i)
        {
            unsigned int sec = (*values)[i];
            unsigned int h = sec / 3600;
            unsigned int m = (sec - (3600 * h))/ 60;
            unsigned int s = (sec - (3600 * h) - (60 * m)) % 60;
            QDateTime *aux = new QDateTime(QDate(1970,1,1), QTime(h,m,s));

            if(mx < sec)
            {
                axisYDateTime->setMax((*aux));
                mx = sec;
            }

            series->append(convertDateTime((*start)[i])->toMSecsSinceEpoch(),aux->toMSecsSinceEpoch());
        }
        axisYDateTime->setMin(QDateTime(QDate(1970,1,1),QTime(0,0)));

    }
    else
    {
        axisY = axisYInt;

        double max = (*values)[0];
        for(unsigned int i = 0; i < values->size(); ++i)
        {
            if (max < (*values)[i])
                max = (*values)[i];
            series->append(convertDateTime((*start)[i])->toMSecsSinceEpoch(),(*values)[i]);
        }
        axisYInt->setMin(0);
        axisYInt->setMax(max);
    }
    axisY->setVisible(true);
    axisY->setTitleVisible(true);

    axisX->setMin(*convertDateTime((*start)[0]));
    axisX->setMax(*convertDateTime((*start)[start->size() -1]));

    connect();
}
