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

    QLineEdit* name;
    QDateTimeEdit *start;
    unsigned int pos;


    QVBoxLayout *mainL;

    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);

    void setupCommon(QBoxLayout *mainL, action act, Training* training = nullptr);

    int showExNumberDialog();
    void addButtons();

public:
    explicit trainingDialog(QWidget *parent);
};

#endif // TRAININGDIALOG_H
