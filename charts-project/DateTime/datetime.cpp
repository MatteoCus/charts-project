#include "datetime.h"

DateTime::DateTime()
    :date(1,1,2000), time(){}

DateTime::DateTime(const Date& d, const TimeStamp& t)
    :date(d), time(t){}

//possible throws --> catched outside of the creation of DateTime

const unsigned int DateTime::hoursPerDay = 24;

void DateTime::setTime(const TimeStamp& t){
    if(t.getHours()>= 24)
        throw std::invalid_argument("Invalid hour set");
    try {
        time.setTime(t.getHours(), t.getMinutes(), t.getSeconds());
    }  catch (std::invalid_argument& e) {
        throw e;
    }
}

void DateTime::setDate(const Date& d){
    try {
        date.setDate(d.getDay(), d.getMonth(), d.getYear());
    }  catch (DateException& e) {
        throw e;
    }

}

Date DateTime::getDate() const {return date;}

TimeStamp DateTime::getTime() const {return time;}

void DateTime::setDateTime(const Date& date, const TimeStamp& time){
    try {
        setDate(date);
        setTime(time);
    }  catch(DateException& ex){
        throw ex;
    }
    catch (std::invalid_argument& e) {
        throw e;
    }

}

DateTime DateTime::operator+(const TimeSpan& addTime) const{
    TimeSpan t = time + addTime;
    Date d = date;
    if(t.getHours() >= hoursPerDay)
    {
        d += t.getHours()/hoursPerDay;
        t.setTime(t.getHours() % hoursPerDay, t.getMinutes(), t.getSeconds());
    }
    return DateTime(d, t);
}

DateTime DateTime::operator-(const TimeSpan& subTime) const{
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

bool DateTime::operator!=(const DateTime& dateTime) const{
    return !operator==(dateTime);
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
