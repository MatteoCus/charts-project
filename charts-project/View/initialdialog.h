#ifndef INITIALDIALOG_H
#define INITIALDIALOG_H

#include <QDialog>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QGroupBox>
#include <QCloseEvent>

class initialDialog : public QDialog
{
    Q_OBJECT
private:
    QHBoxLayout* mainLayout;
    QVBoxLayout* buttonsLayout, *textImageLayout;
    QPushButton* newButton;
    QPushButton* openButton;
    QLabel* text;

    void addButtons();
    void addTextImage();
    void closeEvent(QCloseEvent *event) override;

private slots:
    void closeWidget();
public:
    explicit initialDialog(QWidget *parent = nullptr);

signals:
    void openFile() const;
    void showView() const;
    void closeAll() const;
};

#endif // INITIALDIALOG_H
