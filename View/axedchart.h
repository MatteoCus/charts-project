#ifndef AXEDCHART_H
#define AXEDCHART_H

#include "chart.h"


class axedChart : public chart
{
    Q_OBJECT
public:

    /**
     * @brief axedChart:        costruttore di axedChart, un widget per la gestione di un grafico con assi
     * @param parent:           widget genitore
     */
    explicit axedChart(QWidget *parent = nullptr);

    /**
     * @brief setAxes:      gestisce l'aggiunta delle etichette sugli assi x ed y del grafico
     * @param x:            stringa da apporre sull'asse x
     * @param y:            stringa da apporre sull'asse y
     */
    virtual void setAxes(const std::string& x, const std::string& y) = 0;

    /**
     * @brief addSeries:        gestisce l'aggiunta di nuovi dati nel grafico, eliminando i vecchi
     * @param values:           valori da apporre sull'asse y
     * @param start:            date di inizio degli allenamenti da visualizzare
     * @param duration          booleano che indica se i valori in "values" rappresentano delle durate (durata espressa in secondi da "00:00:00")
     */
    virtual void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) = 0;
};

#endif // AXEDCHART_H
