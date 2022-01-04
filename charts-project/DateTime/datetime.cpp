#include "datetime.h"

DateTime::DateTime()
    :date(1,1,2000), time(){}

DateTime::DateTime(const Date& d, const TimeStamp& t)
    :date(d), time(t){}

DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year,
                   unsigned int hours, unsigned int minutes, unsigned int seconds)
    : date(day,month, year), time(hours, minutes, seconds){}

//possible throws --> catched outside of the creation of DateTime

const unsigned int DateTime::hoursPerDay = 24;

void DateTime::setTime(unsigned int hours, unsigned int minutes, unsigned int seconds){
    if(hours >= 24)
        throw std::invalid_argument("Invalid hour set");
    try {
        time.setTime(hours, minutes, seconds);
    }  catch (std::invalid_argument& e) {
        throw e;
    }
}

void DateTime::setDate(unsigned int day, unsigned int month, unsigned int year){
    try {
        date.setDate(day, month, year);
    }  catch (DateException& e) {
        throw e;
    }

}

Date DateTime::getDate() const {return date;}

TimeStamp DateTime::getTime() const {return time;}

void DateTime::setDateTime(unsigned int day, unsigned int month, unsigned int year,
                           unsigned int hours, unsigned int minutes, unsigned int seconds){
    try {
        setDate(day, month, year);
        setTime(hours, minutes, seconds);
    }  catch(DateException& ex){
        throw ex;
    }
    catch (std::invalid_argument& e) {
        throw e;
    }

}

DateTime DateTime::operator+(const TimeSpan& addTime){
    TimeSpan t = time + addTime;
    Date d = date;
    if(t.getHours() >= hoursPerDay)
    {
        d += t.getHours()/hoursPerDay;
        t.setTime(t.getHours() % hoursPerDay, t.getMinutes(), t.getSeconds());
    }
    return DateTime(d, t);
}

DateTime DateTime::operator-(const TimeSpan& subTime){
    Date d = date;
    TimeSpan t = time;
    if(t < subTime)
    {
        while (t < subTime)
        {
            d += -1;
            t = t + TimeSpan(24);
        }
     }
    t = t - subTime;
    return DateTime(d,t);
}

bool DateTime::operator==(const DateTime& dateTime) const{
    return (date == dateTime.getDate()) && (time == dateTime.getTime());
}

bool DateTime::operator<(const DateTime& dateTime) const{
    return (date < dateTime.getDate()) || (date == dateTime.getDate() && (time < dateTime.getTime()));
}

bool DateTime::operator>(const DateTime& dateTime) const{
    return !operator<(dateTime) && !operator==(dateTime);
}
bool DateTime::operator<=(const DateTime& dateTime) const{
    return !operator>(dateTime);
}
bool DateTime::operator>=(const DateTime& dateTime) const{
    return !operator<(dateTime);
}
