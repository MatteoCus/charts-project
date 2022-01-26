#ifndef CHARTVIEWER_H
#define CHARTVIEWER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include "datawidget.h"
#include "chartwidget.h"

class chartViewer : public QWidget
{
    Q_OBJECT
public:
    explicit chartViewer(QWidget *parent = nullptr);

signals:

};

#endif // CHARTVIEWER_H
