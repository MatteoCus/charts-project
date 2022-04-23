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
#include "./Model/repetition.h"
#include "./Model/endurance.h"

class selectTrainingDialog : public QDialog
{
    Q_OBJECT
private:
    QComboBox* dateBox;
    QLineEdit* name;
private slots:
    //void updateName(const QString &text);

public:
    explicit selectTrainingDialog(QWidget* parent = nullptr, const std::vector<const Training*>* trainings = nullptr, std::string type = "All");    //trainings not nullptr
    static QString getDate(QWidget* parent, bool* ok = nullptr, const std::vector<const Training*>* trainings = nullptr, std::string type = "All");


};

#endif // SELECTTRAININGDIALOG_H
