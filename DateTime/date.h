#ifndef DATE_H
#define DATE_H
#include <string>
class Date{
private:
    unsigned int day, month, year;
    static bool isLeap(unsigned int year);
    static bool checkDate(unsigned int day, unsigned int month, unsigned int year);
public:
    Date();
    Date(const Date& d)  = default;
    Date(unsigned int d, unsigned int m, unsigned int y);
    void setDate(unsigned int day, unsigned int month, unsigned int year);
    void setDay(unsigned int day);
    void setMonth(unsigned int month);
    void setYear(unsigned int year);
    unsigned int getDay() const;
    unsigned int getMonth() const;
    unsigned int getYear() const;
    std::string toString() const;
    Date operator+(unsigned int n) const;
    Date operator-(unsigned int n) const;
    void operator+=(unsigned int n);
    void operator-=(unsigned int n);
    Date operator++(int);
    Date& operator++();
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
};

#endif
