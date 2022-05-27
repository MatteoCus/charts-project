#ifndef CHARTVIEWER_H
#define CHARTVIEWER_H
#include <utility>

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QDialog>
#include <QFileDialog>
#include <QFont>
#include <QPlainTextEdit>
#include "tablewidget.h"
#include "chartwidget.h"
#include "./Model/training.h"

#include "./Model/run.h"
#include "./Model/cycling.h"
#include "./Model/tennis.h"
#include "./Model/rugby.h"
#include "./Model/walk.h"

#include "endurancedialog.h"
#include "repetitiondialog.h"
#include "trainingvalues.h"
#include "action.h"
#include "selecttrainingdialog.h"

class Controller;

class chartViewer : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    QHBoxLayout* mainLayout;
    tableWidget* tableW;
    chartWidget* chartW;
    QDialog* dialog;
    const std::list<Training*>* trainings;
    void addMenu(QHBoxLayout* mainLayout);
    void findTraining(unsigned int &n, bool found, const QString& start);

public:
    explicit chartViewer(QWidget *parent = nullptr);

    void showWarning(const QString& message);
    QString showPathDialog();
    trainingValues showAddDialog();
    trainingValues showRemoveDialog();
    trainingValues showSetDialog();
    void setData(const std::list<Training*>* data);
    void showData();

signals:

};

#endif // CHARTVIEWER_H
