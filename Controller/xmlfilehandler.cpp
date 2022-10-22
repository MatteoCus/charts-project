#include "xmlfilehandler.h"

void xmlFileHandler::writeExercises(QXmlStreamWriter& writer, std::vector<trainingValues>::iterator it)
{
    if(it->exName.size() == it->exDuration.size() && it->exName.size() == it->exRecovery.size())
    {
        writer.writeStartElement("exercises");
        for(unsigned int i = 0; i < it->exName.size(); i++)
        {
            writer.writeStartElement("exercise");
            writer.writeTextElement("name", it->exName.at(i));
            writer.writeTextElement("duration", it->exDuration.at(i).toString());
            writer.writeTextElement("recovery", it->exRecovery.at(i).toString());
            writer.writeEndElement();
        }
        writer.writeEndElement();
    }
    else
        throw std::runtime_error("Esercizi non corretti!");
}

void xmlFileHandler::readType(QXmlStreamReader &reader, QString& type)
{
    QString attr = reader.attributes().value("type").toString();

    if( attr == "Rugby" || attr== "Tennis" || attr == "Camminata" || attr== "Corsa" || attr == "Ciclismo")
        type = reader.attributes().value("type").toString();
    else
        throwReadError();
}

void xmlFileHandler::readName(QXmlStreamReader &reader, QString& name)
{
    if(reader.name() == "name")
        name = reader.readElementText();
    else
        throwReadError();
}

void xmlFileHandler::throwReadError()
{
    throw std::runtime_error("Il file non è leggibile!");
}

void xmlFileHandler::readStart(QXmlStreamReader &reader, QDateTime& start)
{
    if(reader.name() == "start")
        start = QDateTime::fromString(reader.readElementText(), Qt::ISODate);
    else
        throwReadError();
}

void xmlFileHandler::readDuration(QXmlStreamReader &reader, QTime &duration)
{
    if(reader.name() == "duration")
        duration = QTime::fromString(reader.readElementText());
    else
        throwReadError();
}

void xmlFileHandler::readDistance(QXmlStreamReader &reader, double &distance)
{

    if(reader.name().toString() == "distance")
    {
        std::string dist = reader.readElementText().toStdString();

        #ifdef Q_OS_WIN
        std::replace(dist.begin(),dist.end(), ',', '.');

        #else
        std::replace(dist.begin(),dist.end(), '.', ',');

        #endif

        distance = std::stod(dist);
    }
    else
        throwReadError();
}

void xmlFileHandler::readEndurance(QXmlStreamReader &reader, QTime &duration, double &distance)
{
    if(reader.readNextStartElement())
        readDuration(reader,duration);
    else
        throwReadError();

    if(reader.readNextStartElement())
        readDistance(reader,distance);
    else
        throwReadError();
}

void xmlFileHandler::readExerciseName(QXmlStreamReader &reader, std::vector<QString> &exName)
{
    if(reader.name().toString() == "name")
        exName.push_back(reader.readElementText());
    else
        throwReadError();
}

void xmlFileHandler::readExerciseDuration(QXmlStreamReader &reader, std::vector<QTime> &exDuration)
{
    if(reader.name().toString() == "duration")
        exDuration.push_back(QTime::fromString(reader.readElementText()));
    else
        throwReadError();
}

void xmlFileHandler::readExerciseRecovery(QXmlStreamReader &reader, std::vector<QTime> &exRecovery)
{
    if(reader.name().toString() == "recovery")
        exRecovery.push_back(QTime::fromString(reader.readElementText()));
    else
        throwReadError();
}

