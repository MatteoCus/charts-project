#ifndef ENDURANCEDIALOG_H
#define ENDURANCEDIALOG_H

#include "trainingdialog.h"

class enduranceDialog : public trainingDialog
{
private:
    QDoubleSpinBox* distance;
    QTimeEdit* duration;

public:
    explicit enduranceDialog(QWidget *parent, action act, Endurance* training = nullptr);
    static dialogValues getValues(QWidget* parent, bool *ok, action act, Endurance* training = nullptr);
};

#endif // ENDURANCEDIALOG_H
