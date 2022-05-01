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
#include <QCheckBox>
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
    QTableWidget *table1, *table2;
    QCheckBox * splitCheckBox;
    QLabel* label1;

    QPushButton* addButton;
    QPushButton* setButton;
    QPushButton* removeButton;
    QPushButton* exerciseButton;

    QVBoxLayout* tableLayout;
    QVBoxLayout* mainLayout;

    const std::list<const Training*>* trainings;
    bool splitState;

    void setLabelStyleSheet(QLabel* name);
    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);
    void adaptTableHeight(unsigned int h, QTableWidget* table);
    void adaptTableWidth(unsigned int w, QTableWidget* table);
    void addTable(QTableWidget * table);
    void addControlTable(QVBoxLayout* mainLayout);
    void addControls(QVBoxLayout* mainLayout);
    void addLabel(QLabel* label);
    void setupExercises(QVBoxLayout *mainL, const Repetition* training);
    void setupCommon(QVBoxLayout* mainL, const Training* training);

    void setLineEdit(QLineEdit* item);

    void showCommonData(const Training* it, unsigned int i = 1);
    void showRepetitionData(const Repetition* training);
    void showEnduranceData(const Endurance* training);
    
private slots:
    void showExercises();
    void changeState(int state);
public:
    explicit tableWidget(QWidget *parent = nullptr);
    void showData();
    void setData(const std::list<const Training *> *data);

signals:

};

#endif // TABLEWIDGET_H
