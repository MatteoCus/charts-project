#ifndef XMLFILEHANDLER_H
#define XMLFILEHANDLER_H

#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFileDialog>
#include "./Model/tennis.h"
#include "./Model/rugby.h"
#include "./Model/walk.h"
#include "./Model/run.h"
#include "./Model/cycling.h"
#include "trainingvalues.h"

class xmlFileHandler
{

private:

    /**
     * @brief writeExercises:   gestisce la scrittura sullo stream XML in ingresso degli esercizi dell'allenamento in ingresso
     * @param writer:           stream XML in cui salvare i dati
     * @param it:               iteratore che punta ad un allenamento di cui scrivere i dati degli esercizi
     */
    static void writeExercises(QXmlStreamWriter& writer, std::vector<trainingValues>::iterator it);

    /**
     * @brief readTrainings:                gestisce la lettura sullo stream XML in ingresso degli allenamenti
     * @param reader:                       stream XML da cui leggere i dati
     * @throw std::runtime_error:           se i dati non sono leggibili
     * @return std::vector<trainingValues>: valori degli allenamenti letti
     */
    static std::vector<trainingValues> readTrainings(QXmlStreamReader& reader);

    /**
     * @brief readType:                     gestisce la lettura sullo stream XML in ingresso del tipo degli allenamenti
     * @param reader:                       stream XML da cui leggere i dati
     * @param type:                         variabile in cui salvare il tipo dell'allenamento letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readType(QXmlStreamReader &reader, QString& type);

    /**
     * @brief readName:                     gestisce la lettura sullo stream XML in ingresso del nome degli allenamenti
     * @param reader:                       stream XML da cui leggere i dati
     * @param name:                         variabile in cui salvare il nome dell'allenamento letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readName(QXmlStreamReader &reader, QString& name);

    /**
     * @brief throwReadError:               lancia un'eccezione std::runtime_error comune per ogni metodo
     * @throw std::runtime_error:           sempre
     */
    static void throwReadError();

    /**
     * @brief readStart:                    gestisce la lettura sullo stream XML in ingresso dell'inizio degli allenamenti
     * @param reader:                       stream XML da cui leggere i dati
     * @param start:                        variabile in cui salvare l'inizio dell'allenamento letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readStart(QXmlStreamReader &reader, QDateTime& start);

    /**
     * @brief readDuration:                 gestisce la lettura sullo stream XML in ingresso della durata degli esercizi degli allenamenti
     * @param reader:                       stream XML da cui leggere i dati
     * @param duration:                     variabile in cui salvare la durata degli allenamenti
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readDuration(QXmlStreamReader& reader, QTime& duration);

    /**
     * @brief readDistance:                 gestisce la lettura sullo stream XML in ingresso della distanza degli allenamenti
     * @param reader:                       stream XML da cui leggere i dati
     * @param distance:                     variabile in cui salvare la distanza dell'allenamento letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readDistance(QXmlStreamReader& reader, double& distance);

    /**
     * @brief readEndurance:                gestisce la lettura sullo stream XML in ingresso degli allenamenti di resistenza
     * @param reader:                       stream XML da cui leggere i dati
     * @param duration:                     variabile in cui salvare la durata degli allenamenti
     * @param distance:                     variabile in cui salvare la distanza dell'allenamento letto
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readEndurance(QXmlStreamReader& reader, QTime& duration, double& distance);

    /**
     * @brief readExerciseName:             gestisce la lettura sullo stream XML in ingresso del nome degli esercizi di un allenamento
     * @param reader:                       stream XML da cui leggere i dati
     * @param exName:                       variabile in cui salvare il nome degli esercizi di un allenamento
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readExerciseName(QXmlStreamReader& reader, std::vector<QString>& exName);

    /**
     * @brief readExerciseDuration:         gestisce la lettura sullo stream XML in ingresso delle durate degli esercizi di un allenamento
     * @param reader:                       stream XML da cui leggere i dati
     * @param exDuration:                   variabile in cui salvare le durate degli esercizi di un allenamento
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readExerciseDuration(QXmlStreamReader& reader, std::vector<QTime>& exDuration);

    /**
     * @brief readExerciseRecovery:         gestisce la lettura sullo stream XML in ingresso dei recuperi degli esercizi di un allenamento
     * @param reader:                       stream XML da cui leggere i dati
     * @param exRecovery:                   variabile in cui salvare i recuperi degli esercizi di un allenamento
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readExerciseRecovery(QXmlStreamReader& reader, std::vector<QTime>& exRecovery);

    /**
     * @brief readExerciseName:             gestisce la lettura sullo stream XML in ingresso degli esercizi di un allenamento
     * @param reader:                       stream XML da cui leggere i dati
     * @param exName:                       variabile in cui salvare il nome gli esercizi di un allenamento
     * @param exDuration:                   variabile in cui salvare le durate degli esercizi di un allenamento
     * @param exRecovery:                   variabile in cui salvare i recuperi degli esercizi di un allenamento
     * @throw std::runtime_error:           se i dati non sono leggibili
     */
    static void readRepetition(QXmlStreamReader& reader, std::vector<QString>& exName, std::vector<QTime>& exDuration, std::vector<QTime>& exRecovery);

public:
    explicit xmlFileHandler() = delete;
    explicit xmlFileHandler(const xmlFileHandler&) = delete;

    /**
     * @brief write:        gestisce la scrittura sul device di IO in ingresso degli allenamenti in ingresso
     * @param device:       IO device in cui salvare i dati
     * @param trainings:    allenamenti da salvare
     */
    static void write(QIODevice *device, std::vector<trainingValues> trainings);

    /**
     * @brief getWriteFileName:     gestisce la richiesta del path del file su cui scrivere gli allenamenti
     * @throw std::runtime_error:   se la richiesta del path va a vuoto (utente esce dal dialog specifico)
     * @return QString:             path del file su cui scrivere
     */
    static QString getWriteFileName();

    /**
     * @brief read:                                     gestisce l'apertura di uno stream XML sul device di IO in ingresso
     * @param device:                                   IO device da cui leggere i dati
     * @throw std::runtime_error:                       se il device non è leggibile
     * @return std::vector<trainingValues>:             valori degli allenamenti letti
     */
    static std::vector<trainingValues> read(QIODevice *device);

    /**
     * @brief getReadFileName:      gestisce la richiesta del path del file da cui leggere gli allenamenti
     * @throw std::runtime_error:   se la richiesta del path va a vuoto (utente esce dal dialog specifico)
     * @return QString:             path del file su cui leggere
     */
    static QString getReadFileName();

signals:
};

#endif // XMLFILEHANDLER_H
