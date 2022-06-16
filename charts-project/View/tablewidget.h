#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QObject>
#include <QWindow>
#include <QDesktopWidget>
#include <QWidget>
#include <QRect>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QScrollBar>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QSizePolicy>
#include <QDialog>
#include <QTimeEdit>
#include <QLabel>
#include <QCheckBox>
#include <sstream>
#include <iomanip>
#include "selecttrainingdialog.h"
#include "repetitiondialog.h"

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
    QLabel* label1, *label2;

    QPushButton* addButton;
    QPushButton* setButton;
    QPushButton* removeButton;
    QPushButton* exerciseButton;

    QVBoxLayout* table1Layout, *table2Layout;
    QVBoxLayout* mainLayout, *tableLayout;

    const std::list<Training*>* trainings;
    bool splitState, firstShow;

    void setLabelColor(QLabel* label);
    void setCheckBoxStyleSheet(QCheckBox* checkBox);
    void addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2);
    void adaptSingleTableHeight(QTableWidget* table);
    void adaptDoubleTableHeight(QTableWidget* table);
    void setTableStyleSheet(QTableWidget* table);
    void addControlTable();
    void addControls();

    void showCommonData(Training* it, unsigned int i = 1);
    void showRepetitionData(Repetition* training, unsigned int i = 1);
    void showEnduranceData(Endurance* training, unsigned int i = 1);
    
    void insertEmptyRow(QTableWidget* table);

    void setContentResize(QTableWidget* table);

    void setStretchResize(QTableWidget *table);
    void adjustResizePolicy();

private slots:
    void changeState(bool state, bool show);
public:
    explicit tableWidget(QWidget *parent = nullptr);
    void showData();
    void setData(const std::list<Training *> *data);
    void setSplitState(bool state);
    void screenChanged();

signals:
    void add();
    void set();
    void remove();
    void showExercises();
};

#endif // TABLEWIDGET_H
