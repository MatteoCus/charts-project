#include "chartviewer.h"

chartViewer::chartViewer(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    dataWidget* dataW = new dataWidget(this);
    chartWidget* chartW = new chartWidget(this);
    mainLayout->setSpacing(40);
    mainLayout->addWidget(dataW);
    mainLayout->addWidget(chartW);
    mainLayout->setContentsMargins(10,90,10,20);
    setLayout(mainLayout);

    resize(1200,700);
    show();
}
