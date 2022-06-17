#ifndef RUGBY_H
#define RUGBY_H

#include "repetition.h"

class Rugby : public Repetition
{
public:

    /**
     * @brief Rugby:                    costruisce un allenamento con nome generico, data uguale a "01/01/2000 00:00",
     *                                  collezione vuota di esercizi
     */
    Rugby() = default;

    /**
     * @brief Rugby:                    costruisce un allenamento usando nome e data di inizio indicati, con collezione vuota di esercizi
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     */
    Rugby(const std::string &name, const DateTime& start);

    /**
     * @brief CaloriesBurned:           restituisce il numero di calorie bruciate durante l'allenamento
     * @return unsigned int:            calorie bruciate
     */
    unsigned int CaloriesBurned() const override;

    /**
     * @brief Intensity:            restituisce l'intensità dell'allenamento in percentuale
     * @return double:              intensità dell'allenamento in percentuale
     */
    double Intensity() const override;

    /**
     * @brief clone:                    metodo per implementare il clonable pattern sulla gerarchia sottostante
     */
    Rugby* clone() const override;
};

#endif // RUGBY_H
