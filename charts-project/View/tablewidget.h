#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QSizePolicy>
#include <QDialog>
#include <QTimeEdit>
#include <QLineEdit>
#include <sstream>
#include <iomanip>
#include "selecttrainingdialog.h"
#include "trainingdialog.h"

#include <./Model/tennis.h>
#include <./Model/rugby.h>
#include <./Model/run.h>
#include <./Model/walk.h>
#include <./Model/cycling.h>
#include <./DateTime/datetime.h>

class tableWidget : public QWidget
{
    Q_OBJECT
private:
    QTableWidget *table;
    QLabel* title;
    QDialog* dialog;
    std::vector<QPushButton*> exerciseButtons;
    const std::vector<const Training*>* trainings;

    void setLabelStyleSheet(QLabel* name);
    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);
    void adaptTable(unsigned int w, unsigned int h, QTableWidget* table);
    void addTable(QVBoxLayout* tableLayout);
    void addControlTable(QVBoxLayout* mainLayout);
    void addControls(QVBoxLayout* tableLayout);
    void setupExercises(QVBoxLayout *mainL, const Repetition* training);
    void setupCommon(QVBoxLayout* mainL, const Training* training);

    QPushButton* addButton;
    QPushButton* setButton;
    QPushButton* removeButton;
    QPushButton* exerciseButton;

    QVBoxLayout* mainLayout;
private slots:
    void showExercises();
public:
    explicit tableWidget(QWidget *parent = nullptr);
    void showData();
    void setData(const std::vector<const Training *> *data);

signals:

};

#endif // TABLEWIDGET_H
