#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "DateTime/timespan.h"
#include "DateTime/date.h"
#include "DateTime/dateexception.h"
#include "DateTime/datetime.h"

using namespace std;

int main(int argc, char *argv[])
{
    DateTime d;
    d.setDateTime(DateTime(Date(15,12,2020), TimeStamp(15,15)));
    d = d + TimeSpan(15,16);
    cout<<d.getDate().getDate()<<" "<<d.getTime().getHours()<<":"<<d.getTime().getMinutes()
       <<":"<<d.getTime().getSeconds()<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
