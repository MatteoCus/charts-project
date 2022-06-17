#ifndef DATETIME_H
#define DATETIME_H

#include "timespan.h"
#include "date.h"
#include <stdexcept>

#define Time TimeSpan

class DateTime
{
private:

    //data della data-ora
    Date date;

    //orario della data-ora
    Time time;

    //costante che indica il numero di ore al giorno
    static const unsigned int hoursPerDay;

    /**
     * @brief setTime:                  modifica l'orario della data-ora usando un orario in ingresso
     * @param time:                     orario in ingresso
     * @throw std::invalid_argument:    se l'orario non è valida
     */
    void setTime(const Time& time);

    /**
     * @brief setDate:                  modifica la data della data-ora usando una data in ingresso
     * @param date:                     data in ingresso
     */
    void setDate(const Date& date);
public:

    /**
     * @brief DateTime:                  costruisce una data-ora uguale a "01/01/2000 00:00:00"
     */
    DateTime();

    /**
     * @brief DateTime:                 costruisce una data-ora usando la data e l'orario in ingresso
     * @param date:                     data in ingresso
     * @param time:                     orario in ingresso
     */
    DateTime(const Date& date, const Time& time);

    /**
     * @brief getDate:           restituisce la data della data-ora
     * @return Date:             data della data-ora
     */
    Date getDate() const;

    /**
     * @brief getTime:           restituisce l'orario della data-ora
     * @return Time:             orario della data-ora
     */
    Time getTime() const;

    /**
     * @brief toString:             restituisce una stringa che rappresenta la data-ora in formato "dd/MM/yyyy hh:mm:ss"
     * @return std::string:         stringa che rappresenta la data-ora in formato "dd/MM/yyyy hh:mm:ss"
     */
    std::string toString() const;

    /**
     * @brief setDateTime:              modifica la data-ora usando la data e l'orario in ingresso
     * @param date:                     data in ingresso
     * @param time:                     orario in ingresso
     */
    void setDateTime(const Date& date, const Time& time);

    /**
     * @brief operator+:                ritorna una data-ora che è la somma della data-ora attuale e una durata in ingresso
     * @param time:                     durata in ingresso
     * @return DateTime:                data-ora che è la somma della data-ora attuale e una durata in ingresso
     */
    DateTime operator+(const TimeSpan& time) const;

    /**
     * @brief operator-:                ritorna una data-ora che è la differenza della data-ora attuale e una durata in ingresso
     * @param time:                     durata in ingresso
     * @return DateTime:                data-ora che è la differenza della data-ora attuale e una durata in ingresso
     */
    DateTime operator-(const TimeSpan& time) const;

    /**
     * @brief operator==:               ritorna un booleano che indica se la data-ora attuale e la data-ora in ingresso sono uguali
     * @param dateTime:                 data-ora in ingresso
     * @return bool:                    booleano che indica se la data-ora attuale e la data-ora in ingresso sono uguali
     */
    bool operator==(const DateTime& dateTime) const;

    /**
     * @brief operator!=:               ritorna un booleano che indica se la data-ora attuale e la data-ora in ingresso sono diverse
     * @param dateTime:                 data-ora in ingresso
     * @return bool:                    booleano che indica se la data-ora attuale e la data-ora in ingresso sono diverse
     */
    bool operator!=(const DateTime& dateTime) const;

    /**
     * @brief operator<:                ritorna un booleano che indica se la data-ora attuale è minore della data-ora in ingresso
     * @param dateTime:                 data-ora in ingresso
     * @return bool:                    booleano che indica se la data-ora attuale è minore della data-ora in ingresso
     */
    bool operator<(const DateTime& dateTime) const;

    /**
     * @brief operator>:                ritorna un booleano che indica se la data-ora attuale è maggiore della data-ora in ingresso
     * @param dateTime:                 data-ora in ingresso
     * @return bool:                    booleano che indica se la data-ora attuale è maggiore della data-ora in ingresso
     */
    bool operator>(const DateTime& dateTime) const;

    /**
     * @brief operator<:                ritorna un booleano che indica se la data-ora attuale è minore o uguale della data-ora in ingresso
     * @param dateTime:                 data-ora in ingresso
     * @return bool:                    booleano che indica se la data-ora attuale è minore o uguale della data-ora in ingresso
     */
    bool operator<=(const DateTime& dateTime) const;

    /**
     * @brief operator>:                ritorna un booleano che indica se la data-ora attuale è maggiore o uguale della data-ora in ingresso
     * @param dateTime:                 data-ora in ingresso
     * @return bool:                    booleano che indica se la data-ora attuale è maggiore o uguale  della data-ora in ingresso
     */
    bool operator>=(const DateTime& dateTime) const;
};

#endif // DATETIME_H
