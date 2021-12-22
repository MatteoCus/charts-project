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
    std::vector<Exercise*> eserciziRugby;
    eserciziRugby.push_back(new Exercise("Riscaldamento", QTime(0,10), QTime(0,2)));
    eserciziRugby.push_back(new Exercise("Passaggi", QTime(0,20), QTime(0,5)));
    eserciziRugby.push_back(new Exercise("Placcaggio", QTime(0,20), QTime(0,5)));
    eserciziRugby.push_back(new Exercise("Mischia", QTime(0,30), QTime(0,10)));
    eserciziRugby.push_back(new Exercise("Rimessa", QTime(0,30), QTime(0,10)));
    eserciziRugby.push_back(new Exercise("Partitella", QTime(1,0), QTime(0,15)));
    Rugby* first = new Rugby(QDateTime(QDate(2021, 12, 21)), 90);
    first->setStart(QDateTime(QDate(2021, 12, 21), QTime(16,00)));
    for(unsigned int i = 0; i < eserciziRugby.size() ; ++i)
        first->addExercise(eserciziRugby[i]);
    cout<<"Nell'allenamento, l'atleta ha bruciato "<< first->CaloriesBurned() <<" Calorie, con intensita' del "<<first->Intensity()
       <<"% in "<<first->getExercisesNumber()<<" esercizi"<<endl;
    Tennis* f = new Tennis(QDateTime(QDate(2021, 12, 22), QTime(15,0)), 75);
    f->addExercise(new Exercise("Dritto", QTime(0,30), QTime(0,8)));
    f->addExercise(new Exercise("Rovescio", QTime(0,30), QTime(0,11)));
    cout<<"Nell'allenamento, l'atleta ha bruciato "<< f->CaloriesBurned() <<" Calorie, con intensita' del "<<f->Intensity()
       <<"% in "<<f->getExercisesNumber()<<" esercizi"<<endl;
    Tennis* s = new Tennis(*f);
    delete f;
    s->setWeight(55);
    Run* run;
    try{
    run = new Run(QDateTime(QDate(2021, 12, 23), QTime(15,0)), 75);
    run->setDistance(12.10);
    run->setDuration(QTime(1,12));
    }
    catch(std::invalid_argument e)
    {
        std::cerr<<e.what()<<endl;
    }
    Cycling* walk = nullptr;
    try{
        walk = new Cycling(QDateTime(QDate(2021, 12, 23), QTime(15,0)), 75);
        walk->setDistance(100);
        walk->setDuration(QTime(2,03));
    }
    catch(std::invalid_argument e)
    {
        std::cerr<<e.what()<<endl;
    }

    cout<<"Nell'allenamento, l'atleta ha bruciato "<< walk->CaloriesBurned() <<" Calorie, tenendo un passo di "<<walk->Pace().minute()<<
          ":"<<walk->Pace().second()<<" su 10 chilometri"<<endl;

    delete run;
    std::vector<Training*> schedule;
    schedule.push_back(first);
    schedule.push_back(s);
    schedule.push_back(walk);
    cout<<"Peso atleta: "<<schedule[0]->getWeight()<<", calorie perse nel primo allenamento: "<<schedule[0]->CaloriesBurned()<<", inizio alle "<<schedule[0]->getStart().time().hour()<<":"
       <<schedule[0]->getStart().time().minute()<<" e fine alle "<<schedule[0]->end().time().hour()<<":"
      <<schedule[0]->end().time().minute()<<endl;
    cout<<"Peso atleta: "<<schedule[1]->getWeight()<<", calorie perse nel secondo allenamento: "<<schedule[1]->CaloriesBurned()<<", con inizio alle "<<schedule[1]->getStart().time().hour()<<":"
       <<schedule[1]->getStart().time().minute()<<" e fine alle "<<schedule[1]->end().time().hour()<<":"
      <<schedule[1]->end().time().minute()<<endl;
    cout<<"Peso atleta: "<<schedule[2]->getWeight()<<", calorie perse nel terzo allenamento: "<<schedule[2]->CaloriesBurned()<<", con inizio alle "<<schedule[2]->getStart().time().hour()<<":"
       <<schedule[2]->getStart().time().minute()<<" e fine alle "<<schedule[2]->end().time().hour()<<":"
      <<schedule[2]->end().time().minute()<<endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
