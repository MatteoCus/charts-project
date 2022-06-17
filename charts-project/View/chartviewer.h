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

    //riferimento agli allenamenti del model
    const std::list<Training*>* trainings;

    /**
     * @brief addMenu:      aggiunge i menu al mainLayout (e connette i segnali e gli slot)
     */
    void addMenu();

    /**
     * @brief findTraining:     trova un allenamento basandosi sulla sua data di inizio (è identificatore degli esercizi)
     *                          e ritorna la sua posizione usando un riferimento
     * @param n:                riferimento alla posizione dell'allenamento
     * @param start:            data di inizio dell'allenamento da cercare
     */
    void findTraining(unsigned int &n, const QDateTime& start);

    /**
     * @brief closeEvent:   consente la chiusura del  widget chiedendo ulteriore conferma
     * @param event:        evento di chiusura
     */
    void closeEvent(QCloseEvent *event) override;

    /**
     * @brief setStyle:     imposta lo stile del widget (e dell'applicazione, essendo genitore di quasi tutte le componenti grafiche)
     */
    void setStyle();
    
private slots:

    /**
     * @brief showExercises:        consente la scelta di un allenamento di ripetizione e ne mostra gli esercizi
     * @throw std::runtime_error:   se il tipo di allenamento selezionato non è valido
     */
    void showExercises();

    /**
     * @brief showChart:            consente la visualizzazione del widget grafico presente in chartViewer in un dialog
     *                              indipendente e ingrandibile
     */
    void showChart();

    /**
     * @brief screenChanged:        gestisce il cambio di schermo in cui è visualizzato il widget, segnalando la cosa
     *                              alla tabella, per garantire una vista equilibrata
     */
    void screenChanged();

public:

    /**
     * @brief chartViewer:          costruttore di chartViewer: è il widget principale della GUI
     * @param parent:               widget genitore
     */
    explicit chartViewer(QWidget *parent = nullptr);

    /**
     * @brief setController:        imposta il riferimento al controller (e connette segnali e slot)
     * @param c:                    riferimento al controller
     */
    void setController(Controller* c);

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
     * @throw std::runtime_error:   se il tipo di allenamento scelto non è corretto/se l'operazione è annullata
     * @return dialogValues:        valori per rimuovere un allenamento dal modello
     */
    dialogValues showRemoveDialog();

    /**
     * @brief showSetDialog:        estrae i valori dai dialog per modificare un allenamento nel modello
     * @throw std::runtime_error:   se il tipo di allenamento scelto non è corretto/se l'operazione è annullata
     * @return dialogValues:        valori per modificare un allenamento nel modello
     */
    dialogValues showSetDialog();

    /**
     * @brief setData:          collega il riferimento agli allenamenti
     * @param data:             riferimento agli allenamenti
     */
    void setData(const std::list<Training*>* data);

    /**
     * @brief showData:         aggiorna la/le tabella/e ed il grafico attivo
     */
    void showData();

signals:
    void addTrainings() const;
    void setTrainings() const;
    void removeTrainings() const;
    void save() const;
    void saveAs() const;
    void newPlan() const;
    void open() const;
    void closeAll() const;
};

#endif // CHARTVIEWER_H
