#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGraphicsEffect>
#include <QSizePolicy>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>
#include <QFont>
#include <./DateTime/datetime.h>
#include <./Model/walk.h>
#include <./Model/cycling.h>
#include <./Model/run.h>
#include <./Model/tennis.h>
#include <./Model/rugby.h>
#include "linechart.h"
#include "barchart.h"
#include "piechart.h"

class chartWidget : public QWidget
{
    Q_OBJECT
private:

    //puntatore al grafico attivo
    chart* visibleChart;

    //grafico a linea
    lineChart* line;

    //grafico a barre
    barChart* bar;

    //grafico a torta
    pieChart* pie;

    //combo box per la selezione del grafico
    QComboBox* chartBox;

    //combo box per la selezione dei dati da visualizzare nel grafico attivo
    QComboBox* dataBox;

    //layout principale
    QVBoxLayout * mainLayout;

    /**
     * @brief addDefaultChart:  creazione dei grafici di default con assegnazione del grafico visibile al grafico a linee
     */
    void addDefaultChart();

    /**
     * @brief addControls:          aggiunta delle combo box al layout principale (e collegamento segnali e slot)
     */
    void addControls();

    /**
     * @brief hideDataBoxEntry: metodo per nascondere entry della combo box relativa ai dati: alcuni dati visualizzati
     *                          appartengono solamente agli allenamenti di ripetizione/resistenza, quindi in assenza di
     *                          tali allenamenti non si devono poter selezionare tali entry
     * @param x:                posizione della entry da nascondere
     */
    void hideDataBoxEntry(int x);

    /**
     * @brief unhideDataBoxEntry:   mostra eventuali entry nascoste della combo box relativa ai dati
     * @param x:                    posizione della entry da rendere visibile
     */
    void unhideDataBoxEntry(int x);

    /**
     * @brief checkDataBoxValues:   gestisce i valori delle combo box in seguito a modifiche del model
     *                              (nasconde/mostra entry della combo box relativa ai dati)
     * @param trainings:            puntatore ad una collezione di allenamenti da cui dedurre se
     *                              nascondere entry della combo box
     */
    void checkDataBoxValues(const std::list<Training*>* trainings);

    /**
     * @brief extractValues:        consente l'estrazione dei dati, a partire dal riferimento agli allenamenti del model,
     *                              in un formato compatibile con le esigenze dei grafici
     * @param trainings:            puntatore ad una collezione di allenamenti da cui estrarre i valori
     * @param values:               valori estratti
     * @param start:                date di inizio degli allenamenti da cui sono estratti i valori
     * @param data:                 tipo di dati da estrarre dagli allenamenti
     */
    void extractValues(const std::list<Training*>* trainings, std::vector<double>& values, std::vector<DateTime*>& start, const std::string& data);

    /**
     * @brief extractValues:        consente l'estrazione dei dati, a partire dal riferimento agli allenamenti del model,
     *                              in un formato compatibile con le esigenze dei grafici
     * @param trainings:            puntatore ad una collezione di allenamenti da cui estrarre i valori
     * @param values:               valori estratti
     * @param data:                 tipo di dati da estrarre dagli allenamenti
     */
    void extractValues(const std::list<Training*>* trainings, std::vector<double>& values, const std::string& data);

public:

    /**
     * @brief chartWidget:          costruttore di chartWidget, widget per la visualizzazione dinamica di grafici
     * @param parent:               widget genitore
     */
    explicit chartWidget(QWidget *parent = nullptr);

    /**
     * @brief showData:         gestisce la visualizzazione dei dati usando il grafico attivo ed i tipi di dato
     *                          selezionati dall'utente (se non specificati, si prendono i valori dalle combo box)
     * @param trainings:        puntatore ad una collezione di allenamenti da cui estrarre i valori
     * @param chart:            nome del grafico da usare per la visualizzazione
     * @param data:             nome dei dati da usare per la visualizzazione
     */
    void showData(const std::list<Training*>* trainings, std::string chart = "", std::string data = "");

    /**
     * @brief getVisibleChart:  ritorna un puntatore al grafico visibile
     * @return  chart*:         puntatore al grafico visibile
     */
    chart* getVisibleChart() const;

    /**
     * @brief setChartsSize:   imposta le dimensioni del grafico
     * @param w:               larghezza del grafico
     * @param h:               altezza del grafico
     */
    void setChartsSize(int w, int h);

    /**
     * @brief clone:                metodo per implementare il clonable pattern sulla gerarchia sottostante
     * @param trainings:            puntatore ad una collezione di allenamenti, serve al costruttore
     */
    chartWidget *clone(const std::list<Training*>* trainings) const;

signals:
    void updateChart(chartWidget&, const std::string&, const std::string&) const;
};

#endif // CHARTWIDGET_H
