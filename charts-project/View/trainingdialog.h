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
#include "typedialog.h"
#include "trainingvalues.h"
#include "selecttrainingdialog.h"
#include "action.h"

class trainingDialog : public QDialog
{
    Q_OBJECT
private:

    QLineEdit* name;
    QDateTimeEdit *start;
    QDoubleSpinBox* distance;
    QTimeEdit* duration;
    QLineEdit* nameEx;
    QTimeEdit* exDuration;
    QTimeEdit* recovery;
    QString type;


    void setLabelStyleSheet(QLabel* name);

    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);

    void setupRepetition(QBoxLayout *mainL);

    void setupEndurance(QBoxLayout *mainL);

    void setupCommon(QBoxLayout *mainL, action act, QString name = "", QString start = "");

public:
    explicit trainingDialog(QWidget *parent = nullptr, action act = nothing, const std::vector<Training*>* trainings = nullptr);
    static trainingValues getValues(QWidget* parent = nullptr, bool *ok = nullptr , action act = nothing, const std::vector<Training*>* trainings= nullptr);

};

#endif // TRAININGDIALOG_H
