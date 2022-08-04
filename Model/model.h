#ifndef MODEL_H
#define MODEL_H

#include "action.h"
#include "exercisecreator.h"
#include "plan.h"
#include "training.h"
#include "trainingcreator.h"
#include <string>
#include <vector>

class Model {
private:

    //puntatore al piano di allenamenti, che contiene una collezione di allenamenti
    Plan *plan;

public:

    /**
     * @brief Model:                 costruisce il piano di allenamenti
     */
    Model();

    /**
     * @brief addNewTraining:           aggiunge al piano e fa creare ad una classe apposita un allenamento sulla base dei parametri in ingresso
     * @param type:                     tipo dell'allenamento da creare
     * @param name:                     nome dell'allenamento da creare
     * @param start:                    data di inizio dell'allenamento da creare
     * @param distance:                 distanza percorsa durante l'allenamento da creare
     * @param duration:                 durata dell'allenamento da creare
     * @param exName:                   puntatore ad una collezione di nomi per nuovi esercizi da creare
     * @param exDuration:               puntatore ad una collezione di durate per nuovi esercizi da creare
     * @param exRecovery:               puntatore ad una collezione di durate di recupero per nuovi esercizi da creare
     * @throw std::invalid_argument:    se i parametri passati contengono degli errori a livello logico
     */
    void addNewTraining(const std::string &type, const std::string &name,
                        const DateTime &start, double distance = 0.0,
                        const TimeSpan &duration = TimeSpan(),
                        const std::vector<std::string>* exName = nullptr,
                        const std::vector<TimeSpan>* exDuration = nullptr,
                        const std::vector<TimeSpan>* exRecovery = nullptr) const;

    /**
     * @brief removeTraining:           rimuove l'allenamento richiesto dal piano di allenamenti
     * @param pos:                      posizione dell'allenamento da rimuovere
     * @throw std::out_of_range:        se la posizione passata non è valida (minore di 0 o maggiore della dimensione del piano di allenamenti)
     */
    void removeTraining(unsigned int pos) const;

    /**
     * @brief getTraining:          ritorna il puntatore ad un allenamento del piano di allenamenti
     * @param position:             posizione da cui ottenere il puntatore ad un allenamento del piano di allenamenti
     * @throw std::out_of_range:    se la posizione passata non è valida (minore di 0 o maggiore della dimensione del piano di allenamenti)
     * @return Training*:           puntatore ad un allenamneto dal piano di allenamenti
     */
    Training *getTraining(unsigned int pos) const;

    /**
     * @brief getTrainings:                 restituisce il puntatore alla collezione di puntatori agli allenamenti
     * @return std::list<Training *>*:      puntatore alla collezione di puntatori agli allenamenti
     */
    const std::list<Training *>* getTrainings() const;

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
    void setTraining(unsigned int pos, const std::string &name, const DateTime &start,
                     double distance = 0.0, const TimeSpan &duration = TimeSpan(),
                     unsigned int exPos = 0, action operation = nothing,
                     const std::vector<std::string>* exName = nullptr,
                     const std::vector<TimeSpan>* exDuration = nullptr,
                     const std::vector<TimeSpan>* exRecovery = nullptr) const;

    /**
     * @brief getPlanSize:       restituisce il numero di allenamenti presenti nella collezione di allenamenti
     * @return unsigned int:     numero di allenamenti presenti nella collezione di allenamenti
     */
    unsigned int getPlanSize() const;

    /**
     * @brief isEmpty:                  ritorna un booleano che indica se il piano di allenamenti ha almeno un allenamento
     * @return bool:                    indica se il piano di allenamenti ha almeno un allenamento
     */
    bool isEmpty() const;

    /**
     * @brief removeTrainings:                 svuota il piano di allenamenti
     */
    void removeTrainings() const;

    /**
     * @brief Model:           costruttore di copia profonda
     * @param model:           modello da cui copiare il piano di allenamenti
     */
    Model(const Model &model);

    /**
     * @brief operator=:              operatore di assegnazione ridefinito
     * @param model:                  modello da cui copiare il piano di allenamenti
     * @return Model&:                riferimento al modello appena modificato
     */
    Model &operator=(const Model &model);

    /**
     * @brief ~Model:                 distruttore profondo
     */
    ~Model();
};

#endif // MODEL_H
