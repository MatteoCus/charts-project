#ifndef PIECHART_H
#define PIECHART_H

#include "nonaxedchart.h"
#include <QWidget>

class pieChart : public nonAxedChart
{
protected:

    //dati rappresentati come fette
    QPieSeries * series;

    //collezione di fette
    std::vector<QPieSlice *> slices;

    //collezione di colori
    std::vector<QColor> colors;

    /**
     * @brief connect:  gestisce l'aggiunta delle serie appena costruite al grafico, prima della sua visualizzazione
     */
    void connect() override;

    /**
     * @brief setPieSliceStyle: assegna i colori delle fette del grafico
     */
    void setPieSliceStyle();
public:

    /**
     * @brief pieChart:     costruttore di pieChart, un widget per la gestione di un grafico a torta
     * @param parent:       widget genitore
     */
    pieChart(QWidget *parent = nullptr);

    /**
     * @brief addSeries:        gestisce l'aggiunta di nuovi dati nel grafico, eliminando i vecchi
     * @param values:           valori da visualizzare
     * @param repetition:       booleano che indica la presenza esclusiva (o meno) di allenamenti di ripetizione
     * @param endurance:        booleano che indica la presenza esclusiva (o meno) di allenamenti di resistenza
     */
    void addSeries(const std::vector<double>* values, bool repetition, bool endurance) override;
};

#endif // PIECHART_H
