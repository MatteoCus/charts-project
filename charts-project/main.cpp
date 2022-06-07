#include <QApplication>
#include <iostream>
#include <vector>
#include <list>
#include "DateTime/timespan.h"
#include "DateTime/date.h"
#include "DateTime/datetime.h"
#include "Model/model.h"
#include "View/chartviewer.h"
#include "Controller/controller.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/jogging.png"));
    chartViewer w;
    Controller c;
    Model m;
    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);
    w.show();
    return a.exec();
}
