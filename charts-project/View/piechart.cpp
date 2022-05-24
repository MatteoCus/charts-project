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
        (*it)->setColor(colors[i]);
        i++;
    }
}

pieChart::pieChart(QWidget *parent) : nonAxedChart(parent)
{
    series = new QPieSeries();
    graph->addSeries(series);

    colors.push_back(QColor(201, 70, 26));
    colors.push_back(QColor(194,97,16));
    colors.push_back(QColor(201, 140, 26));
    colors.push_back(QColor(201, 193, 26));
    colors.push_back(QColor(178, 201, 26));
}

void pieChart::addSeries(const std::vector<double> *values, bool repetition, bool endurance)
{
    double total = 0;
    for (auto it = values->begin(); it != values->end(); ++it)
        total += *it;

    if (total != 0)
    {
        slices.erase(slices.begin(), slices.end()--);
        graph->removeSeries(series);
        series->clear();

        if (repetition) //se allenamenti sono solo di ripetizione
        {
            if ((*values)[0]/total)
                series->append("Rugby", (*values)[0]/total);

            if((*values)[1]/total)
                series->append("Tennis", (*values)[1]/total);
        }
        else
        {
            if((*values)[0]/total)
                series->append("Ciclismo", (*values)[0]/total);
            if((*values)[1]/total)
                series->append("Corsa", (*values)[1]/total);
            if((*values)[2]/total)
                series->append("Camminata", (*values)[2]/total);

            if (!endurance)         //se allenamenti non sono solo di endurance
            {
                if((*values)[3]/total)
                    series->append("Rugby", (*values)[3]/total);
                if((*values)[4]/total)
                    series->append("Tennis", (*values)[4]/total);
            }
        }

    }
    else throw std::runtime_error("Errore durante la visualizzazione dei dati!");

    int size = series->slices().size();
    for (int i = 0; i < size; i++)
        slices.push_back(series->slices().at(i));
    connect();
    setPieSliceStyle();
}
