#include "date.h"
#include <stdexcept>

Date::Date()
    : day(1), month(1), year(2000) {}

Date::Date(unsigned int d, unsigned int m, unsigned int y)
    : day(checkDate(d,m,y)? d : throw std::invalid_argument("Invalid date inserted!")),
        month(m), year(y) {}

bool Date::isLeap(unsigned int year){
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}

bool Date::checkDate(unsigned int day, unsigned int month, unsigned int year){
  if (day < 1 || day > 31 || month < 1 || month > 12
    || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
    || (month == 2 && isLeap(year) && day > 29)
    || (month == 2 && !isLeap(year) && day > 28))
        return false;
    return true;
}

void Date::setDate(unsigned int d, unsigned int m, unsigned int y){
    if(checkDate(d,m,y)){
        day  = d;
        month = m;
        year = y;
    }
    else
        throw std::invalid_argument("Invalid date inserted!");
}

void Date::setDay(unsigned int d){
    if(checkDate(d,month,year))
        day  = d;
    else
        throw std::invalid_argument("Invalid date inserted!");
}

void Date::setMonth(unsigned int m){
    if(checkDate(day,m,year))
        month = m;
    else
        throw std::invalid_argument("Invalid date inserted!");
}

void Date::setYear(unsigned int y){
    if(checkDate(day,month,y))
        year = y;
    else
        throw std::invalid_argument("Invalid date inserted!");
}

unsigned int Date::getDay() const { return day;}

unsigned int Date::getMonth() const { return month;}

unsigned int Date::getYear() const { return year;}

Date Date::operator+(unsigned int n) const{ //n è il numero di giorni
    if(checkDate(day + n, month, year))
        return Date(day + n, month, year);
    unsigned int d = day + n, m = month, y = year;
    while (!checkDate(d,m,y)){
        if(m == 4 || m == 6 || m == 9 || m == 11){
            d -=30;
            m++; 
        }
        else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8
                || m == 10 || m == 12){
                    d -= 31;
                    if(m == 12){
                        m = 1;
                        y++;
                    }
                    else{
                        m++;
                    }
                }
        else{   //m == 2
            m++;
            if(isLeap(y))
                d -= 29;
            else
                d -=28;
        }
    }
    return Date(d,m,y);
}

Date Date::operator-(unsigned int n) const{
    if(checkDate(day - n, month, year))
        return Date(day - n, month, year);
    unsigned int d = day - n, m = month, y = year;
    while (!checkDate(d,m,y)){
        if(m == 5 || m == 7 || m == 10 || m == 12){
            d +=30;
            m--; 
        }
        else if(m == 1 || m == 2 || m == 4 || m == 6 || m == 8
                || m == 9 || m == 11){
                    d += 31;
                    if(m == 1){
                        m = 12;
                        y--;
                    }
                    else{
                        m--;
                    }
                }
        else{   //m == 3
            m--;
            if(isLeap(y))
                d += 29;
            else
                d +=28;
        }
    }
    return Date(d,m,y);
}

void Date::operator+=(unsigned int n){
    *this = *this + n;
}

void Date::operator-=(unsigned int n){
    *this = *this - n;
}

Date& Date::operator++(){
    *this = *this +1;
    return *this;
}

Date Date::operator++(int){
    Date aux(*this);
    *this = *this +1;
    return aux;
}

bool Date::operator==(const Date& d) const{
    return year == d.year && month == d.month && day == d.day;
}

bool Date::operator!=(const Date& d) const{
    return !(this->operator==(d));
}

bool Date::operator<(const Date& d) const{
    return (year < d.year || (year == d.year && month < d.month)
            || (year == d.year && month == d.month && day < d.day));
}

bool Date::operator>(const Date& d) const{
    return !(this->operator<(d));
}

bool Date::operator<=(const Date& d) const{
    return this->operator==(d) || this->operator<(d);
}

bool Date::operator>=(const Date& d) const{
    return this->operator==(d) || this->operator>(d);
}
