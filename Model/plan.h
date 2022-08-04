#ifndef PLAN_H
#define PLAN_H

#include "action.h"
#include "DateTime/datetime.h"
#include "endurance.h"
#include "exercisecreator.h"
#include "repetition.h"
#include "training.h"
#include <list>
#include <vector>
#include <string>

class Plan {
private:

    //collezione di puntatori ad allenamenti: gli allenamenti sono memorizzati in ordine temporale (invariante per ogni operazione
    //  su questa collezione) e tra di essi non ci possono essere sovrapposizioni; la loro durata deve essere <= 20 ore, il numero
    //  di esercizi compreso tra 1 e 15 e le durate ed i nomi devono essere non nulli.
    std::list<Training *> trainings;

    /**
     * @brief copy:                     costruisce una lista di puntatori ad allenamenti equivalenti a quelli del piano passato in ingresso
     * @param plan:                     piano di allenamenti da cui copiare la collezione di allenamenti
     * @return std::list<Training *>:   collezione di puntatori ad allenamenti equivalenti a quelli del piano passato in ingresso
     */
    static std::list<Training *> copy(const Plan &plan);

    /**
     * @brief destroy:                  dealloca gli allenamenti del piano passato in ingresso
     * @param plan:                     piano di allenamenti a cui deallocare la collezione di allenamenti
     */
    static void destroy(const Plan &plan);

    /**
     * @brief check:                    ritorna un booleano che indica se l'allenamento in ingresso è corretto in base ai vincoli (sopra)
     * @param training:                 allenamento da valutare
     * @throw std::invalid_argument:
     * @return bool:                    booleano che indica se l'allenamento in ingresso è corretto in base ai vincoli di programma
     */
    bool check(Training *training);

public:

    /**
     * @brief Plan:                 costruisce il piano di allenamenti vuoto (senza alcun allenamento nella collezione)
     */
    Plan() = default;

    /**
     * @brief insertTraining:           inserisce il puntatore ad un nuovo allenamento nella collezione di allenamenti rispettando i vincoli (sopra)
     * @param training:                 allenamento da inserire
     * @throw std::invalid_argument:    se l'allenamento non rispetta i vincoli di programma
     */
    void insertTraining(Training *training);

    /**
     * @brief removeTraining:           rimuove il puntatore (e dealloca) l'allenamento richiesto dalla collezione di allenamenti rispettando i vincoli (sopra)
     * @param pos:                      posizione dell'allenamento da rimuovere
     * @throw std::out_of_range:        se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     */
    void removeTraining(unsigned int pos);

    /**
     * @brief getTraining:          ritorna il puntatore ad un allenamento dalla collezione di allenamenti
     * @param position:             posizione da cui ottenere il puntatore ad un allenamento dalla collezione di allenamenti
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     * @return Training*:           puntatore ad un allenamneto dalla collezione di allenamenti
     */
    Training *getTraining(unsigned int position) const;

    /**
     * @brief getTrainings:                 restituisce il puntatore alla collezione di puntatori agli allenamenti
     * @return std::list<Training *>*:      puntatore alla collezione di puntatori agli allenamenti
     */
    const std::list<Training *>* getTrainings() const;

    /**
     * @brief getSize:           restituisce il numero di allenamenti presenti nella collezione di allenamenti
     * @return unsigned int:     numero di allenamenti presenti nella collezione di allenamenti
     */
    unsigned int getSize() const;

    /**
     * @brief isEmpty:                  ritorna un booleano che indica se il piano di allenamenti ha almeno un allenamento
     * @return bool:                    indica se il piano di allenamenti ha almeno un allenamento
     */
    bool isEmpty() const;

    /**
     * @brief clear:                 svuota la collezione di puntatori agli allenamenti, deallocandoli
     */
    void clear();

    /**
     * @brief setTraining:              modifica un allenamento sulla base dei parametri in ingresso
     * @param position:                 posizione dell'allenamento da modificare
     * @param name:                     nome per l'allenamento da modificare
     * @param start:                    data di inizio per l'allenamento da modificare
     * @param distance:                 distanza percorsa per l'allenamento da modificare
     * @param duration:                 durata per l'allenamento da modificare
     * @param exPos:                    eventuale posizione dove modificare la collezione di esercizi di un allenamento di ripetizione
     * @param action:                   eventuale azione da effettuare sulla collezione di esercizi di un allenamento di ripetizione (all'esercizio indicato da exPos)
     * @param exName:                   puntatore ad una collezione di nomi per nuovi esercizi da modificare
     * @param exDuration:               puntatore ad una collezione di durate per nuovi esercizi da modificare
     * @param exRecovery:               puntatore ad una collezione di durate di recupero per nuovi esercizi da modificare
     * @throw std::out_of_range:        se la posizione passata non è valida (minore di 0 o maggiore della dimensione della collezione)
     * @throw std::invalid_argument:    se i dati in ingresso non sono corretti
     */
    void setTraining(unsigned int position, const std::string &name, const DateTime &start,
                     double distance = 0.0, const TimeSpan &duration = TimeSpan(),
                     unsigned int exPos = 0, action operation = nothing,
                     const std::vector<std::string>* exName = nullptr,
                     const std::vector<TimeSpan>* exDuration = nullptr,
                     const std::vector<TimeSpan>* exRecovery = nullptr);

    /**
     * @brief Plan:           costruttore di copia profonda
     * @param plan:           piano di allenamenti da cui copiare la collezione di allenamenti
     */
    Plan(const Plan &plan);

    /**
     * @brief operator=:             operatore di assegnazione ridefinito
     * @param plan:                  piano di allenamenti da cui copiare la collezione di allenamenti
     * @return Plan&:                riferimento al piano di allenamenti appena modificato
     */
    Plan &operator=(const Plan &plan);

    /**
     * @brief ~Plan:                 distruttore profondo
     */
    ~Plan();
};

#endif // PLAN_H
