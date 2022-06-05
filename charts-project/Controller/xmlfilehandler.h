#ifndef XMLFILEHANDLER_H
#define XMLFILEHANDLER_H

#include <QXmlStreamWriter>
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
    QXmlStreamWriter writer;
public:
    explicit xmlFileHandler() = delete;
    explicit xmlFileHandler(const xmlFileHandler&) = delete;

    static void write(QIODevice *device, std::vector<trainingValues> trainings);
    static QString getWriteFileName();

signals:

};

#endif // XMLFILEHANDLER_H
