#ifndef CHARTVIEWER_H
#define CHARTVIEWER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QDialog>
#include <QFileDialog>
#include <QFont>
#include <QPlainTextEdit>
#include "datawidget.h"
#include "chartwidget.h"
#include "./Model/training.h"
#include "adddialog.h"
#include "trainingvalues.h"
#include "action.h"

class chartViewer : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* mainLayout;
    dataWidget* dataW;
    chartWidget* chartW;
    QDialog* dialog;
    const std::vector<Training*>* trainings;
    void addMenu(QHBoxLayout* mainLayout);


public:
    explicit chartViewer(QWidget *parent = nullptr);

    void showWarning(const QString& message);
    QString showImportDialog();
    trainingValues showAddDialog();
    trainingValues showRemoveDialog();
    trainingValues showSetDialog();

signals:

};

#endif // CHARTVIEWER_H
