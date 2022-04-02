#include <QApplication>
#include <iostream>
#include <vector>
#include <list>
#include "DateTime/timespan.h"
#include "DateTime/date.h"
#include "DateTime/datetime.h"
#include "Model/model.h"
#include "View/chartviewer.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    chartViewer* w = new chartViewer();
    w->show();
    return a.exec();
}
