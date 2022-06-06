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
public:
    explicit xmlFileHandler() = delete;
    explicit xmlFileHandler(const xmlFileHandler&) = delete;

    static void write(QIODevice *device, std::vector<trainingValues> trainings);
    static QString getWriteFileName();

    static std::vector<trainingValues> read(QIODevice *device);
    static QString getReadFileName();

signals:

private:
    static void writeExercises(QXmlStreamWriter& writer, std::vector<trainingValues>::iterator it);
    static std::vector<trainingValues> readTrainings(QXmlStreamReader& reader);
    static void readType(QXmlStreamReader &reader, QString& type);
    static void readName(QXmlStreamReader &reader, QString& name);
    static void throwReadError();
    static void readStart(QXmlStreamReader &reader, QDateTime& start);
    static void readDuration(QXmlStreamReader& reader, QTime& duration);
    static void readDistance(QXmlStreamReader& reader, double& distance);
    static void readEndurance(QXmlStreamReader& reader, QTime& duration, double& distance);
    static void readExerciseName(QXmlStreamReader& reader, std::vector<QString>& exName);
    static void readExerciseDuration(QXmlStreamReader& reader, std::vector<QTime>& exDuration);
    static void readExerciseRecovery(QXmlStreamReader& reader, std::vector<QTime>& exRecovery);
    static void readRepetition(QXmlStreamReader& reader, std::vector<QString>& exName, std::vector<QTime>& exDuration, std::vector<QTime>& exRecovery);
};

#endif // XMLFILEHANDLER_H
