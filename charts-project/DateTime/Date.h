#ifndef DATE_H
#define DATE_H

#include <ctime>
#include <sstream>

#include "dateexception.h"

//! Classe di gestione data
/*!
        Classe rappresentate una data dd/mm/yy
*/
class Date {
private:
  std::tm date; /*!< Contiene le info grezze sulla data */
  void clear();
  void check_date(int day, int month, int year);
  bool is_leap(int year);

public:
  Date();
  Date(const Date &date_obj);
  Date(int day, int month, int year);
  Date(const std::string &iso_string);
  ~Date();
  void setDate(int day, int month, int year);
  void setDate(const std::string &iso_string);
  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);
  std::string getDate() const;
  int getDay() const;
  int getMonth() const;
  int getYear() const;
  int operator-(const Date &date_obj);
  Date operator+(int n);
  void operator+=(int n);
  void operator++();
  bool operator==(const Date&) const;
  bool operator<(const Date&) const;
  bool operator>(const Date&) const;
  bool operator<=(const Date&) const;
  bool operator>=(const Date&) const;
  void today();
  Date operator=(const Date &date_obj);
};

#endif
