#ifndef ADDVALUES_H
#define ADDVALUES_H
#include <QString>
#include <QTime>
#include <QDateTime>


class addValues
{
public:
    addValues(QString type, QDateTime start, QString name,double distance,
    QTime duration, QString exName, QTime exDuration, QTime recovery);
    QString type;
    QDateTime start;
    QString name;
    double distance;
    QTime duration;
    QString exName;
    QTime exDuration;
    QTime recovery;
};

#endif // ADDVALUES_H
