#ifndef DateTimeConverter_H
#define DateTimeConverter_H

#include "QDateTime"
#include "datetime.h"

class DateTimeConverter
{
public:
    explicit DateTimeConverter() = delete;
    explicit DateTimeConverter(const DateTimeConverter&) = delete;

    /**
     * @brief toDateTime:                ritorna un DateTime equivalente al QDateTime in ingresso
     * @param dateTime:                  oggetto data-ora di tipo QDateTime in ingresso
     * @return DateTime:                 data-ora di tipo DateTime equivalente al QDateTime in ingresso
     */
    static DateTime toDateTime(const QDateTime& dateTime) ;

    /**
     * @brief toQDateTime:               ritorna un QDateTime equivalente al DateTime in ingresso
     * @param dateTime:                  oggetto data-ora di tipo DateTime in ingresso
     * @return QDateTime:                data-ora di tipo QDateTime equivalente al DateTime in ingresso
     */
    static QDateTime toQDateTime(const DateTime& dateTime) ;

    /**
     * @brief toDate:                ritorna un Date equivalente al QDate in ingresso
     * @param date:                  oggetto data di tipo QDate in ingresso
     * @return Date:                 data di tipo Date equivalente al QDate in ingresso
     */
    static Date toDate(const QDate& date) ;

    /**
     * @brief toQDate:               ritorna un QDate equivalente al Date in ingresso
     * @param date:                  oggetto data di tipo Date in ingresso
     * @return QDate:                data di tipo QDate equivalente al Date in ingresso
     */
    static QDate toQDate(const Date& date) ;

    /**
     * @brief toTime:                ritorna un Time equivalente al QTime in ingresso
     * @param time:                  oggetto orario di tipo QTime in ingresso
     * @return Time:                 orario di tipo Time equivalente al QTime in ingresso
     */
    static Time toTime(const QTime& time) ;

    /**
     * @brief toQTime:               ritorna un QTime equivalente al Time in ingresso
     * @param time:                  oggetto orario di tipo Time in ingresso
     * @return QTime:                orario di tipo QTime equivalente al Time in ingresso
     */
    static QTime toQTime(const TimeSpan& time) ;
};

#endif // DateTimeConverter_H
