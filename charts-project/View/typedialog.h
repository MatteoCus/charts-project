#ifndef TYPEDIALOG_H
#define TYPEDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>

class typeDialog : public QDialog
{
    Q_OBJECT
private:
    QComboBox* typeBox;
public:
    explicit typeDialog(QWidget* parent = nullptr);
    static QString getType(QWidget* parent, bool* ok = nullptr);
};

#endif // TYPEDIALOG_H
