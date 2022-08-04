#include "piechart.h"

void pieChart::connect()
{
    graph->addSeries(series);
    graph->legend()->hide();
}

void pieChart::setPieSliceStyle()
{
    unsigned int i = 0;
    for (auto it = slices.begin(); it != slices.end(); ++it)
    {
        (*it)->setLabelVisible();
        (*it)->setColor(colors.at(i));
        i++;
    }
}

pieChart::pieChart(QWidget *parent) : nonAxedChart(parent)
{
    series = new QPieSeries();
    graph->addSeries(series);

    colors.push_back(QColor(0, 128, 0));
    colors.push_back(QColor(2, 184, 2));
    colors.push_back(QColor(111, 214, 15));
    colors.push_back(QColor(191, 214, 15));
    colors.push_back(QColor(219, 216, 46));
}

void pieChart::addSeries(const std::vector<double> *values, bool repetition, bool endurance)
{
    double total = 0;

    if (values->size() > 0)
    {
        for (auto it = values->begin(); it != values->end(); ++it)
            total += *it;
    }

    slices.erase(slices.begin(), slices.end()--);

    if (!graph->series().empty())
        graph->removeSeries(series);

    if(!series->slices().empty())
        series->clear();

    if (total != 0)
    {

        if (repetition) //se allenamenti sono solo di ripetizione
        {
            if (values->at(0)/total)
                series->append("Rugby", values->at(0)/total);

            if(values->at(1)/total)
                series->append("Tennis", values->at(1)/total);
        }
        else
        {
            if(values->at(0)/total)
                series->append("Ciclismo", values->at(0)/total);
            if(values->at(1)/total)
                series->append("Corsa", values->at(1)/total);
            if(values->at(2)/total)
                series->append("Camminata", values->at(2)/total);

            if (!endurance)         //se allenamenti non sono solo di endurance
            {
                if(values->at(3)/total)
                    series->append("Rugby", values->at(3)/total);
                if(values->at(4)/total)
                    series->append("Tennis", values->at(4)/total);
            }
        }

        int size = series->slices().size();
        for (int i = 0; i < size; i++)
            slices.push_back(series->slices().at(i));
        connect();
        setPieSliceStyle();
    }
}
