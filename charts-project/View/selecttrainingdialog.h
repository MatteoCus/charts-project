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
#include "./Model/training.h"

class selectTrainingDialog : public QDialog
{
    Q_OBJECT
private:
    QComboBox* dateBox;
    QLineEdit* name;
private slots:
    //void updateName(const QString &text);

public:
    explicit selectTrainingDialog(QWidget* parent = nullptr, const std::vector<Training*>* trainings = nullptr);    //trainings not nullptr
    static QString getDate(QWidget* parent, bool* ok = nullptr, const std::vector<Training*>* trainings = nullptr);


};

#endif // SELECTTRAININGDIALOG_H
