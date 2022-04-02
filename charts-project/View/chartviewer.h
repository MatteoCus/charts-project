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
#include "adddialog.h"
#include "addvalues.h"

class chartViewer : public QWidget
{
    Q_OBJECT
private:
    QHBoxLayout* mainLayout;
    dataWidget* dataW;
    chartWidget* chartW;
    QDialog* dialog;
    void addMenu(QHBoxLayout* mainLayout);


public:
    explicit chartViewer(QWidget *parent = nullptr);

    void showWarning(const QString& message);
    QString showImportDialog();
    addValues showAddDialog();

signals:

};

#endif // CHARTVIEWER_H
