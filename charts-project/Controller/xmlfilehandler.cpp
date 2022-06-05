#include "xmlfilehandler.h"

void xmlFileHandler::write(QIODevice *device, std::vector<trainingValues> trainings)
{

    QXmlStreamWriter stream(device);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("plan");

    for(auto it = trainings.begin(); it != trainings.end(); ++it)
    {
        stream.writeStartElement("training");

        if(it->type != "Corsa" && it->type != "Camminata" && it->type != "Ciclismo" && it->type != "Tennis" && it->type != "Rugby")
            throw std::runtime_error("Tipo di allenamento non riconosciuto!");

        stream.writeAttribute("type", it->type);

        stream.writeTextElement("name", it->name);
        stream.writeTextElement("start", it->start.toString(Qt::SystemLocaleLongDate));

        if (it->type == "Rugby" || it->type == "Tennis")
        {
            if(it->exName.size() == it->exDuration.size() && it->exName.size() == it->exRecovery.size())
            {
                stream.writeStartElement("exercises");
                for(unsigned int i = 0; i < it->exName.size(); i++)
                {
                    stream.writeStartElement("exercise");
                    stream.writeTextElement("name", it->exName.at(i));
                    stream.writeTextElement("duration", it->exDuration.at(i).toString());
                    stream.writeTextElement("recovery", it->exRecovery.at(i).toString());
                    stream.writeEndElement();
                }
                stream.writeEndElement();
            }
            else
                throw std::runtime_error("Esercizi non corretti!");
        }
        else
        {
            stream.writeTextElement("duration", it->duration.toString());
            stream.writeTextElement("distance", QString::fromStdString(std::to_string(it->distance)));
        }
        stream.writeEndElement();
    }


    stream.writeEndElement();
    stream.writeEndDocument();


}

QString xmlFileHandler::getWriteFileName()
{
    QString fileName = QFileDialog::getSaveFileName(nullptr, ("Save File"),
                                                    "/home",
                                                    ("XML Files (*.xml)"));
    if (fileName == "")
        throw std::runtime_error("Nessun file scelto, aggiunta annullata!");

    fileName += ".xml";
    return fileName;
}
