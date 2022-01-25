#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <vector>
#include <list>
#include "DateTime/timespan.h"
#include "DateTime/date.h"
#include "DateTime/dateexception.h"
#include "DateTime/datetime.h"
#include "Model/model.h"
#include "View/chartwidget.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    chartWidget w;
    return a.exec();
}
