#ifndef DIALOGVALUES_H
#define DIALOGVALUES_H

#include "trainingvalues.h"

class dialogValues : public trainingValues
{
public:

    //posizione relativa all'allenamento su cui intervenire
    int pos;

    //azione relativa all'esercizio su cui intervenire
    action exAct;

    //posizione relativa all'esercizio su cui intervenire
    int exPos;

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
     * @param pos:                      posizione dell'allenamento su cui intervenire
     * @param exAct:                    eventuale azione da effettuare sulla collezione di esercizi di un allenamento di ripetizione (all'esercizio indicato da exPos)
     * @param exPos:                    eventuale posizione dove modificare la collezione di esercizi di un allenamento di ripetizione
     */
    dialogValues(const QString& type, const QDateTime& start, const QString& name,double distance,
                 const QTime& duration,std::vector<QString> exName, std::vector<QTime> exDuration,
                 std::vector<QTime> exRecovery, int pos, action exAct, int exPos);
};

#endif // DIALOGVALUES_H
