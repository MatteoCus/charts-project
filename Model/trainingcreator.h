#ifndef TRAININGCREATOR_H
#define TRAININGCREATOR_H

#include "cycling.h"
#include "DateTime/datetime.h"
#include "rugby.h"
#include "run.h"
#include "tennis.h"
#include "walk.h"
#include <stdexcept>
#include <string>
#include <vector>

class trainingCreator {
public:

    /**
     * @brief createTraining:           crea e ritorna un allenamento sulla base dei parametri in ingresso
     * @param type:                     tipo dell'allenamento da creare
     * @param name:                     nome dell'allenamento da creare
     * @param start:                    data di inizio dell'allenamento da creare
     * @param distance:                 distanza percorsa durante l'allenamento da creare
     * @param duration:                 durata dell'allenamento da creare
     * @param exName:                   puntatore ad una collezione di nomi per nuovi esercizi da creare
     * @param exDuration:               puntatore ad una collezione di durate per nuovi esercizi da creare
     * @param exRecovery:               puntatore ad una collezione di durate di recupero per nuovi esercizi da creare
     * @throw std::invalid_argument:    se i parametri passati contengono degli errori a livello logico
     * @return Training*:               allenamento creato sulla base dei parametri in ingresso
     */
    static Training *createTraining(const std::string &type, const std::string &name,
                             const DateTime &start, double distance = 0.0,
                             TimeSpan duration = TimeSpan(),
                             const std::vector<std::string>* exName = nullptr,
                             const std::vector<TimeSpan>* exDuration = nullptr,
                             const std::vector<TimeSpan>* exRecovery = nullptr);
};

#endif // TRAININGCREATOR_H
