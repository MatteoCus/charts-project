#include "datetime.h"

DateTime::DateTime()
    :date(1,1,2000), time(){}

DateTime::DateTime(const DateTime & datetime)
    :date(datetime.date), time(datetime.time){}

DateTime::DateTime(const Date& d, const Time& t)
    :date(d), time(t){}

const unsigned int DateTime::hoursPerDay = 24;

void DateTime::setTime(const Time& t){
    if(t.getHours()>= 24)
        throw std::invalid_argument("Tentativo di modifica di un orario usando un valore non valido!");
    time.setTime(t.getHours(), t.getMinutes(), t.getSeconds());
}

void DateTime::setDate(const Date& d){
    date.setDate(d.getDay(), d.getMonth(), d.getYear());
}

Date DateTime::getDate() const {return date;}

Time DateTime::getTime() const {return time;}

std::string DateTime::toString() const
{
    return date.toString() + " " + time.toString();
}

void DateTime::setDateTime(const Date& date, const Time& time){
    setDate(date);
    setTime(time);
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
