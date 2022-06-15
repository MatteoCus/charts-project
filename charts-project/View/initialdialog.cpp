#include "initialdialog.h"

void initialDialog::addButtons()
{
    buttonsLayout = new QVBoxLayout;
    buttonsLayout->setSpacing(50);
    buttonsLayout->setContentsMargins(25,50,12,50);
    buttonsLayout->setAlignment(Qt::AlignTop);

    newButton = new QPushButton("Nuovo",this);
    openButton = new QPushButton("Apri",this);

    newButton->setFixedSize(150,70);
    openButton->setFixedSize(150,70);

    buttonsLayout->addWidget(newButton);
    buttonsLayout->addWidget(openButton);

    mainLayout->addLayout(buttonsLayout);
}

void initialDialog::addTextImage()
{
    textImageLayout= new QVBoxLayout;
    textImageLayout->setAlignment(Qt::AlignTop);
    textImageLayout->setContentsMargins(12, 50, 25, 50);
    textImageLayout->setAlignment(Qt::AlignTop);
    textImageLayout->setSpacing(20);

    QLabel* img = new QLabel(this);
    QPixmap pic = QPixmap(":/images/sport.jpg");
    pic = pic.scaledToHeight(200);
    img->setPixmap(pic);
    img->setFixedSize(300,200);
    textImageLayout->addWidget(img);

    QLabel* text = new QLabel("TT - Training Tracker è un programma utile per gestire gli\n"
                              "allenamenti di un atleta di qualsiasi livello, offrendo una\n"
                              "serie di parametri, corredati da grafici, per tenere traccia\n"
                              " dei progressi effettuati nel tempo.\n\n"
                              "I tipi di allenamento disponibili sono: \n"
                              "1) Corsa\n"
                              "2) Camminata\n"
                              "3) Ciclismo\n"
                              "4) Tennis\n"
                              "5) Rugby\n\n"
                              "Vi sono alcuni vincoli relativi ai dati:\n"
                              "a) La durata di ogni allenamento deve essere inferiore o \n"
                              "   uguale a 20 ore;\n"
                              "b) Il numero di esercizi inseribili per i tipi di \n"
                              "   allenamento 4) e 5) deve essere compreso tra 1 e 15.",this);

    textImageLayout->addWidget(text);

    mainLayout->addLayout(textImageLayout);
}

void initialDialog::closeEvent(QCloseEvent *event)
{
    if(!event->spontaneous())
        return;
    else
    {
        event->accept();
        emit closeAll();
    }
}

void initialDialog::closeWidget()
{
    close();
}

initialDialog::initialDialog(QWidget *parent) :QDialog(parent)
{
    mainLayout = new QHBoxLayout;
    mainLayout->setMargin(0);

    addButtons();
    addTextImage();

    setLayout(mainLayout);

    setFixedSize(600,600);

    connect(newButton,SIGNAL(clicked()),this, SIGNAL(showView()));
    connect(newButton,SIGNAL(clicked()),this, SLOT(closeWidget()));
    connect(openButton,SIGNAL(clicked()),this, SIGNAL(openFile()));
    connect(openButton,SIGNAL(clicked()),this, SLOT(closeWidget()));
}
