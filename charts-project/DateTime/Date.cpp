#include "date.h"

/*! \brief Costruttore di default

        Azzera gli elementi della struct tm che non servono
        e setta la data a 1/1/1900
*/
Date::Date() { clear(); }

/*! \brief Costruttore di copia

        Accetta un'istanza di Date e ne copia
        gli attributi. Non effettua controlli di coerenza

        \param date_obj Oggetto Date passata come argomento
*/
Date::Date(const Date &date_obj) {
  clear();
  this->date.tm_mday = date_obj.date.tm_mday;
  this->date.tm_mon = date_obj.date.tm_mon;
  this->date.tm_year = date_obj.date.tm_year;
}

/*! \brief Costruttore con parametri


        Accetta tre parametri costituenti una data
        ed effettua un controllo sulla consistenza
        della data

        \param day giorno della data
        \param month mese della data
        \param year anno della data

        \exception DateException componenti della data non coerenti (rethrow)
*/
Date::Date(int day, int month, int year) {

  try {
    check_date(day, month, year);
    clear();
    this->date.tm_mday = day;
    this->date.tm_mon = month - 1;
    this->date.tm_year = year - 1900;
  } catch (DateException &ex) {
    throw ex;
  }
}

/*! \brief Costruttore con parametri

        Riceve una stringa ISO 8601 YYYY-MM-DD e ne estrae i componenti,
        eseguendo anche un controllo di coerenza

        \param iso_string data nel formato ISO 8601 YYYY-MM-DD

        \exception DateException Componenti della data non coerenti (rethrow)
*/
Date::Date(const std::string &iso_string) {
  try {
    if (iso_string.size() != 10)
      throw std::invalid_argument("Bad formatted string");

    std::stringstream ss_day;
    std::stringstream ss_month;
    std::stringstream ss_year;
    int day;
    int month;
    int year;

    ss_year << iso_string.substr(0, 4);
    ss_year >> year;

    ss_month << iso_string.substr(5, 2);
    ss_month >> month;

    ss_day << iso_string.substr(8, 2);
    ss_day >> day;

    check_date(day, month, year);
    clear();
    this->date.tm_mday = day;
    this->date.tm_mon = month - 1;
    this->date.tm_year = year - 1900;
  } catch (DateException &ex) {
    throw ex;
  }
}

/*! \brief Distruttore di classe

        Non ha nessun compito
*/
Date::~Date() {}

/*! \brief Setter per la data

        Riceve le componenti della data e le setta,
        eseguendo anche un controllo di coerenza

        \param day giorno della data
        \param month mese della data
        \param year anno della data

        \exception DateException Componenti della data non coerenti (rethrow)
*/
void Date::setDate(int day, int month, int year) {
  try {
    check_date(day, month, year);
    clear();
    this->date.tm_mday = day;
    this->date.tm_mon = month - 1;
    this->date.tm_year = year - 1900;
  } catch (DateException &ex) {
    throw ex;
  }
}

/*! \brief Setter per la data

        Riceve una stringa ISO 8601 YYYY-MM-DD e ne estrae i componenti,
        eseguendo anche un controllo di coerenza

        \param iso_string data nel formato ISO 8601 YYYY-MM-DD

        \exception DateException Componenti della data non coerenti (rethrow)
*/
void Date::setDate(const std::string &iso_string) {
  try {
    if (iso_string.size() != 10)
      throw DateException("Bad formatted string",
                          DateException::STRING_INVALID_FORMAT);

    std::stringstream ss_day;
    std::stringstream ss_month;
    std::stringstream ss_year;
    int day;
    int month;
    int year;

    ss_year << iso_string.substr(0, 4);
    ss_year >> year;

    ss_month << iso_string.substr(5, 2);
    ss_month >> month;

    ss_day << iso_string.substr(8, 2);
    ss_day >> day;

    check_date(day, month, year);
    clear();
    this->date.tm_mday = day;
    this->date.tm_mon = month - 1;
    this->date.tm_year = year - 1900;
  } catch (DateException &ex) {
    throw ex;
  }
}

/*! \brief Setter per il giorno

        Riceve un giorno, effettua un controllo di coerenza
        e setta il giorno

        \param day giorno della data

        \exception DateException giorno della data non coerente (rethrow)
*/
void Date::setDay(int day) {
  try {
    check_date(day, this->date.tm_mon + 1, this->date.tm_year + 1900);
    this->date.tm_mday = day;
  } catch (DateException &ex) {
    throw ex;
  }
}

/*! \brief Setter per il mese

        Riceve un mese, effettua un controllo di coerenza
        e setta il mese

        \param month mese della data

        \exception DateException mese della data non coerente (rethrow)
*/
void Date::setMonth(int month) {
  try {
    check_date(this->date.tm_mday, month, this->date.tm_year + 1900);
    this->date.tm_mon = month - 1;
  } catch (DateException &ex) {
    throw ex;
  }
}

/*! \brief Setter per l'anno

        Riceve un anno, effettua un controllo di coerenza
        e setta l'anno

        \param year anno della data

        \exception DateException anno della data non coerente (rethrow)
*/
void Date::setYear(int year) {
  try {
    check_date(this->date.tm_mday, this->date.tm_mon + 1, year);
    this->date.tm_year = year - 1900;
  } catch (DateException &ex) {
    throw ex;
  }
}

