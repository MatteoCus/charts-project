#ifndef DATAWIDGET_H
#define DATAWIDGET_H

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

class dataWidget : public QWidget
{
    Q_OBJECT
    void adaptTable(unsigned int w, unsigned int h, QTableWidget* table);
    void addTable(QVBoxLayout* tableLayout);
    void addLabel(QVBoxLayout* tableLayout);
    void addLabelTable(QHBoxLayout* mainLayout);
    void addControls(QHBoxLayout* mainLayout);

public:
    explicit dataWidget(QWidget *parent = nullptr);

signals:

};

#endif // DATAWIDGET_H
