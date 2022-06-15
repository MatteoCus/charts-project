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
#include "./Model/exercise.h"

#include "endurancedialog.h"
#include "repetitiondialog.h"
#include "dialogvalues.h"
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
    QMenuBar* menuBar;
    QMenu *file, *visualizza, *allenamenti;
    const std::list<Training*>* trainings;
    void addMenu(QHBoxLayout* mainLayout);
    void findTraining(unsigned int &n, const QDateTime& start);

private slots:
    void showExercises();
    void showChart();

public:
    explicit chartViewer(QWidget *parent = nullptr);
    void setController(Controller* c);
    void showWarning(const QString& message);
    dialogValues showAddDialog();
    dialogValues showRemoveDialog();
    dialogValues showSetDialog();
    void setData(const std::list<Training*>* data);
    void showData();

signals:
    void addTrainings() const;
    void setTrainings() const;
    void removeTrainings() const;
    void save() const;
    void saveAs() const;
    void newPlan() const;
    void open() const;
};

#endif // CHARTVIEWER_H
