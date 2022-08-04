#ifndef SELECTTRAININGDIALOG_H
#define SELECTTRAININGDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include "./Model/repetition.h"
#include "./Model/endurance.h"

class selectTrainingDialog : public QDialog
{
    Q_OBJECT
private:

    //combo box contenente tutte le stringhe delle date di inizio degli allenamenti del tipo richiesto
    QComboBox* dateBox;

    //line edit contenente i nomi dell'allenamento di cui l'inizio è selezionato nella combo box
    QLineEdit* name;

public:

    /**
     * @brief selectTrainingDialog: costruttore di selectTrainingDialog, dialog per la scelta di allenamenti
     *                              con funzionalità di filtro sul tipo di allenamenti osservabili
     * @param parent:               widget genitore di tale dialog
     * @param trainings:            collezione di allenamenti da visualizzare (dopo essere stati filtrati per tipo) per la scelta
     * @param type:                 parametro opzionale che indica il tipo di allenamenti visualizzabili
     */
    explicit selectTrainingDialog(QWidget* parent = nullptr, const std::list<Training*>* trainings = nullptr, std::string type = "All");

    /**
     * @brief getDate               metodo statico per garantire l'esecuzione del dialog senza doverlo allocare
     * @param parent:               widget genitore di tale dialog
     * @param ok                    booleano che serve per indicare se il dialog ha ritornato valori validi o meno
     * @param trainings:            collezione di allenamenti da visualizzare (dopo essere stati filtrati per tipo) per la scelta
     * @param type:                 parametro opzionale che indica il tipo di allenamenti visualizzabili
     * @return QString:     ritorna la stringa in formato "dd/MM/yyyy hh:mm:ss" della data-ora di inizio dell'allenamento scelto
     */
    static QString getDate(QWidget* parent, bool* ok = nullptr, const std::list<Training*>* trainings = nullptr, std::string type = "All");


};

#endif // SELECTTRAININGDIALOG_H
