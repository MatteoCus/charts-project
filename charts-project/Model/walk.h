#ifndef WALK_H
#define WALK_H

#include "endurance.h"

class Walk : public Endurance
{
public:

    /**
     * @brief Walk: costruisce un allenamento con nome generico, data uguale a "01/01/2000 00:00", distanza e durata entrambe non nulle
     */
    Walk() = default;

    /**
     * @brief Walk:                      costruisce un allenamento usando nome, data di inizio, distanza e durata indicati
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     * @param distance:                 distanza percorsa durante l'allenamento
     * @param duration:                 durata dell'allenamento
     * @throw std::invalid_argument:    se la distanza o la durata sono nulle
     */
    Walk(const std::string &name, const DateTime& start, double distance, const TimeSpan& duration);

    /**
     * @brief CaloriesBurned:           restituisce il numero di calorie bruciate durante l'allenamento
     * @return unsigned int:            calorie bruciate
     */
    unsigned int CaloriesBurned() const override;

    /**
     * @brief clone:                    metodo per implementare il clonable pattern sulla gerarchia sottostante
     */
    Walk* clone() const override;
};

#endif // WALK_H
