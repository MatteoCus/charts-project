#include "barchart.h"
#include <iostream>
using namespace std;

barChart::barChart(QWidget *parent) : chart(parent)
{
    graph->legend()->hide();
    set = new QBarSet("", this);
    series = new QBarSeries(this);
    graph->addSeries(series);

    axisX = new QDateTimeAxis(this);
    axisX->setFormat("dd-MM-yyyy hh:mm");

    axisYDateTime = new QDateTimeAxis(this);
    axisYDateTime->setFormat("hh:mm:ss");

    axisYInt = new QValueAxis(this);
    axisYInt->setMin(0);

    axisY = axisYDateTime;
}

void barChart::connect()
{
    graph->addSeries(series);
    graph->setAxisX(axisX,series);
    graph->setAxisY(axisY,series);
}

void barChart::addAxes(const std::string &x, const std::string &y)
{
    axisX->setTitleText(QString::fromStdString(x));
    axisY->setTitleText(QString::fromStdString(y));
}

void barChart::addSeries(const std::vector<double> *values, const std::vector<DateTime *> *start, bool duration)
{
    if (values->size() != start->size())
        throw std::runtime_error("Impossibile visualizzare i dati!");

    graph->removeSeries(series);
    series->remove(set);
    set = new QBarSet("", this);
    axisX->setTickCount(values->size() > 1? values->size() : 2);

    if(duration)
    {
        axisY->setTitleVisible(false);
        axisY->setVisible(false);

        axisY = axisYDateTime;

        axisY->setVisible(true);
        axisY->setTitleVisible(true);

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
            cout<<sec<<" "<<aux->toMSecsSinceEpoch()<<endl;

            *set<<aux->toMSecsSinceEpoch();
            delete aux;
        }
        axisYDateTime->setMin(QDateTime(QDate(1970,1,1),QTime(0,0)));
    }
    else
    {
        axisY->setTitleVisible(false);
        axisY->setVisible(false);

        axisY = axisYInt;

        axisY->setVisible(true);
        axisY->setTitleVisible(true);

        double max = (*values)[0];
        for(unsigned int i = 0; i < values->size(); ++i)
        {
            if (max < (*values)[i])
                max = (*values)[i];
            *set<<(*values)[i];
        }
        axisYInt->setMin(0);
        axisYInt->setMax(max);
    }

    axisX->setMin(*convertDateTime((*start)[0]));
    axisX->setMax(*convertDateTime((*start)[start->size() -1]));
    connect();
}
