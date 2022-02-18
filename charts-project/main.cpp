#include <QApplication>
#include <iostream>
#include <vector>
#include <list>
#include "DateTime/timespan.h"
#include "DateTime/Date.h"
#include "DateTime/DateException.h"
#include "DateTime/datetime.h"
#include "Model/model.h"
#include "View/mainwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    mainWindow * w = new mainWindow();
    return a.exec();
}
