#ifndef CHARTVIEWER_H
#define CHARTVIEWER_H
#include <utility>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QDialog>
#include <QFileDialog>
#include <QFont>
#include <QPlainTextEdit>
#include "tablewidget.h"
#include "chartwidget.h"
#include "./Model/training.h"

#include "./Model/run.h"
#include "./Model/cycling.h"
#include "./Model/tennis.h"
#include "./Model/rugby.h"
#include "./Model/walk.h"
#include "./Model/exercise.h"

#include "endurancedialog.h"
#include "repetitiondialog.h"
#include "dialogvalues.h"
#include "action.h"
#include "selecttrainingdialog.h"

class Controller;

class chartViewer : public QWidget
{
    Q_OBJECT
private:
    //riferimento al controller
    Controller* controller;

    //layout principale
    QHBoxLayout* mainLayout;

    //widget per visualizzare le tabelle
    tableWidget* tableW;

    //widget per visualizzare i grafici
    chartWidget* chartW;

    //barra del menù
    QMenuBar* menuBar;

    //i menù
    QMenu *file, *visualizza, *allenamenti;

    /**
     * @brief addMenu:      aggiunge i menu al mainLayout (e connette i segnali e gli slot)
     */
    void addMenu();

    /**
     * @brief findTraining:     trova un allenamento basandosi sulla sua data di inizio (è identificatore degli esercizi)
     *                          e ritorna la sua posizione usando un riferimento
     * @param trainings:        puntatore ad una collezione di allenamenti in cui trovare l'allenamento che ha
     *                          come data di inizio la data di inizio in ingresso
     * @param n:                riferimento alla posizione dell'allenamento
     * @param start:            data di inizio dell'allenamento da cercare
     */
    void findTraining(const std::list<Training *>* trainings, unsigned int &n, const QDateTime& start);

    /**
     * @brief closeEvent:   consente la chiusura del  widget chiedendo ulteriore conferma
     * @param event:        evento di chiusura
     */
    void closeEvent(QCloseEvent *event) override;

    /**
     * @brief setStyle:     imposta lo stile del widget (e dell'applicazione, essendo genitore di quasi tutte le componenti grafiche)
     */
    void setStyle();
    
public:

    /**
     * @brief chartViewer:          costruttore di chartViewer: è il widget principale della GUI
     * @param parent:               widget genitore
     */
    explicit chartViewer(QWidget *parent = nullptr);

    /**
     * @brief changeTableState:     modifica la visualizzazione del widget che gestisce le tabelle
     * @param trainings:            puntatore ad una collezione di allenamenti, serve per la visualizzazione dei dati
     * @param state:                tipo di visualizzazione
     * @param show:                 booleano che indica se il widget che gestisce le tabelle deve mostrare i cambiamenti a video
     */
    void changeTableState(const std::list<Training*>* trainings, bool state, bool show);

    /**
     * @brief setController:        imposta il riferimento al controller (e connette segnali e slot)
     * @param c:                    riferimento al controller
     */
    void setController(Controller* c);

    /**
     * @brief showExercises:        consente la scelta di un allenamento di ripetizione e ne mostra gli esercizi
     * @param trainings:            puntatore ad una collezione di allenamenti in cui operare
     * @throw std::runtime_error:   se il tipo di allenamento selezionato non è valido
     */
    void showExercises(const std::list<Training *>* trainings);

    /**
     * @brief showChart:            consente la visualizzazione del widget grafico presente in chartViewer in un dialog
     *                              indipendente e ingrandibile
     * @param trainings:            puntatore ad una collezione di allenamenti in cui operare
     */
    void showChart(const std::list<Training *>* trainings);

    /**
     * @brief screenChanged:        gestisce il cambio di schermo in cui è visualizzato il widget, segnalando la cosa
     *                              alla tabella, per garantire una vista equilibrata
     * @param trainings:            puntatore ad una collezione di allenamenti da visualizzare sulla tabella
     */
    void screenChanged(const std::list<Training *>* trainings);

    /**
     * @brief showWarning:          mostra a video i messaggi di errore dell'applicazione
     * @param message:              messaggio di errore
     */
    void showWarning(const QString& message);

    /**
     * @brief showAddDialog:        estrae i valori dai dialog per creare un allenamento da inserire nel modello
     * @throw std::runtime_error:   se il tipo di allenamento scelto non è corretto/se l'operazione è annullata
     * @return dialogValues:        valori per creare un allenamento da inserire nel modello
     */
    dialogValues showAddDialog();

    /**
     * @brief showRemoveDialog:     estrae i valori dai dialog per rimuovere un allenamento dal modello
     * @param trainings:            puntatore ad una collezione di allenamenti in cui operare
     * @throw std::runtime_error:   se il tipo di allenamento scelto non è corretto/se l'operazione è annullata
     * @return dialogValues:        valori per rimuovere un allenamento dal modello
     */
    dialogValues showRemoveDialog(const std::list<Training *>* trainings);

    /**
     * @brief showSetDialog:        estrae i valori dai dialog per modificare un allenamento nel modello
     * @param trainings:            puntatore ad una collezione di allenamenti in cui operare
     * @throw std::runtime_error:   se il tipo di allenamento scelto non è corretto/se l'operazione è annullata
     * @return dialogValues:        valori per modificare un allenamento nel modello
     */
    dialogValues showSetDialog(const std::list<Training *>* trainings);

    /**
     * @brief showData:         aggiorna la/le tabella/e ed il grafico attivo
     * @param trainings:        puntatore ad una collezione di allenamenti in cui operare
     */
    void showData(const std::list<Training *>* trainings);

    /**
     * @brief updateChart:      aggiorna il widget relativo alla visualizzazione dei grafici
     * @param trainings:        puntatore ad una collezione di allenamenti di cui visualizzare i dati richiesti nel grafico richiesto
     * @param widget:           widget in cui attuare i cambiamenti
     * @param chart:            nome del grafico richiesto
     * @param data:             nome dei dati richiesti
     */
    void updateChart(const std::list<Training*>* trainings, chartWidget& widget, const std::string& chart, const std::string& data);

signals:
    void addTrainings() const;
    void changeSplitState(bool) const;
    void setTrainings() const;
    void removeTrainings() const;
    void save() const;
    void saveAs() const;
    void showExercises() const;
    void showChart() const;
    void screenChanged() const;
    void newPlan() const;
    void open() const;
    void closeAll() const;
    void updateChart(chartWidget&, const std::string&, const std::string&) const;

};

#endif // CHARTVIEWER_H
