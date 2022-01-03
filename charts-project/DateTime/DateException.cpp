#include "dateexception.h"

/*! \brief Costruttore con parametri

        Accetta una string di errore e un codice
        e richiama il costruttore di std::runtime_error
        Se il codice non e' valido, UNDEFINED viene settato

        \param err_msg stringa di errore
        \param err_code codice di errore
*/
DateException::DateException(const std::string &err_msg, int err_code)
    : std::invalid_argument(err_msg) {
  if (err_code < 0 || err_code > 2)
    this->err_code = UNDEFINED;
  else
    this->err_code = err_code;
}

/*! \brief Getter per il codice di errore

        \return codice di errore
*/
int DateException::code() { return this->err_code; }
