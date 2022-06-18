#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QObject>
#include <QWindow>
#include <QDesktopWidget>
#include <QWidget>
#include <QRect>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QScrollBar>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QSizePolicy>
#include <QDialog>
#include <QTimeEdit>
#include <QLabel>
#include <QCheckBox>
#include <sstream>
#include <iomanip>
#include "selecttrainingdialog.h"
#include "repetitiondialog.h"

#include <./Model/tennis.h>
#include <./Model/rugby.h>
#include <./Model/run.h>
#include <./Model/walk.h>
#include <./Model/cycling.h>
#include <./DateTime/datetime.h>

class tableWidget : public QWidget
{
    Q_OBJECT
private:

    //tabelle per la visualizzazione dei dati
    QTableWidget *table1, *table2;

    //check box per la visualizzazione alternativa
    QCheckBox * splitCheckBox;

    //etichette delle tabelle
    QLabel* label1, *label2;

    //pulsanti per l'esecuzione di azioni sul model
    QPushButton* addButton;
    QPushButton* setButton;
    QPushButton* removeButton;
    QPushButton* exerciseButton;

    //layouts delle tabelle
    QVBoxLayout* table1Layout, *table2Layout;

    //layout principale e layout delle tabelle
    QVBoxLayout* mainLayout, *tableLayout;

    //splitState: indica se la visualizzazione alternativa è attiva
    bool splitState;

    /**
     * @brief setLabelColor:        imposta il colore dell'etichetta in ingresso
     * @param label:                etichetta da modificare
     */
    void setLabelColor(QLabel* label);

    /**
     * @brief addToLayout:      aggiunge al layout passato i due widget in ingresso
     * @param layout:           layout in input
     * @param w1:               widget da aggiungere per primo
     * @param w2:               widget da aggiungere per secondo
     */
    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);


    /**
     * @brief adaptSingleTableHeight:       adatta l'altezza della tabella in ingresso nel caso della visualizzazione standard
     *                                      a tabella singola
     * @param table:                        tabella da adattare
     */
    void adaptSingleTableHeight(QTableWidget* table);

    /**
     * @brief adaptDoubleTableHeight        adatta l'altezza della tabella in ingresso nel caso della visualizzazione alternativa
     *                                      a tabella doppia
     * @param table:                        tabella da adattare
     */
    void adaptDoubleTableHeight(QTableWidget* table);

    /**
     * @brief setTableResize:               inizializza l'header della tabella in ingresso
     * @param table:                        tabella da inizializzare
     */
    void setTableResize(QTableWidget* table);

    /**
     * @brief addControlTable:          aggiunge tabelle, controlli e rispettivi layout al layout principale
     */
    void addControlTable();

    /**
     * @brief addControls:              aggiunge i controlli (pulsanti) al proprio layout
     */
    void addControls();

    /**
     * @brief showCommonData:           consente di inserire nelle tabelle, a seconda della visualizzazione, delle QLabel
     *                                  con valori comuni a tutti gli allenamenti
     * @param it:                       allenamento da cui prendere ed inserire i valori nelle tabelle
     * @param i:                        numero di tabella (1 o 2) in cui mettere i valori
     */
    void showCommonData(Training* it, unsigned int i = 1);

    /**
     * @brief showRepetitionData        consente di inserire nelle tabelle, a seconda della visualizzazione, delle QLabel
     *                                  con valori comuni solo agli allenamenti di ripetizione
     * @param training                  allenamento da cui prendere ed inserire i valori nelle tabelle
     * @param i:                        numero di tabella (1 o 2) in cui mettere i valori
     */
    void showRepetitionData(Repetition* training, unsigned int i = 1);

    /**
     * @brief showEnduranceData         consente di inserire nelle tabelle, a seconda della visualizzazione, delle QLabel
     *                                  con valori comuni solo agli allenamenti di resistenza
     * @param training                  allenamento da cui prendere ed inserire i valori nelle tabelle
     * @param i                         numero di tabella (1 o 2) in cui mettere i valori
     */
    void showEnduranceData(Endurance* training, unsigned int i = 1);
    
    /**
     * @brief insertEmptyRow:           inserisce una riga vuota nella tabella in ingresso
     * @param table:                    tabella in cui inserire la riga
     */
    void insertEmptyRow(QTableWidget* table);

    /**
     * @brief setContentResize:         imposta, nella tabella in ingresso, alcune colonne in modo che adattino la propria
     *                                  dimensione a quella del contenuto
     * @param table:                    tabella in ingresso
     */
    void setContentResize(QTableWidget* table);

    /**
     * @brief setStretchResize:         imposta, nella tabella in ingresso, che tutte le colonne si allarghino in base
     *                                  alla disponibilità di spazio nel layout
     * @param table:                    tabella in ingresso
     */
    void setStretchResize(QTableWidget *table);

    /**
     * @brief adjustResizePolicy:       imposta la resize policy in base alla risoluzione dello schermo in cui il widget
     *                                  è attualmente visibile
     * @param trainings:                puntatore ad una collezione di allenamenti da cui dedurre la resize policy, usando anche
     *                                  la risoluzione dello schermo in cui è mostrato il widget
     */
    void adjustResizePolicy(const std::list<Training *>* trainings);

public:

    /**
     * @brief tableWidget:      costruttore di tableWidget, widget per la visualizzazione dinamica di tabelle
     * @param parent:           widget genitore
     */
    explicit tableWidget(QWidget *parent);

    /**
     * @brief changeState:              cambia lo splitState e aggiorna, se "show" è true, il widget
     * @param trainings:                puntatore ad una collezione di allenamenti da mostrare in base al valore di "show"
     * @param state:                    nuovo splitState
     * @param show:                     booleano che consente o meno di aggiornare la grafica del widget
     */
    void changeState(const std::list<Training *>* trainings,bool state, bool show);

    /**
     * @brief showData:         gestisce la visualizzazione dei dati usando splitState
     * @param trainings:        puntatore ad una collezione di allenamenti da mostrare
     */
    void showData(const std::list<Training *>* trainings);

    /**
     * @brief setSplitState:    modifica esplicitamente il valore di spliState senza aggiornare il widget
     * @param trainings:        puntatore ad una collezione di allenamenti da NON mostrare dopo aver impostato lo splitState
     *                          (si usa il metodo changeState))
     * @param state:            nuovo splitState
     */
    void setSplitState(const std::list<Training *>* trainings,bool state);

    /**
     * @brief screenChanged:    metodo pubblico che consente di chiamare il metodo privato "adjustResizePolicy"
     * @param trainings:        puntatore ad una collezione di allenamenti da cui dedurre la resize policy
     */
    void screenChanged(const std::list<Training *>* trainings);

signals:
    void add();
    void set();
    void remove();
    void showExercises();
    void changeState(bool);
};

#endif // TABLEWIDGET_H
