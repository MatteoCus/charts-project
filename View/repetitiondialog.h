#ifndef REPETITIONDIALOG_H
#define REPETITIONDIALOG_H

#include "trainingdialog.h"

class repetitionDialog : public trainingDialog
{
private:
    action exAct;
    std::vector<QLineEdit*> exName;
    std::vector<QTimeEdit*> exDuration;
    std::vector<QTimeEdit*> exRecovery;
    unsigned int exPos;

public:
    explicit repetitionDialog(QWidget *parent, action act, Repetition *training = nullptr);
    static trainingValues getValues(QWidget* parent, bool *ok, action act, Repetition* training = nullptr);
};

#endif // REPETITIONDIALOG_H
