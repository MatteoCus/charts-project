#include "linechart.h"

lineChart::lineChart(QWidget *parent) : chart(parent)
{
    series = new QLineSeries(this);

    axisX = new QCategoryAxis(this);
    //axisX->setFormat("dd.MM.yyyy");

    axisY = new QValueAxis(this);
    axisY->setLabelFormat("%i");

    pen = QPen(QRgb(0xc26110));
    pen.setWidth(3);
    series->setPen(pen);
}

void lineChart::connect(QChart *chart)
{
    chart->setAxisX(axisX,series);
    chart->setAxisY(axisY,series);
    chart->legend()->hide();
}

void lineChart::addAxes(const std::string &x, const std::string &y)
{
    axisX->setTitleText(QString::fromStdString(x));
    axisY->setTitleText(QString::fromStdString(y));
}

void lineChart::addSeries(const std::vector<int> *values, const std::vector<DateTime *> *start)
{
    if (values->size() != start->size())
        throw std::runtime_error("Impossibile visualizzare i dati!");

    series->clear();
    series->append(0,0);

    for(unsigned int i = 0; i < values->size(); ++i)
    {
        series->append(i+1,(*values)[i]);
        axisX->append(QString::fromStdString((*start)[i]->toString()), i+1);
    }
}
