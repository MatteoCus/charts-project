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
    void setComboBoxStyleSheet();
public:
    explicit selectTrainingDialog(QWidget* parent = nullptr, const std::list<const Training*>* trainings = nullptr, std::string type = "All");
    static QString getDate(QWidget* parent, bool* ok = nullptr, const std::list<const Training*>* trainings = nullptr, std::string type = "All");


};

#endif // SELECTTRAININGDIALOG_H