/*! \brief Getter per la data

        \return Stringa nella forma dd/mm/yy
*/
std::string Date::getDate() const {
  std::ostringstream ss;
  ss << this->getDay() << "/" << this->getMonth() << "/" << this->getYear();
  return ss.str();
}

/*! \brief Getter per il giorno

        \return giorno della data
*/
int Date::getDay() const { return this->date.tm_mday; }

/*! \brief Getter per il mese

        \return mese della data
*/
int Date::getMonth() const { return this->date.tm_mon + 1; }

/*! \brief Getter per l'anno

        \return anno della data
*/
int Date::getYear() const { return this->date.tm_year + 1900; }

/*! \brief Operatore di sottrazione

        Sottrae due date, restituendo il numero di
        giorni che intercorre tra le due date

        \param date_obj Oggetto Date da cui sottrarre

        \return giorni di differenza tra le date
*/
int Date::operator-(const Date &date_obj) {
  std::time_t x = std::mktime(&this->date);
  std::time_t y = std::mktime((std::tm *)&date_obj.date);
  double diff = std::difftime(x, y) / (60 * 60 * 24);
  return (int)diff;
}

/*! \brief Somma n giorni alla data

        \param n giorni da sommare

        \return una nuova data, con i giorni sommati
*/
Date Date::operator+(int n) {
  Date retv = *this;

  retv.date.tm_mday += n;
  std::mktime(&retv.date);

  return retv;
}

/*! \brief Somma n giorni alla data

        \param n giorni da sommare
*/
void Date::operator+=(int n) {
  this->date.tm_mday += n;
  std::mktime(&this->date);
}

/*! \brief Incrementa la data di un giorno */
void Date::operator++() {
  this->date.tm_mday += 1;
  std::mktime(&this->date);
}
bool Date::operator==(const Date& date) const {
    return (getYear()==date.getYear()) && (getMonth()==date.getMonth()) && (getDay()==date.getDay());
}


bool Date::operator<(const Date& date) const{
    return (getYear() < date.getYear()) || (getYear() == date.getYear() && getMonth() < date.getMonth())
            || (getYear() == date.getYear() && getMonth() == date.getMonth() && getDay() < date.getDay());
}

bool Date::operator>(const Date& date) const {return !operator<(date) && !operator==(date);}

bool Date::operator<=(const Date& date) const {return !operator>(date);}

bool Date::operator>=(const Date& date) const {return !operator<(date);}


/*! \brief Metodo privato clear di resettaggio

        Azzera i dati inutili (secondi, minuti, ore)
        e setta la data a 1/1/1900
*/
void Date::clear() {
  this->date.tm_sec = 0;
  this->date.tm_min = 0;
  this->date.tm_hour = 1; // con 0 si impalla la somma
  this->date.tm_mday = 1;
  this->date.tm_mon = 0;
  this->date.tm_year = 0;
}

/*! \brief Metodo privato di controllo bisestile

        Controlla se un anno e' o meno bisestile

        \param year anno da testare

        \retval true Anno bisestile
        \retval false Annon non bisestile
*/
bool Date::is_leap(int year) {
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    return true;
  else
    return false;
}

/*! \brief Metodo privato di test date

        Controlla la coerenza delle componenti di
        una data. In particolare deve risultare:
        - day in [1,32]
        - month in [1,12]
        - year >= 1900
        - month in {4,6,9,11} -> day <= 30
        - month = 2 && is_leap(year) -> day <= 29
        - month = 2 && !is_leap(year) -> day <= 28

        altrimenti verra' lanciata un'eccezione

        \param day giorno della data
        \param month mese della data
        \param year anno della data

        \exception DateException componenti della data non coerenti
*/
void Date::check_date(int day, int month, int year) {
  //
  // Controlli  base
  //
  if (day < 1)
    throw DateException("Day can't be < 1", DateException::INVALID_FORMAT);
  else if (day > 31)
    throw DateException("Day can't be > 31", DateException::INVALID_FORMAT);

  if (month < 1)
    throw DateException("Month can't be < 1", DateException::INVALID_FORMAT);
  else if (month > 12)
    throw DateException("Month can't be > 12", DateException::INVALID_FORMAT);

  if (year < 1900)
    throw DateException("Year can't be < 1900", DateException::INVALID_FORMAT);
  //
  // Controlli coerenza <day, month> e year
  //
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
    std::ostringstream ss;
    ss << "<day, month> = <" << day << ", " << month
       << "> is not valid. Day must be in [1,30]";
    throw DateException(ss.str(), DateException::INVALID_FORMAT);
  } else if (month == 2 && is_leap(year) && day > 29) {
    std::ostringstream ss;
    ss << "<day, month> = <" << day << ", " << month
       << "> (leap) is not valid. Day must be in [1,29]";
    throw DateException(ss.str(), DateException::INVALID_FORMAT);
  } else if (month == 2 && !is_leap(year) && day > 28) {
    std::ostringstream ss;
    ss << "<day, month> = <" << day << ", " << month
       << "> (not leap) is not valid. Day must be in [1,28]";
    throw DateException(ss.str(), DateException::INVALID_FORMAT);
  }
}

/*! \brief Setta la data a oggi*/
void Date::today() {
  std::time_t rawtime;
  std::tm *timeinfo;

  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);
  std::mktime(timeinfo);
  this->date = *timeinfo;
}

Date Date::operator=(const Date &date_obj) {
    this->date = date_obj.date;
    return (*this);
}
