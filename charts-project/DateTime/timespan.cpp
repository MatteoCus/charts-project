#include "timespan.h"

TimeSpan::TimeSpan(unsigned int h, unsigned int m, unsigned int s)
    : sec((m < 60 && s < 60)
              ? h * secInHour + m * secInMinute + s
              : throw std::invalid_argument("Invalid timespan inserted")) {}

const unsigned int TimeSpan::secPerDay = secInHour * 24;

const unsigned int TimeSpan::secInHour = 3600;

const unsigned int TimeSpan::secInMinute = 60;

unsigned int TimeSpan::getTotalMinutes() const { return sec / secInMinute; }

unsigned int TimeSpan::getTotalSeconds() const { return sec; }

unsigned int TimeSpan::getHours() const { return sec / secInHour; }

unsigned int TimeSpan::getMinutes() const {
  return (sec % secInHour) / secInMinute;
}

unsigned int TimeSpan::getSeconds() const { return sec % secInMinute; }

void TimeSpan::setTime(unsigned int h, unsigned int m, unsigned int s) {
  sec = (m < 60 && s < 60)
            ? h * secInHour + m * secInMinute + s
            : throw std::invalid_argument("Invalid timespan setted");
}

bool TimeSpan::isNull() const { return sec == 0; }

TimeSpan TimeSpan::operator+(const TimeSpan &time) const {
  unsigned int totSec = sec + time.sec;
  unsigned int h = totSec / secInHour, m = (totSec % secInHour) / secInMinute,
               s = totSec % secInMinute;
  return TimeSpan(h, m, s);
}

TimeSpan TimeSpan::operator-(const TimeSpan &time) const {
  if (sec < time.sec)
    throw std::invalid_argument(
        "Invalid operation: timestamp subtraction has a negative result");
  unsigned int totSec = sec - time.sec;
  unsigned int h = totSec / secInHour, m = (totSec % secInHour) / secInMinute,
               s = totSec % secInMinute;
  return TimeSpan(h, m, s);
}

TimeSpan TimeSpan::operator*(unsigned int n) const {
  unsigned int totSec = sec * n;
  unsigned int h = totSec / (secInHour), m = (totSec % secInHour) / secInMinute,
               s = totSec % secInMinute;
  return TimeSpan(h, m, s);
}

TimeSpan TimeSpan::operator/(double n) const {
  if (n > 0) {
    unsigned int totSec = sec / n;
    unsigned int h = totSec / (secInHour),
                 m = (totSec % secInHour) / secInMinute,
                 s = totSec % secInMinute;
    return TimeSpan(h, m, s);
  }
  throw std::invalid_argument("Division by 0 with a time length");
}

double TimeSpan::operator/(const TimeSpan &time) const {
  return sec / time.sec;
}

bool TimeSpan::operator==(const TimeSpan &time) const {
  return sec == time.sec;
}

bool TimeSpan::operator!=(const TimeSpan &time) const {
  return sec != time.sec;
}

bool TimeSpan::operator<(const TimeSpan &time) const {
  return sec < time.getTotalSeconds();
}

bool TimeSpan::operator>(const TimeSpan &time) const {
  return sec > time.getTotalSeconds();
}

bool TimeSpan::operator<=(const TimeSpan &time) const {
  return sec <= time.getTotalSeconds();
}

bool TimeSpan::operator>=(const TimeSpan &time) const {
  return sec >= time.getTotalSeconds();
}
