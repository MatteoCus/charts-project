#ifndef TENNIS_H
#define TENNIS_H

#include "repetition.h"

class Tennis : public Repetition
{

protected:
    //parametro per il calcolo delle calorie bruciate durante l'allenamento
    static const double c1;

    //parametro per il calcolo dell'intensità dell'allenamento
    static const unsigned int c2;
public:

    /**
     * @brief Tennis:                   costruisce un allenamento con nome generico, data uguale a "01/01/2000 00:00",
     *                                  collezione vuota di esercizi
     */
    Tennis() = default;

    /**
     * @brief Tennis:                   costruisce un allenamento usando nome e data di inizio indicati, con collezione vuota di esercizi
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     */
    Tennis(const std::string &name, const DateTime& start);

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
    Tennis* clone() const override;
};

#endif // TENNIS_H
