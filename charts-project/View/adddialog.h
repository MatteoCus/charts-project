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
#include "typedialog.h"
#include "addvalues.h"

class addDialog : public QDialog
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

    void setupCommon(QBoxLayout *mainL);

public:
    explicit addDialog(QWidget *parent = nullptr);
    static addValues getValues(QWidget* parent, bool *ok = nullptr);

};

#endif // ADDDIALOG_H