void xmlFileHandler::readRepetition(QXmlStreamReader &reader, std::vector<QString>& exName, std::vector<QTime>& exDuration, std::vector<QTime>& exRecovery)
{
    if(reader.readNextStartElement() && reader.name() == "exercises")
    {
        while(reader.readNextStartElement() && reader.name() == "exercise")  //usando reader.readNextStartElement() si rischia di leggere il prossimo tag <training>
        {
            if(reader.readNextStartElement())
                readExerciseName(reader,exName);
            else
                throwReadError();

            if(reader.readNextStartElement())
                readExerciseDuration(reader,exDuration);
            else
                throwReadError();
            if(reader.readNextStartElement())
                readExerciseRecovery(reader,exRecovery);
            else
                throwReadError();

            reader.readNextStartElement();
        }
    }
    else
        throwReadError();
}

std::vector<trainingValues> xmlFileHandler::readTrainings(QXmlStreamReader &reader)
{
    Q_ASSERT(reader.isStartElement() && reader.name() == QLatin1String("plan"));
    std::vector<trainingValues> vector;

    while (reader.readNextStartElement()) {             //avanza l'input per ogni allenamento
        QString type;
        QDateTime start;
        QString name;
        double distance = 0.0;
        QTime duration;
        std::vector<QString> exName;
        std::vector<QTime> exDuration;
        std::vector<QTime> exRecovery;

        if (reader.name().toString() == "training")
        {
            readType(reader,type);

            if(reader.readNextStartElement())
                readName(reader, name);
            else
                throwReadError();

            if(reader.readNextStartElement())
                readStart(reader, start);
            else
                throwReadError();

            if(type == "Rugby" || type == "Tennis")
                readRepetition(reader,exName,exDuration,exRecovery);
            else
                readEndurance(reader, duration, distance);
        }
        else
            throwReadError();

        vector.push_back(trainingValues(type,start,name,distance,duration,exName,exDuration,exRecovery));
        reader.readNextStartElement();
    }

    std::reverse(vector.begin(), vector.end());
    return vector;
}

void xmlFileHandler::write(QIODevice *device, std::vector<trainingValues> trainings)
{

    QXmlStreamWriter writer(device);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("plan");

    for(auto it = trainings.begin(); it != trainings.end(); ++it)
    {
        writer.writeStartElement("training");

        if(it->type != "Corsa" && it->type != "Camminata" && it->type != "Ciclismo" && it->type != "Tennis" && it->type != "Rugby")
            throw std::runtime_error("Tipo di allenamento non riconosciuto!");

        writer.writeAttribute("type", it->type);

        writer.writeTextElement("name", it->name);
        writer.writeTextElement("start", it->start.toString(Qt::ISODate));

        if (it->type == "Rugby" || it->type == "Tennis")
            writeExercises(writer, it);
        else
        {
            writer.writeTextElement("duration", it->duration.toString());
            writer.writeTextElement("distance", QString::fromStdString(std::to_string(it->distance)));
        }
        writer.writeEndElement();
    }


    writer.writeEndElement();
    writer.writeEndDocument();


}

QString xmlFileHandler::getWriteFileName(QWidget* parent)
{
    QString fileName = QFileDialog::getSaveFileName(parent, ("Save File"),
                                                    "/home",
                                                    ("XML Files (*.xml)"));
    if (fileName == "")
        throw std::runtime_error("Nessun file scelto, aggiunta annullata!");

    if(fileName.size() > 4)
    {
        QString ext = fileName.mid(fileName.size()-4);

        if(ext != ".xml")
            fileName += ".xml";
    }
    else
        fileName += ".xml";
    return fileName;
}

std::vector<trainingValues> xmlFileHandler::read(QIODevice *device)
{
    QXmlStreamReader reader(device);

    if (reader.readNextStartElement() && reader.name() == "plan")
        return readTrainings(reader);
    else
        throw std::runtime_error("Il file non è leggibile!");

}

QString xmlFileHandler::getReadFileName(QWidget* parent)
{
    QString fileName = QFileDialog::getOpenFileName(parent, ("Open file"),
                                                    "/home",
                                                    ("XML Files (*.xml)"));
    if (fileName == "")
        throw std::runtime_error("Nessun file scelto, apertura annullata!");

    return fileName;
}
