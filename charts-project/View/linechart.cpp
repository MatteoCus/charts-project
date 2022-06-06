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

    pen = QPen(QRgb(0x008000));
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

    if (!graph->series().empty())
        graph->removeSeries(series);

    series->clear();
    //axisX->setTickCount(values->size() != 1? values->size() : 2);

    axisY->setTitleVisible(false);
    axisY->setVisible(false);

    if(values->size() > 0)
    {

        if(duration)
        {
            axisY = axisYDateTime;

            QDateTime* max = new QDateTime();
            unsigned int mx = 0;

            if (start->size() > 1)
                axisX->setRange(*convertDateTime((*start)[0]),*convertDateTime((*start)[start->size() -1]));
            else
            {
                axisX->setRange((*convertDateTime((*start)[0])).addDays(-1),*convertDateTime((*start)[0]));
                series->append((*convertDateTime((*start)[0])).addDays(-1).toMSecsSinceEpoch(), QDateTime(QDate(1970,1,1),QTime(0,0)).toMSecsSinceEpoch());
            }

            for(unsigned int i = 0; i < values->size(); ++i)
            {
                unsigned int sec = (*values)[i];
                unsigned int h = sec / 3600;
                unsigned int m = (sec - (3600 * h))/ 60;
                unsigned int s = (sec - (3600 * h) - (60 * m)) % 60;
                QDateTime aux = QDateTime(QDate(1970,1,1), QTime(h,m,s));

                if(mx < sec)
                {
                    delete max;
                    max = new QDateTime(aux);
                    mx = sec;
                }

                series->append(convertDateTime((*start)[i])->toMSecsSinceEpoch(),aux.toMSecsSinceEpoch());
            }
            axisYDateTime->setRange(QDateTime(QDate(1970,1,1),QTime(0,0)),*max);
            delete max;

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
            axisYInt->setRange(0,max);
        }
        axisY->setVisible();
        axisY->setTitleVisible();


        axisX->setVisible();
        axisX->setTitleVisible();

        connect();
    }
    else
    {
        axisX->setTitleVisible(false);
        axisX->setVisible(false);
    }
}
