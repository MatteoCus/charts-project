#ifndef ENDURANCEDIALOG_H
#define ENDURANCEDIALOG_H

#include "trainingdialog.h"

class enduranceDialog : public trainingDialog
{
private:
    QDoubleSpinBox* distance;
    QTimeEdit* duration;

public:
    explicit enduranceDialog(QWidget *parent, action act, const Endurance* training = nullptr);
    static trainingValues getValues(QWidget* parent, bool *ok, action act, const Endurance* training = nullptr);
};

#endif // ENDURANCEDIALOG_H
