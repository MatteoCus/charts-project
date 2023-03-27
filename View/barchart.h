#ifndef BARCHART_H
#define BARCHART_H

#include "axedchart.h"
#include <QWidget>

class barChart : public axedChart
{

protected:

    //dati rappresentati come barre verticali
    QBarSeries* series;

    //set di barre
    QBarSet* set;

    //categorie di barre
    QStringList categories;

    //asse x
    QBarCategoryAxis* axisX;

    /**
     * @brief connect:  gestisce l'aggiunta delle serie appena costruite al grafico, prima della sua visualizzazione
     */
    void connect() override;

public:

    /**
     * @brief barChart:     costruttore di barChart, un widget per la gestione di un grafico a barre
     * @param parent:       widget genitore
     */
    barChart(QWidget *parent = nullptr);

    /**
     * @brief setAxes:      gestisce l'aggiunta delle etichette sugli assi x ed y del grafico
     * @param x:            stringa da apporre sull'asse x
     * @param y:            stringa da apporre sull'asse y
     */
    void setAxes(const std::string& x, const std::string& y) override;

    /**
     * @brief addSeries:        gestisce l'aggiunta di nuovi dati nel grafico, eliminando i vecchi
     * @param values:           valori da apporre sull'asse y
     * @param start:            date di inizio degli allenamenti da visualizzare
     * @param duration          booleano che indica se i valori in "values" rappresentano delle durate (durata espressa in secondi da "00:00:00")
     */
    void addSeries(const std::vector<double>* values, const std::vector<DateTime*>* start, bool duration) override;
};

#endif // BARCHART_H
