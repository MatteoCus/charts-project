#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <QtCharts>
#include <QLineSeries>
#include <QBarSeries>
#include <QPieSeries>
#include <QPieSlice>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QBarSet>
#include <QCategoryAxis>
#include <QDateTimeAxis>
#include <DateTime/datetime.h>
#include "DateTime/datetimeconverter.h"

#include <vector>
QT_CHARTS_USE_NAMESPACE

class chart : public QWidget
{
protected:

    //widget per la visualizzazione di un grafico
    QChartView *chartView;

    //widget che rappresenta il grafico
    QChart * graph;

    /**
     * @brief connect:  gestisce l'aggiunta delle serie appena costruite al grafico, prima della sua visualizzazione
     */
    virtual void connect() = 0;
public:

    /**
     * @brief chart:    costruttore di chart, un widget per la gestione di un grafico a livello superiore rispetto ad un QChartView
     * @param parent:   widget genitore
     */
    chart(QWidget *parent = nullptr);

    /**
     * @brief getChartView:     ritorna il puntatore al QChartView per usi esterni a questo widget
     * @return QChartView:      widget per la gestione di un grafico
     */
    QChartView *getChartView() const;
};

#endif // CHART_H
