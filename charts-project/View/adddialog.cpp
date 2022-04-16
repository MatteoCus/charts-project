#include "adddialog.h"
#include <iostream>

void addDialog::setLabelStyleSheet(QLabel* name)
{
    name->setStyleSheet("QLabel {background-color: #404244; color: white}");
}

void addDialog::addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void addDialog::setupRepetition(QBoxLayout* mainL)
{
    std::vector<QHBoxLayout *> nameExLayout;
    std::vector<QHBoxLayout *> exDurationLayout;
    std::vector<QHBoxLayout *> exRecoveryLayout;
    std::vector<QLabel*> nameExLabel;
    std::vector<QVBoxLayout *> rowLayout;
    QVBoxLayout * firstLayout = new QVBoxLayout;
    QFont font;
    font.setItalic(true);

    setupCommon(firstLayout);

    firstLayout->setContentsMargins(0,0,15,0);
    rowLayout.push_back(firstLayout);
    unsigned int exNumber = showExNumberDialog();
    if (exNumber > 3){
        QHBoxLayout * horizLayout = new QHBoxLayout;
        horizLayout->addLayout(firstLayout);
        unsigned int numVerticalLayout = exNumber/3 + (exNumber%3==0? 0 : 1);
        std::cout<<numVerticalLayout<<std::endl;
        for(unsigned int i=1; i < numVerticalLayout  ; ++i)
        {
            QVBoxLayout * otherLayout = new QVBoxLayout;
            rowLayout.push_back(otherLayout);
            otherLayout->setContentsMargins(0,60,0,0);
            otherLayout->setAlignment(Qt::AlignTop);
            horizLayout->addLayout(otherLayout);
        }
        mainL->addLayout(horizLayout);
    }
    else
        mainL->addLayout(firstLayout);

    unsigned int i=0;
    for (; i<exNumber ; i++){
        QVBoxLayout* repetitionLayout = new QVBoxLayout;
        rowLayout[(i/3)]->addLayout(repetitionLayout);

        //Setup dei nomi
        nameExLayout.push_back(new QHBoxLayout);
        QLabel* auxLabel = new QLabel(QString("Nome esercizio " + QString::fromStdString(std::to_string(i+1)) + " :"), this);
        nameExLabel.push_back(auxLabel);
        auxLabel->setFont(font);

        QLineEdit* auxEdit = new QLineEdit(this);
        auxEdit->setStyleSheet("QLineEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                              "selection-color : white} ");
        auxEdit->setAlignment(Qt::AlignCenter);
        auxEdit->setFixedWidth(120);
        nameEx.push_back(auxEdit);
        setLabelStyleSheet(nameExLabel[i]);
        addToLayout(nameExLayout[i],nameExLabel[i],auxEdit);

        //Setup delle durate
        exDurationLayout.push_back(new QHBoxLayout);
        QLabel* exDurationLabel = new QLabel(QString("Durata attività"), this);
        exDurationLabel->setFont(font);

        QTimeEdit* auxDuration = new QTimeEdit(QTime(1,0,0),this);
        auxDuration->setStyleSheet("QTimeEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                                  "selection-color : white} ");
        auxDuration->setDisplayFormat("hh:mm:ss");
        auxDuration->setAlignment(Qt::AlignCenter);
        auxDuration->setFixedWidth(120);
        exDuration.push_back(auxDuration);
        setLabelStyleSheet(exDurationLabel);
        addToLayout(exDurationLayout[i],exDurationLabel,auxDuration);

        //Setup dei recuperi
        exRecoveryLayout.push_back(new QHBoxLayout);
        QLabel* exRecoveryLabel = new QLabel(QString("Durata recupero"), this);
        exRecoveryLabel->setFont(font);

        QTimeEdit* auxRecovery = new QTimeEdit(QTime(1,0,0),this);
        auxRecovery->setStyleSheet("QTimeEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                                  "selection-color : white} ");
        auxRecovery->setDisplayFormat("hh:mm:ss");
        auxRecovery->setAlignment(Qt::AlignCenter);
        auxRecovery->setFixedWidth(120);
        exRecovery.push_back(auxRecovery);
        setLabelStyleSheet(exRecoveryLabel);
        addToLayout(exRecoveryLayout[i],exRecoveryLabel,auxRecovery);

        //Setup layout
        repetitionLayout->setContentsMargins(0,10,5,10);
        repetitionLayout->addLayout(nameExLayout[i]);
        repetitionLayout->addLayout(exDurationLayout[i]);
        repetitionLayout->addLayout(exRecoveryLayout[i]);


    }
}

