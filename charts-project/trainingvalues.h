#ifndef TRAININGVALUES_H
#define TRAININGVALUES_H

#include <QString>
#include <QTime>
#include <QDateTime>
#include <vector>
#include "action.h"

class trainingValues
{
public:

    //tipo dell'allenamento
    QString type;

    //data di inizio dell'allenamento
    QDateTime start;

    //nome dell'allenamento
    QString name;

    //distanza dell'allenamento
    double distance;

    //durata dell'allenamento
    QTime duration;

    //nomi degli esecizi dell'allenamento
    std::vector<QString> exName;

    //durate degli esecizi dell'allenamento
    std::vector<QTime> exDuration;

    //recuperi degli esecizi dell'allenamento
    std::vector<QTime> exRecovery;

    /**
     * @brief dialogValues:             costruttore di un oggetto di appoggio per i dati raccolti dai dialog
     * @param type:                     tipo dell'allenamento
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     * @param distance:                 distanza percorsa durante l'allenamento
     * @param duration:                 durata dell'allenamento
     * @param exName:                   puntatore ad una collezione di nomi per nuovi esercizi
     * @param exDuration:               puntatore ad una collezione di durate per nuovi esercizi
     * @param exRecovery:               puntatore ad una collezione di durate di recupero per nuovi esercizi
     */
    trainingValues(const QString& type, const QDateTime& start, const QString& name,double distance,
                   const QTime& duration,std::vector<QString> exName, std::vector<QTime> exDuration,
                   std::vector<QTime> exRecovery);
};

#endif // TRAININGVALUES_H
