#ifndef DATE_H
#define DATE_H
#include <string>
class Date{
private:

    //rispettivamente giorno, mese ed anno della data
    unsigned int day, month, year;

    /**
     * @brief isLeap:                   ritorna un booleano che indica se l'anno in ingresso è bisestile
     * @param year:                     anno da valutare
     * @return bool:                    booleano che indica se l'anno in ingresso è bisestile
     */
    static bool isLeap(unsigned int year);

    /**
     * @brief checkDate:                ritorna un booleano che indica se i valori in ingresso possono costituire una data valida
     * @param day:                      giorno della data da valutare
     * @param month:                    mese della data da valutare
     * @param year:                     anno della data da valutare
     * @return bool:                    booleano che indica se i valori in ingresso possono costituire una data valida
     */
    static bool checkDate(unsigned int day, unsigned int month, unsigned int year);
public:

    /**
     * @brief Date:                 costruisce la data "01/01/2000"
     */
    Date();

    /**
     * @brief Date:                     costruisce una data basandosi su giorno, mese ed anno in input
     * @param day:                      giorno della data da costruire
     * @param month:                    mese della data da costruire
     * @param year:                     anno della data da costruire
     * @throw std::invalid_argument:    se la data non è valida
     */
    Date(unsigned int day, unsigned int month, unsigned int year);

    /**
     * @brief setDate:                  modifica una data basandosi su giorno, mese ed anno in input
     * @param day:                      giorno della data da modificare
     * @param month:                    mese della data da modificare
     * @param year:                     anno della data da modificare
     * @throw std::invalid_argument:    se la data non è valida
     */
    void setDate(unsigned int day, unsigned int month, unsigned int year);

    /**
     * @brief setDay:                   modifica il giorno di una data
     * @param day:                      giorno della data da modificare
     * @throw std::invalid_argument:    se la data non è valida
     */
    void setDay(unsigned int day);

    /**
     * @brief setMonth:                 modifica il mese di una data
     * @param month:                    mese della data da modificare
     * @throw std::invalid_argument:    se la data non è valida
     */
    void setMonth(unsigned int month);

    /**
     * @brief setYear:                  modifica l'anno di una data
     * @param year:                     anno della data da modificare
     * @throw std::invalid_argument:    se la data non è valida
     */
    void setYear(unsigned int year);

    /**
     * @brief getDay:               restituisce il giorno della data
     * @return unsigned int:        giorno della data
     */
    unsigned int getDay() const;

    /**
     * @brief getMonth:             restituisce il mese della data
     * @return unsigned int:        mese della data
     */
    unsigned int getMonth() const;

    /**
     * @brief getYear:              restituisce l'anno della data
     * @return unsigned int:        anno della data
     */
    unsigned int getYear() const;

    /**
     * @brief toString:             restituisce una stringa che rappresenta la data in formato "dd/MM/yyyy"
     * @return std::string:         stringa che rappresenta la data in formato "dd/MM/yyyy"
     */
    std::string toString() const;

    /**
     * @brief operator+:              restituisce una data equivalente alla data attuale a cui sono sommati "n" giorni
     * @param n:                      numero di giorni da aggiungere alla data attuale
     * @return TimeSpan:              data equivalente alla data attuale a cui sono sommati "n" giorni
     */
    Date operator+(unsigned int n) const;

    /**
     * @brief operator-:              restituisce una data equivalente alla data attuale a cui sono sottratti "n" giorni
     * @param n:                      numero di giorni da sottrarre alla data attuale
     * @return TimeSpan:              data equivalente alla data attuale a cui sono sottratti "n" giorni
     */
    Date operator-(unsigned int n) const;

    /**
     * @brief operator+=:             aggiunge alla data attuale "n" giorni
     * @param n:                      numero di giorni da aggiungere alla data attuale
     */
    void operator+=(unsigned int n);

    /**
     * @brief operator-=:            sottrae alla data attuale "n" giorni
     * @param n:                     numero di giorni da sottrarre alla data attuale
     */
    void operator-=(unsigned int n);

    /**
     * @brief operator++:            operatore ++ postfisso
     */
    Date operator++(int);

    /**
     * @brief operator++:            operatore ++ prefisso
     */
    Date& operator++();

    /**
     * @brief operator==:               ritorna un booleano che indica se la data attuale e la data in ingresso sono uguali
     * @param date:                     data in ingresso
     * @return bool:                    booleano che indica se la data attuale e la data in ingresso sono uguali
     */
    bool operator==(const Date& date) const;

    /**
     * @brief operator==:               ritorna un booleano che indica se la data attuale e la data in ingresso sono diverse
     * @param date:                     data in ingresso
     * @return bool:                    booleano che indica se la data attuale e la data in ingresso sono diverse
     */
    bool operator!=(const Date& date) const;

    /**
     * @brief operator<:                ritorna un booleano che indica se la data attuale è minore della data in ingresso
     * @param date:                     data in ingresso
     * @return bool:                    booleano che indica se la data attuale è minore della data in ingresso
     */
    bool operator<(const Date& date) const;

    /**
     * @brief operator>:                ritorna un booleano che indica se la data attuale è maggiore della data in ingresso
     * @param date:                     data in ingresso
     * @return bool:                    booleano che indica se la data attuale è maggiore della data in ingresso
     */
    bool operator>(const Date& date) const;

    /**
     * @brief operator<=:               ritorna un booleano che indica se la data attuale è minore o uguale della data in ingresso
     * @param date:                     data in ingresso
     * @return bool:                    booleano che indica se la data attuale è minore o uguale della data in ingresso
     */
    bool operator<=(const Date& date) const;

    /**
     * @brief operator>=:               ritorna un booleano che indica se la data attuale è maggiore o uguale della data in ingresso
     * @param date:                     data in ingresso
     * @return bool:                    booleano che indica se la data attuale è maggiore o uguale della data in ingresso
     */
    bool operator>=(const Date& date) const;
};

#endif
