#ifndef REPETITIONDIALOG_H
#define REPETITIONDIALOG_H

#include "trainingdialog.h"

class repetitionDialog : public trainingDialog
{
private:

    //azione da compiere sul/sugli esercizi dell'allenamento selezionato/da creare
    action exAct;

    //edits per i valori degli esercizi dell'allenamento selezionato/da creare
    std::vector<QLineEdit*> exName;
    std::vector<QTimeEdit*> exDuration;
    std::vector<QTimeEdit*> exRecovery;

    //posizione dell'esercizio da mostrare/inserire
    unsigned int exPos;

public:

    /**
     * @brief repetitionDialog:     costruttore di repetitionDialog, dialog per la visualizzazione di allenamenti di ripetizione
     * @param parent:               widget genitore di tale widget
     * @param act:                  azione da compiere sugli allenamenti: il suo valore può rendere editabile o meno dei widget
     * @param training:             allenamento da visualizzare se "act" è diverso da "add"
     */
    explicit repetitionDialog(QWidget *parent, action act, Repetition *training = nullptr);

    /**
     * @brief getValues             metodo statico per garantire l'esecuzione del dialog senza doverlo allocare
     * @param parent:               widget genitore di tale dialog
     * @param ok                    booleano che serve per indicare se il dialog ha ritornato valori validi o meno
     * @param act:                  azione da compiere sugli allenamenti: il suo valore può rendere editabile o meno dei widget
     * @param training:             allenamento da visualizzare se "act" è diverso da "add"
     * @return
     */
    static dialogValues getValues(QWidget* parent, bool *ok, action act, Repetition* training = nullptr);
};

#endif // REPETITIONDIALOG_H
