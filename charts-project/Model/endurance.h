#ifndef ENDURANCE_H
#define ENDURANCE_H

#include "training.h"

class Endurance : public Training
{
private:
    //distanza percorsa durante l'allenamento
    double distance;

    //durata dell'allenamento
    TimeSpan duration;
public:
    /**
     * @brief Endurance: costruisce un allenamento con nome generico, data uguale a "01/01/2000 00:00",
     *                  distanza e durata entrambe non nulle
     */
    Endurance();

    /**
     * @brief Endurance:                costruisce un allenamento usando nome, data di inizio, distanza e durata indicati
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     * @param distance:                 distanza percorsa durante l'allenamento
     * @param duration:                 durata dell'allenamento
     * @throw std::invalid_argument:    se la distanza o la durata sono nulle
     */
    Endurance(const std::string &name, const DateTime& start, double distance, const TimeSpan& duration);

    /**
     * @brief getDistance:       restituisce la distanza percorsa durante l'allenamento
     * @return double:           distanza percorsa durante l'allenamento
     */
    double getDistance() const;

    /**
     * @brief getDuration:              restituisce la durata dell'allenamento
     * @return Timespan:                durata dell'allenamento
     */
    TimeSpan getDuration() const override;

    /**
     * @brief setDistance:              imposta una nuova distanza percorsa durante l'allenamento
     * @param distance:                 distanza percorsa durante l'allenamento
     */
    void setDistance(double distance);

    /**
     * @brief setDuration:              imposta una nuova durata di allenamento
     * @param duration:                 durata dell'allenamento
     */
    void setDuration(const TimeSpan& duration);

    /**
     * @brief ~Endurance:                 distruttore virtuale per la gerarchia sottostante
     */
    virtual ~Endurance() = default;
};

#endif // ENDURANCE_H
