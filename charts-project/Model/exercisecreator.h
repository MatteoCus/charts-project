#ifndef EXERCISECREATOR_H
#define EXERCISECREATOR_H

#include "exercise.h"
#include "DateTime/timespan.h"
#include <string>

class exerciseCreator {
public:

    /**
     * @brief createExercise:           crea e ritorna un esercizio sulla base dei parametri in ingresso
     * @param name:                     nome per l'esercizio da creare
     * @param duration:                 durata per l'esercizio da creare
     * @param recovery:                 durata di recupero per l'esercizio da creare
     * @return Exercise*:               esercizio creato sulla base dei parametri in ingresso
     */
    static Exercise *createExercise(const std::string &name, const TimeSpan &duration,
                             const TimeSpan &recovery);
};

#endif // EXERCISECREATOR_H
