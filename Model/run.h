#ifndef RUN_H
#define RUN_H

#include "endurance.h"

class Run : public Endurance
{
public:

    /**
     * @brief Run: costruisce un allenamento con nome generico, data uguale a "01/01/2000 00:00", distanza e durata entrambe non nulle
     */
    Run() = default;

    /**
     * @brief Run:                      costruisce un allenamento usando nome, data di inizio, distanza e durata indicati
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     * @param distance:                 distanza percorsa durante l'allenamento
     * @param duration:                 durata dell'allenamento
     * @throw std::invalid_argument:    se la distanza o la durata sono nulle
     */
    Run(const std::string &name, const DateTime& start, double distance, const TimeSpan& duration);

    /**
     * @brief CaloriesBurned:           restituisce il numero di calorie bruciate durante l'allenamento
     * @return unsigned int:            calorie bruciate
     */
    unsigned int CaloriesBurned() const override;

    /**
     * @brief clone:                    metodo per implementare il clone pattern sulla gerarchia sottostante
     */
    Run* clone() const override;
};

#endif // RUN_H
