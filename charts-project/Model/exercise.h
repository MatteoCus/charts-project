#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <stdexcept>
#include "DateTime/timespan.h"

class Exercise
{
private:
    //Nome dell'esercizio
    std::string name;

    //Durata dell'esercizio
    TimeSpan duration;

    //Tempo di recupero dell'esercizio
    TimeSpan recovery;
public:

    /**
     * @brief Exercise:               costruisce un esercizio con nome, durata e recupero non nulli
     */
    Exercise();

    /**
     * @brief Exercise:                 costruisce un esercizio usando nome, durata e recupero indicati
     * @param name:                     nome dell'esercizio
     * @param duration:                 durata dell'esercizio
     * @param recovery:                 recupero dell'esercizio
     */
    Exercise(const std::string& name, const TimeSpan& duration, const TimeSpan& recovery);

    /**
     * @brief getName:              restituisce il nome dell'esercizio
     * @return std::string:         nome dell'esercizio
     */
    std::string getName() const;

    /**
     * @brief getDuration:       restituisce la durata dell'esercizio
     * @return TimeSpan:         durata dell'esercizio
     */
    TimeSpan getDuration() const;

    /**
     * @brief getRecovery:       restituisce il recupero dell'esercizio
     * @return TimeSpan:         recupero dell'esercizio
     */
    TimeSpan getRecoveryTime() const;

    /**
     * @brief setName:                  imposta un nuovo nome all'esercizio
     * @param name:                     nome dell'esercizio
     * @throw std::invalid_argument:    se il nome dell'esercizio è nullo
     */
    void setName(const std::string& name);

    /**
     * @brief setDuration:              imposta una nuova durata all'esercizio
     * @param duration:                 durata dell'esercizio
     * @throw std::invalid_argument:    se la durata dell'esercizio è nulla
     */
    void setDuration(const TimeSpan& duration);

    /**
     * @brief setRecovery:              imposta un nuovo recupero all'esercizio
     * @param recovery:                 recupero dell'esercizio
     * @throw std::invalid_argument:    se il recupero dell'esercizio è nullo
     */
    void setRecovery(const TimeSpan& recovery);

    /**
     * @brief clone:                    metodo per implementare il clonable pattern sulla gerarchia sottostante
     */
    virtual Exercise* clone() const;

    /**
     * @brief ~Exercise:                distruttore virtuale per la gerarchia sottostante
     */
    virtual ~Exercise() = default;
};

#endif // EXERCISE_H
