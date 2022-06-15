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

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/images/jogging.png"));
    Model* m = new Model();
    chartViewer* w = new chartViewer();
    Controller* c = new Controller();
    c->setModel(m);
    c->setView(w);
    w->setController(c);
    if(c->startView())
        return a.exec();
    else
        return 0;
}
