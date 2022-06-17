#ifndef REPETITION_H
#define REPETITION_H

#include "exercise.h"
#include "training.h"
#include <string>
#include <vector>

using std::string;

class Repetition : public Training {
private:
    //collezione di esercizi effettuati durante un allenamento
    std::vector<Exercise *> exercises;

    /**
     * @brief copy:                     costruisce una lista di puntatori ad esercizi equivalenti a quelli dell'allenamento passato in ingresso
     * @param repTraining:              allenamento di ripetizione da cui copiare la collezione di esercizi
     * @return std::vector<Exercise *>: lista di puntatori ad esercizi equivalenti a quelli dell'allenamento passato in ingresso
     */
    static std::vector<Exercise *> *copy(const Repetition &repTraining);

    /**
     * @brief destroy:                  dealloca gli esercizi dell'allenamento passato in ingresso
     * @param repTraining:              allenamento di ripetizione a cui deallocare la collezione di esercizi
     */
    static void destroy(const Repetition &repTraining);

    /**
     * @brief isEmpty:                  ritorna un booleano che indica se l'allenamento ha almeno un esercizio
     * @return bool:                    indica se l'allenamento ha almeno un esercizio
     */
    bool isEmpty() const;
public:
    /**
     * @brief Repetition:               costruisce un allenamento con nome generico, data uguale a "01/01/2000 00:00",
     *                                  collezione vuota di esercizi
     */
    Repetition() = default;

    /**
     * @brief Repetition:               costruisce un allenamento usando nome e data di inizio indicati, con collezione vuota di esercizi
     * @param name:                     nome dell'allenamento
     * @param start:                    data di inizio dell'allenamento
     */
    Repetition(const std::string &name, const DateTime &start);

    /**
     * @brief addExercise:           accoda il puntatore ad un nuovo esercizio nella collezione di esercizi
     * @param exercise:              puntatore ad un nuovo esercizio
     */
    void addExercise(Exercise *exercise);

    /**
     * @brief addExercise:          inserisce il puntatore ad un nuovo esercizio nella collezione di esercizi
     * @param position:             posizione in cui inserire il nuovo esercizio nella collezione di esercizi
     * @param exercise:             puntatore ad un nuovo esercizio
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     */
    void insertExercise(unsigned int position, Exercise *exercise);

    /**
     * @brief removeExercise:       rimuove il puntatore ad un esercizio (deallocandolo) dalla collezione di esercizi
     * @param position:             posizione in cui rimuovere un esercizio dalla collezione di esercizi
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     */
    void removeExercise(unsigned int position);

    /**
     * @brief getExercise:          ritorna il puntatore ad un esercizio dalla collezione di esercizi
     * @param position:             posizione da cui ottenere il puntatore ad un esercizio dalla collezione di esercizi
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     * @return Exercise*:           puntatore ad un esercizio dalla collezione di esercizi
     */
    Exercise *getExercise(unsigned int position) const;

    /**
     * @brief getExercises:                 restituisce la collezione di puntatori agli esercizi
     * @return std::vector<Exercise *>:     collezione di puntatori agli esercizi
     */
    std::vector<Exercise *> getExercises() const;

    /**
     * @brief setExercise:          modifica un esercizio della collezione
     * @param position:             posizione in cui modificare un esercizio dalla collezione di esercizi
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     */
    void setExercise(unsigned int position, Exercise *ex);

    /**
     * @brief getSize:           restituisce il numero di esercizi presenti nella collezione di esercizi
     * @return unsigned int:     numero di esercizi presenti nella collezione di esercizi
     */
    unsigned int getSize() const;

    /**
     * @brief totalRecovery:            restituisce la durata totale del recupero dell'allenamento, è la somma dei recuperi dei singoli esercizi
     * @return Timespan:                durata totale del recupero dell'allenamento
     */
    TimeSpan totalRecovery() const;

    /**
     * @brief getDuration:              restituisce la durata dell'allenamento
     * @return Timespan:                durata dell'allenamento
     */
    TimeSpan getDuration() const override;

    /**
     * @brief Intensity:            restituisce l'intensità dell'allenamento in percentuale
     * @return double:              intensità dell'allenamento in percentuale
     */
    virtual double Intensity() const = 0;

    /**
     * @brief Repetition:            costruttore di copia profonda
     * @param repTraining:           allenamento di ripetizione da cui copiare la collezione di esercizi, il nome e la data di inizio
     */
    Repetition(const Repetition &repTraining);

    /**
     * @brief operator=:             operatore di assegnazione ridefinito
     * @param repTraining:           allenamento di ripetizione da cui copiare la collezione di esercizi, il nome e la data di inizio
     * @return Repetition&:          riferimento all'allenamento appena modificato
     */
    Repetition &operator=(const Repetition &repTraining);

    /**
     * @brief ~Repetition:                 distruttore virtuale per la gerarchia sottostante
     */
    virtual ~Repetition();
};

#endif // REPETITION_H
