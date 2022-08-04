#ifndef NONAXEDCHART_H
#define NONAXEDCHART_H

#include "chart.h"
#include <QWidget>

class nonAxedChart : public chart
{
public:
    /**
     * @brief nonAxedChart:     costruttore di axedChart, un widget per la gestione di un grafico senza assi
     * @param parent:           widget genitore
     */
    nonAxedChart(QWidget *parent = nullptr);

    /**
     * @brief addSeries:        gestisce l'aggiunta di nuovi dati nel grafico, eliminando i vecchi
     * @param values:           valori da visualizzare
     * @param repetition:       booleano che indica la presenza esclusiva (o meno) di allenamenti di ripetizione
     * @param endurance:        booleano che indica la presenza esclusiva (o meno) di allenamenti di resistenza
     */
    virtual void addSeries(const std::vector<double>* values, bool repetition, bool endurance) = 0;
};

#endif // NONAXEDCHART_H
