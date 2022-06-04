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

    if (!graph->series().empty())
        graph->removeSeries(series);

    if (!series->barSets().empty())
        series->remove(set);

    set = new QBarSet("", this);
    set->setColor(QColor(0, 128, 0));

    axisX->clear();
    categories.clear();

    axisY->setTitleVisible(false);
    axisY->setVisible(false);

    if(values->size() > 0)
    {
        if(duration)
        {
            axisY = axisYDateTime;

            QDateTime* max = new QDateTime();
            unsigned int mx = 0;
            for(unsigned int i = 0; i < values->size(); ++i)
            {
                categories.append(QString::fromStdString((*start)[i]->toString()));

                unsigned int sec = (*values)[i];
                unsigned int h = sec / 3600;
                unsigned int m = (sec - (3600 * h))/ 60;
                unsigned int s = (sec - (3600 * h) - (60 * m)) % 60;

                QDateTime aux = QDateTime(QDate(1970,1,2), QTime(h,m,s));

                if(mx < sec)
                {
                    delete max;
                    max = new QDateTime(aux);
                    mx = sec;
                }
                int msSinceEpoch = aux.toMSecsSinceEpoch();
                *set<<msSinceEpoch;

            }
            axisYDateTime->setRange(QDateTime(QDate(1970,1,2),QTime(0,0)),*max);
            delete max;
        }
        else
        {
            axisY = axisYInt;

            double max = (*values)[0];
            for(unsigned int i = 0; i < values->size(); ++i)
            {
                categories.append(QString::fromStdString((*start)[i]->toString()));
                if (max < (*values)[i])
                    max = (*values)[i];
                *set<<(*values)[i];
            }
            axisYInt->setMin(0);
            axisYInt->setMax(max);
        }
        axisY->setVisible();
        axisY->setTitleVisible();

        axisX->setTitleVisible();
        axisX->setVisible();

        series->append(set);
        axisX->append(categories);
        connect();
    }
    else
    {
        axisX->setTitleVisible(false);
        axisX->setVisible(false);
    }
}

