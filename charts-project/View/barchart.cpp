#include "barchart.h"
#include <iostream>
using namespace std;

barChart::barChart(QWidget *parent) : axedChart(parent)
{
    graph->legend()->hide();
    set = new QBarSet("", this);
    series = new QBarSeries(this);
    series->append(set);
    graph->addSeries(series);

    categories << "Non c'è alcun dato per ora";

    axisX = new QBarCategoryAxis(this);
    axisX->append(categories);

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

void barChart::setAxes(const std::string &x, const std::string &y)
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
    set->setColor(QColor(194,97,16));

    axisX->clear();
    categories.clear();

    axisY->setTitleVisible(false);
    axisY->setVisible(false);

    if(duration)
    {
        axisY = axisYDateTime;

        unsigned int mx = (*values)[0];
        for(unsigned int i = 0; i < values->size(); ++i)
        {
            categories.append(QString::fromStdString((*start)[i]->getDate().toString()));

            unsigned int sec = (*values)[i];
            unsigned int h = sec / 3600;
            unsigned int m = (sec - (3600 * h))/ 60;
            unsigned int s = (sec - (3600 * h) - (60 * m)) % 60;

            QDateTime *aux = new QDateTime(QDate(1970,1,2), QTime(h,m,s));


            if(mx < sec)
            {
                axisYDateTime->setMax(*aux);
                mx = sec;
            }
            int msSinceEpoch = aux->toMSecsSinceEpoch();
            *set<<msSinceEpoch;
            delete aux;
        }
        axisYDateTime->setMin(QDateTime(QDate(1970,1,2),QTime(0,0)));
    }
    else
    {
        axisY = axisYInt;

        double max = (*values)[0];
        for(unsigned int i = 0; i < values->size(); ++i)
        {
            categories.append(QString::fromStdString((*start)[i]->getDate().toString()));
            if (max < (*values)[i])
                max = (*values)[i];
            *set<<(*values)[i];
        }
        axisYInt->setMin(0);
        axisYInt->setMax(max);
    }
    axisY->setVisible(true);
    axisY->setTitleVisible(true);

    series->append(set);
    axisX->append(categories);
    connect();
}

