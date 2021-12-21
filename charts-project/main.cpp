#include "mainwindow.h"

#include <QApplication>

//cose per testing
#include <iostream>
#include <string>
#include "tennis.h"
#include "rugby.h"
#include "cycling.h"
#include "run.h"
#include "walk.h"
#include "exercise.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    std::vector<Exercise*> eserciziTennis;
    eserciziTennis.push_back(new Exercise("Riscaldamento", QTime(0,10), QTime(0,2)));
    eserciziTennis.push_back(new Exercise("Palleggio", QTime(0,20), QTime(0,5)));
    eserciziTennis.push_back(new Exercise("Servizio", QTime(0,30), QTime(0,10)));
    eserciziTennis.push_back(new Exercise("Volèè", QTime(0,30), QTime(0,5)));
    eserciziTennis.push_back(new Exercise("Partitella", QTime(1,0), QTime(0,10)));
    Tennis* first = new Tennis(QDateTime(QDate(2021, 12, 21)), 100);
    for(unsigned int i = 0; i < eserciziTennis.size() ; ++i)
        first->addExercise(eserciziTennis[i]);
    cout<<"Nell'allenamento, l'atleta ha bruciato "<< first->CaloriesBurned() <<" Calorie, con intensità del "<<first->Intensity()
       <<"% "<<endl;
    Tennis* second = new Tennis(*first);
    delete first;
    second->setWeight(50);
    try {
        second->removeExercise(4);
    }  catch (std::out_of_range e) {
        std::cerr<<e.what()<<std::endl;
    }

    cout<<"Nell'allenamento, l'atleta ha bruciato "<< second->CaloriesBurned() <<" Calorie, con intensità del "<<second->Intensity()
       <<"% "<<endl;
    delete second;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
