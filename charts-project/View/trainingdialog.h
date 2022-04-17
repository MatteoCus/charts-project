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
#include "trainingvalues.h"
#include "selecttrainingdialog.h"
#include "action.h"
#include <QInputDialog>

class trainingDialog : public QDialog
{
    Q_OBJECT
private:

    QLineEdit* name;
    QDateTimeEdit *start;
    QDoubleSpinBox* distance;
    QTimeEdit* duration;
    std::vector<QLineEdit*> nameEx;
    std::vector<QTimeEdit*> exDuration;
    std::vector<QTimeEdit*> exRecovery;
    QString type;


    void setLabelStyleSheet(QLabel* name);

    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);

    void setupRepetition(QBoxLayout *mainL, action act, const Repetition* training = nullptr);

    void setupEndurance(QBoxLayout *mainL, action act, const Endurance* training = nullptr);

    void setupCommon(QBoxLayout *mainL, action act, const Training* training = nullptr);

    int showExNumberDialog();
public:
    explicit trainingDialog(QWidget *parent, action act, const Training* training = nullptr);
    static trainingValues getValues(QWidget* parent, bool *ok, action act, const Training* training = nullptr);
};

#endif // TRAININGDIALOG_H
