#ifndef ENDURANCEDIALOG_H
#define ENDURANCEDIALOG_H

#include "trainingdialog.h"

class enduranceDialog : public trainingDialog
{
private:

    //spin box per l'inserimento/visualizzazione della distanza per allenamenti di resistenza
    QDoubleSpinBox* distance;

    //time edit per l'inserimento/visualizzazione della durata per allenamenti di resistenza
    QTimeEdit* duration;

public:

    /**
     * @brief enduranceDialog:      costruttore di enduranceDialog, dialog per la visualizzazione di allenamenti di resistenza
     * @param parent:               widget genitore di tale dialog
     * @param act:                  azione da compiere sugli allenamenti: il suo valore può rendere editabile o meno dei widget
     * @param training:             allenamento da visualizzare se "act" è diverso da "add"
     */
    explicit enduranceDialog(QWidget *parent, action act, Endurance* training = nullptr);

    /**
     * @brief getValues             metodo statico per garantire l'esecuzione del dialog senza doverlo allocare
     * @param parent:               widget genitore di tale dialog
     * @param ok:                   booleano che serve per indicare se il dialog ha ritornato valori validi o meno
     * @param act:                  azione da compiere sugli allenamenti: il suo valore può rendere editabile o meno dei widget
     * @param training:             allenamento da visualizzare se "act" è diverso da "add"
     * @return dialogValues:        valori degli allenamenti atti a essere usati per modificare il modello
     */
    static dialogValues getValues(QWidget* parent, bool *ok, action act, Endurance* training = nullptr);
};

#endif // ENDURANCEDIALOG_H
