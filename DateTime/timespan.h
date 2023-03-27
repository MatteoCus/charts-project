#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <stdexcept>
#include "string"

class TimeSpan {
private:

    //numero di secondi totali che intercorrono tra 00:00:00 (durata o orario) e la durata/orario da modellare
    unsigned int sec;

    //costante che indica il numero di secondi al giorno
    static const unsigned int secPerDay;

    //costante che indica il numero di secondi in un'ora
    static const unsigned int secInHour;

    //costante che indica il numero di secondi al minuto
    static const unsigned int secInMinute;

public:

    /**
     * @brief TimeSpan:                 costruisce un orario/durata usando le ore, i minuti ed i secondi in input
     * @param hours:                    ore dell'orario/durata
     * @param minutes:                  minuti dell'orario/durata
     * @param seconds:                  secondi dell'orario/durata
     * @throw std::invalid_argument:    se l'orario/durata non è valida
     */
    explicit TimeSpan(unsigned int hours = 0, unsigned int minutes = 0,
                      unsigned int seconds = 0);

    /**
     * @brief getHours:             restituisce l'ora dell'orario/durata
     * @return unsigned int:        ora dell'orario/durata
     */
    unsigned int getHours() const;

    /**
     * @brief getMinutes:           restituisce i minuti dell'orario/durata
     * @return unsigned int:        minuti dell'orario/durata
     */
    unsigned int getMinutes() const;

    /**
     * @brief getSeconds:           restituisce i secondi dell'orario/durata
     * @return unsigned int:        secondi dell'orario/durata
     */
    unsigned int getSeconds() const;

    /**
     * @brief setTime:                  modifica un orario/durata usando le ore, i minuti ed i secondi in input
     * @param hours:                    ore dell'orario/durata
     * @param minutes:                  minuti dell'orario/durata
     * @param seconds:                  secondi dell'orario/durata
     * @throw std::invalid_argument:    se l'orario/durata non è valida
     */
    void setTime(unsigned int hours, unsigned int minutes = 0,
                 unsigned int seconds = 0);

    /**
     * @brief setSeconds:               modifica un orario/durata usando i secondi in ingresso
     * @param seconds:                  secondi dell'orario/durata
     * @throw std::invalid_argument:    se l'orario/durata non è valida
     */
    void setSeconds(unsigned int seconds);
    /**
     * @brief setMinutes:               modifica un orario/durata usando i minuti in ingresso
     * @param minutes:                  minuti dell'orario/durata
     * @throw std::invalid_argument:    se l'orario/durata non è valida
     */
    void setMinutes(unsigned int minutes);

    /**
     * @brief setHours:                 modifica un orario/durata usando le ore in ingresso
     * @param hours:                    ore dell'orario/durata
     */
    void setHours(unsigned int hours);

    /**
     * @brief getTotalMinutes:      restituisce i minuti totale dell'orario/durata
     * @return unsigned int:        minuti totali dell'orario/durata
     */
    unsigned int getTotalMinutes() const;

    /**
     * @brief getTotalSeconds:      restituisce i secondi totale dell'orario/durata
     * @return unsigned int:        secondi totali dell'orario/durata
     */
    unsigned int getTotalSeconds() const;

    /**
     * @brief isNull:               restituisce un booleano che indica se l'orario/durata è nullo o meno
     * @return bool:                indica se l'orario/durata è nullo o meno
     */
    bool isNull() const;

    /**
     * @brief toString:             restituisce una stringa che rappresenta l'orario/durata in formato "hh:mm:ss"
     * @return std::string:         stringa che rappresenta l'orario/durata in formato "hh:mm:ss"
     */
    std::string toString() const;

    /**
     * @brief operator+:                ritorna un orario/durata che è la somma dell'orario/durata attuale e una durata in ingresso
     * @param time:                     durata in ingresso
     * @return TimeSpan:                orario/durata che è la somma dell'orario/durata attuale e un orario/durata in ingresso
     */
    TimeSpan operator+(const TimeSpan &time) const;

    /**
     * @brief operator-:                ritorna un orario/durata che è la differenza dell'orario/durata attuale e una durata in ingresso
     * @param time:                     durata in ingresso
     * @throw std::invalid_argument:    se la durata calcolata non è valida (ex. durata negativa)
     * @return TimeSpan:                orario/durata che è la differenza dell'orario/durata attuale e un orario/durata in ingresso
     */
    TimeSpan operator-(const TimeSpan &time) const;

    /**
     * @brief operator*:                ritorna una durata che è il prodotto della durata attuale e un moltiplicatore in ingresso
     * @param n:                        moltiplicatore in ingresso
     * @return TimeSpan:                durata che è il prodotto della durata attuale e un moltiplicatore in ingresso
     */
    TimeSpan operator*(unsigned int n) const;

    /**
     * @brief operator/:                ritorna una durata che è il quoziente della durata attuale e un divisore in ingresso
     * @param n:                        divisore in ingresso
     * @throw std::invalid_argument:    se il divisore è negativo
     * @return TimeSpan:                durata che è il quoziente della durata attuale e un divisore in ingresso
     */
    TimeSpan operator/(double n) const;

    /**
     * @brief operator/:                ritorna una durata che è il quoziente della durata attuale e una durata in ingresso
     * @param time:                     orario/durata in ingresso
     * @return TimeSpan:                durata che è il quoziente della durata attuale e una durata in ingresso
     */
    double operator/(const TimeSpan &time) const;

    /**
     * @brief operator==:               ritorna un booleano che indica se l'orario/durata attuale e l'orario/durata in ingresso sono uguali
     * @param time:                     orario/durata in ingresso
     * @return bool:                    booleano che indica se l'orario/durata attuale e l'orario/durata in ingresso sono uguali
     */
    bool operator==(const TimeSpan &time) const;

    /**
     * @brief operator!=:               ritorna un booleano che indica se l'orario/durata attuale e l'orario/durata in ingresso sono diversi
     * @param time:                     orario/durata in ingresso
     * @return bool:                    booleano che indica se l'orario/durata attuale e l'orario/durata in ingresso sono diversi
     */
    bool operator!=(const TimeSpan &time) const;

    /**
     * @brief operator<:                ritorna un booleano che indica se l'orario/durata attuale è minore dell'orario/durata in ingresso
     * @param time:                     orario/durata in ingresso
     * @return bool:                    booleano che indica se l'orario/durata attuale è minore dell'orario/durata in ingresso
     */
    bool operator<(const TimeSpan &time) const;

    /**
     * @brief operator>:                ritorna un booleano che indica se l'orario/durata attuale è maggiore dell'orario/durata in ingresso
     * @param time:                     orario/durata in ingresso
     * @return bool:                    booleano che indica se l'orario/durata attuale è maggiore dell'orario/durata in ingresso
     */
    bool operator>(const TimeSpan &time) const;

    /**
     * @brief operator<=:               ritorna un booleano che indica se l'orario/durata attuale è minore o uguale all'orario/durata in ingresso
     * @param time:                     orario/durata in ingresso
     * @return bool:                    booleano che indica se l'orario/durata attuale è minore o uguale all'orario/durata in ingresso
     */
    bool operator<=(const TimeSpan &time) const;

    /**
     * @brief operator>=:               ritorna un booleano che indica se l'orario/durata attuale è maggiore o uguale all'orario/durata in ingresso
     * @param time:                     orario/durata in ingresso
     * @return bool:                    booleano che indica se l'orario/durata attuale è maggiore o uguale all'orario/durata in ingresso
     */
    bool operator>=(const TimeSpan &time) const;
};

#endif // TIMESPAN_H
