#include "endurancedialog.h"

enduranceDialog::enduranceDialog(QWidget *parent, action act, Endurance* training)
    : trainingDialog(parent)
{
    setupCommon(mainL,act,training);
    QHBoxLayout *distanceLayout = new QHBoxLayout;
    QHBoxLayout *durationLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);


    distance = new QDoubleSpinBox(this);
    if (act == add)
        duration = new QTimeEdit(QTime(1,0,0),this);
    else
    {
        Time time = training->getDuration();

        double dist = training->getDistance();

        duration = new QTimeEdit(QTime(time.getHours(),time.getMinutes(),time.getSeconds()),this);
        distance->setValue(dist);

        if( act == eliminate)
        {   duration->setReadOnly(true);
            distance->setReadOnly(true);
        }
    }
    distance->setFixedWidth(150);
    distance->setMinimum(0.01);
    distance->setAlignment(Qt::AlignCenter);
    QLabel* distanceLabel = new QLabel(QString("Distanza percorsa"), this);
    distanceLabel->setFixedWidth(150);
    distanceLabel->setFont(font);

    addToLayout(distanceLayout,distanceLabel,distance);

    duration->setFixedWidth(150);
    duration->setAlignment(Qt::AlignCenter);
    QLabel* durationLabel = new QLabel(QString("Durata allenamento"), this);
    duration->setDisplayFormat("hh:mm:ss");
    durationLabel->setFixedWidth(150);
    durationLabel->setFont(font);



    this->setFixedSize(327,200);

    addToLayout(durationLayout,durationLabel,duration);

    mainL->addLayout(distanceLayout);
    mainL->addLayout(durationLayout);
    addButtons();
}

dialogValues enduranceDialog::getValues(QWidget *parent, bool *ok, action act, Endurance *training)
{
    enduranceDialog *dialog = new enduranceDialog(parent,act,training);

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    QString name;
    QTime duration;
    QDateTime start;
    int pos = 0;
    double distance = 0.0;
    if (ret) {
        name = dialog->name->text();
        start = dialog->start->dateTime();
        pos = dialog->pos;
        distance = dialog->distance->value();
        duration = dialog->duration->time();
    }
    else
        throw std::runtime_error("Operazione annullata!");
    dialog->deleteLater();
    return dialogValues("",start,name,distance,duration,std::vector<QString>(),std::vector<QTime>(),std::vector<QTime>(),pos,nothing, 0);
}
