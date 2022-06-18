#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMessageBox>
#include "../dialogvalues.h"
#include "xmlfilehandler.h"
#include "../DateTime/datetimeconverter.h"
#include "../DateTime/datetime.h"
#include "../View/chartviewer.h"
#include "../View/initialdialog.h"
#include "../Model/model.h"

class Controller : public QObject
{
    Q_OBJECT
private:

    //componente grafico principale
    chartViewer* view;

    //modello
    Model* model;

    //saved: memorizza se i dati salvati nel modello (e disponibili nella vista) sono stati salvati sul file "filenameSaved"
    //firstResponse: indica la risposta dell'utente all'apertura del primo dialog: se è negativa, non si fa partire il loop degli eventi
    //               e l'applicazione termina immediatamente
    bool saved, firstResponse;

    //path del file dove è salvato l'insieme di dati memorizzati nel modello e mostrati nella vista
    QString filenameSaved;

    //dialog iniziale
    initialDialog* dialog;

    /**
     * @brief extractFromViewValues:    estrae i dati da un oggetto dialogValues e li smista nei vari parametri passati per riferimento, per il modello
     * @param start:                    data di inizio dell'allenamento
     * @param duration:                 durata dell'allenamento
     * @param exName:                   collezione di nomi per nuovi esercizi
     * @param exDuration:               collezione di durate per nuovi esercizi
     * @param exRecovery:               collezione di durate di recupero per nuovi esercizi
     * @param pos:                      posizione dell'allenamento su cui intervenire
     * @param exAct:                    eventuale azione da effettuare sulla collezione di esercizi di un allenamento di ripetizione (all'esercizio indicato da exPos)
     * @param exPos:                    eventuale posizione dove modificare la collezione di esercizi di un allenamento di ripetizione
     */
    void extractFromViewValues(dialogValues values, DateTime& start, TimeSpan& duration,std::vector<std::string>& exName,
                               std::vector<Time>& exDuration,std::vector<Time>& exRecovery, int& pos, action& exAct, int& exPos) const;

    /**
     * @brief extractFromModelValues:       estrae i dati da una collezione di allenamenti e li salva in una collezione di trainingValues, per la vista
     * @param trainings:                    collezione di allenamenti
     * @return std::vector<trainingValues>: vettore di trainingValues
     */
    std::vector<trainingValues> extractFromModelValues(const std::list<Training*>* trainings) const;

public:

    /**
     * @brief Controller:           costruttore del Controller
     * @param parent:               parent del Controller
     */
    explicit Controller(QObject *parent = nullptr);

    /**
     * @brief setView:         collega la vista
     * @param v:               vista
     */
    void setView(chartViewer* v);

    /**
     * @brief setModel:        collega il modello
     * @param m:               vista
     */
    void setModel(Model* m);

    /**
     * @brief startView:       mostra il dialog iniziale, con la schermata di spiegazione dei vincoli di programma ed i pulsanti di scelta
     * @return bool:           booleano che indica se l'utente ha scelto di proseguire, o meno, nell'utilizzo del programma dopo aver visto il primo dialog
     */
    bool startView();

    /**
     * @brief ~Controller:     scollega vista e modello, deallocandoli
     */
    ~Controller();

public slots:

    /**
     * @brief add:     gestisce una richiesta di inserimento di un allenamento
     */
    void add();

    /**
     * @brief changeSplitState:     gestisce un cambio di visualizzazione nel widget contenente la tabella/le tabelle
     * @param state:                booleano che indica la visualizzazione richiesta dall'utente
     */
    void changeSplitState(bool state) const;

    /**
     * @brief set:     gestisce una richiesta di modifica di un allenamento
     */
    void set();

    /**
     * @brief remove:     gestisce una richiesta di rimozione di un allenamento
     */
    void remove();

    /**
     * @brief newPlan:     gestisce una richiesta di rimozione di tutti gli allenamenti
     */
    void newPlan();

    /**
     * @brief save:     gestisce una richiesta di salvataggio di tutti gli allenamenti attivi nel file "filenameSaved"
     *                  potendo modificare i campi saved e filenameSaved
     */
    void save();

    /**
     * @brief saveAs:     gestisce una richiesta di salvataggio di tutti gli allenamenti attivi, facendo scegliere il file all'utente;
     *                      i campi saved e filenameSaved non sono modificati
     */
    void saveAs() const;

    /**
     * @brief showExercises:    gestisce una richiesta di visualizzazione degli esercizi di un allenamento (da selezionare)
     */
    void showExercises() const;

    /**
     * @brief showChart:    gestisce una richiesta di visualizzazione di un dialog custom contenente il widget dei grafici
     */
    void showChart() const;

    /**
     * @brief screenChanged:    gestisce il resize delle componenti grafiche in base al modello ed allo schermo
     *                          su cui il widget principale è visualizzato
     */
    void screenChanged() const;

    /**
     * @brief open:     gestisce una richiesta di ripristino di allenamenti da un file (da selezionare)
     */
    void open();

    /**
     * @brief closePlan:     gestisce una richiesta di uscita dal programma chiedendo, qualora i dati fossero aperti da un file
     *                      ("filenameSaved") e non fossero stati più scritti, se si vogliono aggiornare i dati prima di chiudere l'applicazione
     */
    void closePlan();

    /**
     * @brief first_response:    gestisce la situazione in cui l'utente non voglia continuare ad utilizzare il programma dopo il primo dialog
     */
    void first_response();

    /**
     * @brief first_open:    gestisce la situazione in cui l'utente vuole ripristinare allenamenti da file al primo avvio
     *                          usando il dialog iniziale ma non seleziona un file.
     */
    void first_open();

    /**
     * @brief updateChart:  gestisce l'aggiornamento del widget relativo ai grafici, cambiando tipo di grafico o dati visualizzati
     * @param widget:       widget in cui attuare i cambiamenti
     * @param chart:        nome del grafico da visualizzare
     * @param data:         nome del dato da visualizzare
     */
    void updateChart(chartWidget& widget, const std::string& chart, const std::string& data) const;
};

#endif // CONTROLLER_H
