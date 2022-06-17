#ifndef TRAININGDIALOG_H
#define TRAININGDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>
#include <QPushButton>
#include "./Model/training.h"
#include "./Model/endurance.h"
#include "./Model/repetition.h"
#include "./Model/rugby.h"
#include "./Model/run.h"
#include "./Model/walk.h"
#include "typedialog.h"
#include "dialogvalues.h"
#include "selecttrainingdialog.h"
#include "action.h"
#include <QInputDialog>

class trainingDialog : public QDialog
{
    Q_OBJECT
protected:

    //line edit in cui scrivere/visualizzare il nome di un allenamento
    QLineEdit* name;

    //datetime edit in cui scrivere/visualizzare l'inizio di un allenamento
    QDateTimeEdit *start;

    //layout principale
    QVBoxLayout *mainL;

    int pos;

    /**
     * @brief addToLayout:  gestisce l'aggiunta dei widget desiderati nel layout indicato
     * @param layout:       layout in cui aggiungere i widget
     * @param w1:           widget da aggiungere per primo nel layout
     * @param w2:           widget da aggiungere per secondo nel layout
     */
    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);

    /**
     * @brief setupCommon:  gestisce il setup dell'header, comune a tutti i dialog custom di visualizzazione  dati di allenamenti
     * @param layout:       layout in cui aggiungere i widget di header
     * @param act:          azione da compiere sugli allenamenti: il suo valore può rendere editabile o meno dei widget
     * @param training:     allenamento da visualizzare se "act" è diverso da "add"
     */
    void setupCommon(QBoxLayout *layout, action act, Training* training = nullptr);

    /**
     * @brief showExNumberDialog:   dialog di richiesta del numero di esercizi da creare durante la creazione di un allenamento di ripetizione
     * @return int:                 numero di esercizi da creare
     */
    int showExNumberDialog();

    /**
     * @brief addButtons:           aggiunta dei pulsanti di conferma/rifiuto al layout principale (solitamente ultimi widget
     *                              ad essere aggiunti)
     */
    void addButtons();

public:

    /**
     * @brief trainingDialog    costruttore di trainingDialog
     * @param parent            widget genitore di tale dialog
     */
    explicit trainingDialog(QWidget *parent);
};

#endif // TRAININGDIALOG_H
