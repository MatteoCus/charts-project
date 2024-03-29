#include "linechart.h"

lineChart::lineChart(QWidget *parent) : axedChart(parent)
{
    graph->legend()->hide();
    series = new QLineSeries(this);
    graph->addSeries(series);

    axisX = new QDateTimeAxis(this);
    axisX->setFormat("dd-MM-yyyy hh:mm");

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

void lineChart::addSeries(const std::vector<double> *values, const std::vector<DateTime*> *start, bool duration)
{
    if (values->size() != start->size())
        throw std::runtime_error("Tentativo di visualizzazione di dati non congrui nelle dimensioni!");

    if (!graph->series().empty())
        graph->removeSeries(series);

    series->clear();

    axisY->setTitleVisible(false);
    axisY->setVisible(false);

    if(values->size() > 0)
    {
        if (start->size() > 1)
            axisX->setRange(DateTimeConverter::toQDateTime(*start->at(0)),DateTimeConverter::toQDateTime(*start->at(start->size() -1)));
        else
            axisX->setRange(DateTimeConverter::toQDateTime(*start->at(0)).addDays(-1),DateTimeConverter::toQDateTime(*start->at(0)));

        if(duration)
        {
            axisY = axisYDateTime;

            QDateTime* max = new QDateTime();
            unsigned int mx = 0;

            if(start->size() == 1)
                series->append(DateTimeConverter::toQDateTime(*start->at(0)).addDays(-1).toMSecsSinceEpoch(), QDateTime(QDate(1970,1,1),QTime(0,0)).toMSecsSinceEpoch());

            for(unsigned int i = 0; i < values->size(); ++i)
            {
                unsigned int sec = values->at(i);
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

                series->append(DateTimeConverter::toQDateTime(*start->at(i)).toMSecsSinceEpoch(),aux.toMSecsSinceEpoch());
            }
            axisYDateTime->setRange(QDateTime(QDate(1970,1,1),QTime(0,0)),*max);
            delete max;

        }
        else
        {
            axisY = axisYInt;

            if(start->size() == 1)
                series->append(DateTimeConverter::toQDateTime(*start->at(0)).addDays(-1).toMSecsSinceEpoch(), 0);

            double max = values->at(0);
            for(unsigned int i = 0; i < values->size(); i++)
            {
                if (max < values->at(i))
                    max = values->at(i);
                series->append(DateTimeConverter::toQDateTime(*start->at(i)).toMSecsSinceEpoch(),values->at(i));
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