void addDialog::setupEndurance(QBoxLayout* mainL)
{
    QHBoxLayout *distanceLayout = new QHBoxLayout;
    distance = new QDoubleSpinBox(this);
    distance->setFixedWidth(150);
    distance->setAlignment(Qt::AlignCenter);
    distance->setStyleSheet("QDoubleSpinBox {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                            "selection-color : white} ");

    QFont font;
    font.setBold(true);
    QLabel* distanceLabel = new QLabel(QString("Distanza percorsa"), this);
    distanceLabel->setFixedWidth(150);
    distanceLabel->setFont(font);

    setLabelStyleSheet(distanceLabel);
    addToLayout(distanceLayout,distanceLabel,distance);

    QHBoxLayout *durationLayout = new QHBoxLayout;
    duration = new QTimeEdit(QTime(1,0,0),this);
    duration->setFixedWidth(150);
    duration->setAlignment(Qt::AlignCenter);
    duration->setStyleSheet("QTimeEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                            "selection-color : white} ");
    QLabel* durationLabel = new QLabel(QString("Durata allenamento"), this);
    duration->setDisplayFormat("hh:mm:ss");
    durationLabel->setFixedWidth(150);
    durationLabel->setFont(font);

    this->setFixedSize(327,200);

    setLabelStyleSheet(durationLabel);
    addToLayout(durationLayout,durationLabel,duration);

    mainL->addLayout(distanceLayout);
    mainL->addLayout(durationLayout);
}

void addDialog::setupCommon(QBoxLayout* mainL)
{
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *startLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    QLabel* nameLabel = new QLabel(QString("Nome"), this);
    nameLabel->setFont(font);
    name = new QLineEdit(QString("Nome Allenamento"), this);
    name->setFixedWidth(150);
    name->setAlignment(Qt::AlignCenter);
    start = new QDateTimeEdit(QDateTime::currentDateTime());
    start->setFixedWidth(150);
    start->setAlignment(Qt::AlignCenter);

    name->setStyleSheet("QLineEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                        "selection-color : white} ");

    setLabelStyleSheet(nameLabel);

    addToLayout(nameLayout,nameLabel,name);

    QLabel* startLabel = new QLabel(QString("Inizio"), this);
    startLabel->setFont(font);
    start->setStyleSheet("QDateTimeEdit {background-color: #56585a;   color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");

    setLabelStyleSheet(startLabel);

    addToLayout(startLayout,startLabel,start);



    mainL->addLayout(nameLayout);
    mainL->addLayout(startLayout);
}

int addDialog::showExNumberDialog() //guarda come settare lo stylesheet di un QInputDialog
{
    bool ok = false;
    QInputDialog* dial = new QInputDialog(this);
    this -> setStyleSheet("QInputDialog{background-color : #404244}"
                          "QInputDialog QWidget{background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                          "selection-color : white}"
                          "QInputDialog  QLabel{background-color : #404244; color: white}");
    int remove = dial->getInt(this,tr("Esercizi da inserire"),"Quantità: ",1,1,15,1,&ok);
    if(!ok) throw std::runtime_error("Nessun numero scelto, inserimento annullato!");
    return remove;
}

addDialog::addDialog(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    bool ok;
    type = typeDialog::getType(this,&ok);
    if (type == "Camminata" || type == "Corsa" || type == "Ciclismo")
    {
        setupCommon(mainL);
        setupEndurance(mainL);
    }
    else //if(type == "Tennis" || type == "Rugby")
        setupRepetition(mainL);

    this->setStyleSheet("QWidget{background-color : #404244; color : white}");
    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Orientation::Horizontal,this);

    QPushButton* first = new QPushButton(QString("Ok"), buttonBox);
    first->setStyleSheet("QPushButton {color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    first->setDefault(true);

    QPushButton* second = new QPushButton(QString("Cancel"), buttonBox);
    second->setStyleSheet("QPushButton {color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    second->setAutoDefault(false);

    buttonBox->addButton(first,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(second,QDialogButtonBox::RejectRole);

    buttonBox->setStyleSheet("QDialogButtonBox {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                             "selection-color : white} ");

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(buttonsLayout);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                      this, &addDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
        this, &addDialog::reject);
    Q_ASSERT(conn);

    setLayout(mainL);
}

trainingValues addDialog::getValues(QWidget *parent, bool *ok)
{
    addDialog *dialog = new addDialog(parent);

        const int ret = dialog->exec();
        if (ok)
            *ok = !!ret;

        QString name;
        std::vector<QString> exName;
        QTime duration;
        std::vector<QTime> exDuration;
        std::vector<QTime> recovery;
        QDateTime start;
        QString type;
        double distance = 0.0;
        if (ret) {      //modifica per modifica di tutti gli esercizi di un repetition (metti un indice dell'esercizio modificato)

            type = dialog->type;
            name = dialog->name->text();
            start = dialog->start->dateTime();
            if(type == "Tennis" || type == "Rugby")
            {
                for (unsigned int i = 0; i < dialog->nameEx.size(); ++i)
                {
                    exName.push_back(dialog->nameEx[i]->text());
                    exDuration.push_back(dialog->exDuration[i]->time());
                    recovery.push_back(dialog->exRecovery[i]->time());
                }
                std::cout<<dialog->nameEx.size()<<std::endl;
            }
            else
            {
                distance = dialog->distance->value();
                duration = dialog->duration->time();
            }
        }
        dialog->deleteLater();
        return trainingValues(type,start,name,distance,duration,exName,exDuration,recovery);
}
