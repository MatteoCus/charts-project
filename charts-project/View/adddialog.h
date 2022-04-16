#ifndef ADDDIALOG_H
#define ADDDIALOG_H

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
#include <QInputDialog>

class addDialog : public QDialog
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

    void setupRepetition(QBoxLayout *mainL);

    void setupEndurance(QBoxLayout *mainL);

    void setupCommon(QBoxLayout *mainL);

    int showExNumberDialog();
public:
    explicit addDialog(QWidget *parent = nullptr);
    static trainingValues getValues(QWidget* parent = nullptr, bool *ok = nullptr);
};

#endif // ADDDIALOG_H
