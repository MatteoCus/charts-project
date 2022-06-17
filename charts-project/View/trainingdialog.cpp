#include "trainingdialog.h"
#include <iostream>

void trainingDialog::addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void trainingDialog::setupCommon(QBoxLayout* mainL, action act, Training* training)
{
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *startLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    QLabel* nameLabel = new QLabel(QString("Nome"), this);

    if (act == add)
    {
        name = new QLineEdit(QString("Nome Allenamento"), this);
        start = new QDateTimeEdit(QDateTime::currentDateTime());
    }
    else
    {
        if (!training)
            throw std::runtime_error("Allenamento non valido!");
        Date date = training->getStart().getDate();
        Time time = training->getStart().getTime();
        QString trainingName = QString::fromStdString(training->getName());
        QDateTime qdatetime(QDate(date.getYear(),date.getMonth(), date.getDay()), QTime(time.getHours(),time.getMinutes(),time.getSeconds()));

        name = new QLineEdit(trainingName, this);
        start = new QDateTimeEdit(qdatetime,this);

        if( act == eliminate || act == nothing)
        {   name->setReadOnly(true);
            start->setReadOnly(true);
        }
    }
    start->setDisplayFormat("dd/MM/yyyy hh:mm:ss");
    start->setCalendarPopup(true);

    nameLabel->setFont(font);
    name->setFixedWidth(150);
    name->setAlignment(Qt::AlignCenter);

    start->setFixedWidth(150);
    start->setAlignment(Qt::AlignCenter);

    addToLayout(nameLayout,nameLabel,name);

    QLabel* startLabel = new QLabel(QString("Inizio"), this);
    startLabel->setFont(font);

    addToLayout(startLayout,startLabel,start);

    mainL->addLayout(nameLayout);
    mainL->addLayout(startLayout);
}

int trainingDialog::showExNumberDialog()
{
    bool ok = false;
    QInputDialog* dial = new QInputDialog(this);
    int remove = dial->getInt(this,tr("Esercizi da inserire"),"Quantità: ",1,1,15,1,&ok);
    if(!ok) throw std::runtime_error("Nessun numero scelto, inserimento annullato!");
    return remove;
}

void trainingDialog::addButtons()
{
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                       | QDialogButtonBox::Close,this);

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(buttonsLayout);

    connect(buttonBox, &QDialogButtonBox::accepted,
            this, &trainingDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected,
            this, &trainingDialog::reject);

}

trainingDialog::trainingDialog(QWidget *parent) : QDialog(parent)
{
    mainL = new QVBoxLayout;
    setLayout(mainL);
}
