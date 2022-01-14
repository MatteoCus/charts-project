#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QGraphicsEffect>
#include <QSizePolicy>

class dataWidget : public QWidget
{
    Q_OBJECT
public:
    explicit dataWidget(QWidget *parent = nullptr);

signals:

};

#endif // DATAWIDGET_H
