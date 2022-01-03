#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "timespan.h"
using namespace std;

int main(int argc, char *argv[])
{
    TimeSpan prova = TimeSpan();
    cout<<"Numero di secondi dalla mezzanotte: "<<prova.getTotalSeconds()<<endl
       <<"Orario impostato: "<<prova.getHours()<<":"<<prova.getMinutes()<<":"<<prova.getSeconds()<<endl;

    TimeSpan dodiciOre = TimeSpan(12);
    prova = prova + dodiciOre;

    cout<<"Numero di secondi dalla mezzanotte: "<<prova.getTotalSeconds()<<endl
       <<"Orario impostato: "<<prova.getHours()<<":"<<prova.getMinutes()<<":"<<prova.getSeconds()<<endl;

    try {
        dodiciOre.setTime(12,58,0);
    }  catch (std::invalid_argument e) {
        cerr<<e.what();
    }
    TimeSpan seiOre((dodiciOre/2));
    cout<<"Rapporto: "<<seiOre.getHours()<<":"<<seiOre.getMinutes()<<":"<<seiOre.getSeconds()<<endl;

    dodiciOre.setTime(12);
    TimeSpan ventiqOre((dodiciOre * 2));
    cout<<"Moltiplicazione: "<<ventiqOre.getHours()<<":"<<ventiqOre.getMinutes()<<":"<<ventiqOre.getSeconds()<<endl;
    TimeSpan diciottOre = ventiqOre - seiOre;
    cout<<"Sottrazione: "<<diciottOre.getHours()<<":"<<diciottOre.getMinutes()<<":"<<diciottOre.getSeconds()<<endl;

    if(ventiqOre == dodiciOre)
        cout<<"Primo confronto non ok"<<endl;
    else
        cout<<"Primo confronto ok"<<endl;
    if(ventiqOre != dodiciOre)
        cout<<"Secondo confronto ok"<<endl;
    else
        cout<<"Secondo confronto non ok"<<endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
