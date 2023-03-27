#ifndef TYPEDIALOG_H
#define TYPEDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>

class typeDialog : public QDialog
{
    Q_OBJECT
private:

    //combo box contenente tutti i tipi disponibili di allenamento
    QComboBox* typeBox;
public:

    /**
     * @brief typeDialog:    costruttore di typeDialog, un dialog per la scelta del tipo di allenamento
     * @param parent:        widget genitore di tale dialog
     */
    explicit typeDialog(QWidget* parent = nullptr);

    /**
     * @brief getType               metodo statico per garantire l'esecuzione del dialog senza doverlo allocare
     * @param parent:               widget genitore di tale dialog
     * @param ok:                   booleano che serve per indicare se il dialog ha ritornato valori validi o meno
     * @return QString:             stringa contenente il tipo di allenamento scelto
     */
    static QString getType(QWidget* parent, bool* ok = nullptr);
};

#endif // TYPEDIALOG_H
