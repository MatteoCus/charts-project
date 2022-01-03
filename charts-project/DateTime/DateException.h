#ifndef DATEEXCEPTION_H
#define DATEEXCEPTION_H

#include <stdexcept>
#include <string>

//! Classe di gestione delle eccezioni riguardanti la data
/*!
	Questa classe estende std::invalid_argument
	fornendo informazioni sul tipo di errore
	generato nella manipolazione di date
*/
class DateException : public std::invalid_argument
{
private:
	int err_code;

public:
	/*! codici di errore */
	enum codes 
	{ 
		UNDEFINED, /*!< errore non definito */
		STRING_INVALID_FORMAT, /*!< formato della stringa non valida */
		INVALID_FORMAT /*!< formato della data non valido */
	};

	DateException(const std::string& err_msg, int err_code = 0);	
	int code();
};


#endif
