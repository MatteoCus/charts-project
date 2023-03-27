#ifndef TRAINING_H
#define TRAINING_H

#include "DateTime/datetime.h"
#include "DateTime/timespan.h"
#include <stdexcept>

class Training {
private:
    //Nome dell'allenamento
    std::string name;

    //Data (con orario) di inizio allenamento
    DateTime start;

protected:

    //Peso corporeo medio, utile per alcune metriche derivate dell'allenamento
    static const double avgWeight;

public:

    /**
     * @brief Training: costruisce un allenamento con nome generico e data uguale a "01/01/2000 00:00:00"
     */
    Training();

    /**
     * @brief Training:                 costruisce un allenamento usando nome e data di inizio indicati
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     * @throw std::invalid_argument:    se la data inserita non è valida o se il nome è nullo
     */
    Training(const std::string &name, const DateTime &start);

    /**
     * @brief getDuration:              restituisce la durata dell'allenamento
     * @return Timespan:                durata dell'allenamento
     */
    virtual TimeSpan getDuration() const = 0;

    /**
     * @brief CaloriesBurned:           restituisce il numero di calorie bruciate durante l'allenamento
     * @return unsigned int:            calorie bruciate
     */
    virtual unsigned int CaloriesBurned() const = 0;

    /**
     * @brief getName:              restituisce il nome dell'allenamento
     * @return std::string:         nome dell'allenamento
     */
    std::string getName() const;

    /**
     * @brief getStart:          restituisce la data (con ora) dell'inizio dell'allenamento
     * @return DateTime:         inizio dell'allenamento
     */
    DateTime getStart() const;

    /**
     * @brief getEnd:            restituisce la data (con ora) della fine dell'allenamento
     * @return DateTime:         fine dell'allenamento
     */
    DateTime getEnd() const;

    /**
     * @brief setName:                  imposta un nuovo nome all'allenamento
     * @param newName:                  nome dell'allenamento
     * @throw std::invalid_argument:    se il nome dell'allenamento è nullo
     */
    void setName(const std::string &newName);

    /**
     * @brief setStart:                 imposta una nuova data di inizio all'allenamento
     * @param newStart:                 data di inizio dell'allenamento
     */
    void setStart(const DateTime &newStart);

    /**
     * @brief clone:                    metodo per implementare il clonable pattern sulla gerarchia sottostante
     */
    virtual Training *clone() const = 0;

    /**
     * @brief ~Training:                 distruttore virtuale per la gerarchia sottostante
     */
    virtual ~Training() = default;
};

#endif // TRAINING_H
