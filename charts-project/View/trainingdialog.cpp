#include "trainingdialog.h"
#include <iostream>

void trainingDialog::setLabelStyleSheet(QLabel* name)
{
    name->setStyleSheet("QLabel {background-color: #404244; color: white}");
}

void trainingDialog::addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void trainingDialog::setupRepetition(QBoxLayout* mainL, action act, const Repetition* training)
{
    std::vector<QHBoxLayout *> nameExLayout;
    std::vector<QHBoxLayout *> exDurationLayout;
    std::vector<QHBoxLayout *> exRecoveryLayout;
    std::vector<QLabel*> nameExLabel;
    std::vector<QVBoxLayout *> rowLayout;
    QVBoxLayout * firstLayout = new QVBoxLayout;
    QFont font;
    font.setItalic(true);


    firstLayout->setContentsMargins(0,0,15,0);
    rowLayout.push_back(firstLayout);
    unsigned int exNumber = (act == add? showExNumberDialog() : training->getExercises().size());

    if (act == set)
    {
        QStringList items;
        items << tr("Aggiungi") << tr("Inserisci") << tr("Modifica") << tr("Rimuovi")<< tr("Nulla");

        bool ok;
        this -> setStyleSheet("QInputDialog{background-color : #404244}"
                              "QInputDialog QWidget{background-color: #404244; color: white ; selection-background-color: #c26110 ;"
                              "selection-color : white}"
                              "QInputDialog  QLabel{background-color : #404244; color: white}"
                              "QInputDialog QLineEdit{background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                              "selection-color : white}");
        std::string item = QInputDialog::getItem(this, tr("Esercizi"),
                                             tr("Azione da effettuare sugli esercizi:"), items, 0, false, &ok).toStdString();
        if (ok && item !="")
        {
            if (item == "Aggiungi")
                exAct = add;
            else if (item == "Inserisci")
                exAct = insert;
            else if (item == "Modifica")
                exAct = set;
            else if (item == "Rimuovi")
                exAct = eliminate;
            else exAct = nothing;
        }
        else
            throw std::runtime_error("Impossibile modificare l'allenamento!");
    }

    if (act != set || (act == set && exAct == set))
    {
        setupCommon(firstLayout,act,training);
        if (exNumber > 3){
            QHBoxLayout * horizLayout = new QHBoxLayout;
            horizLayout->addLayout(firstLayout);
            unsigned int numVerticalLayout = exNumber/3 + (exNumber%3==0? 0 : 1);
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

            QLineEdit* auxEdit;
            QTimeEdit* auxDuration;
            QTimeEdit* auxRecovery;

            if (act == add)
            {
                auxEdit = new QLineEdit(this);
                auxDuration = new QTimeEdit(QTime(1,0,0),this);
                auxRecovery= new QTimeEdit(QTime(1,0,0),this);
            }
            else
            {
                Exercise* ex = training->getExercise(i);
                Time dur = ex->getDuration();
                Time rec = ex->getRecoveryTime();

                auxEdit = new QLineEdit(QString::fromStdString(ex->getName()));
                auxDuration = new QTimeEdit(QTime(dur.getHours(),dur.getMinutes(),dur.getSeconds()),this);
                auxRecovery = new QTimeEdit(QTime(rec.getHours(),rec.getMinutes(),rec.getSeconds()),this);

                if (act == eliminate)
                {
                    auxEdit->setReadOnly(true);
                    auxDuration->setReadOnly(true);
                    auxRecovery->setReadOnly(true);
                }
            }


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
    else
    {
        if (exAct != nothing)
            setupCommon(firstLayout,nothing,training);
        else
            setupCommon(firstLayout,set,training);

        mainL->addLayout(firstLayout);
        if (exAct == add)
            exPos = training->getSize();
        else if (exAct == insert)
        {
            bool ok = false;
            exPos = QInputDialog::getInt(this,QString("Inserimento esercizio"),QString("Posizione"),1,1,training->getSize()+1,1,&ok);
            exPos--;
            if (!ok)
                throw std::runtime_error("Posizione di inserimento esercizio non valida!");
        }
        else if (exAct == eliminate)
        {
            bool ok = false;
            exPos = QInputDialog::getInt(this,QString("Inserimento esercizio"),QString("Posizione"),1,1,training->getSize(),1,&ok);
            exPos--;
            if (!ok)
                throw std::runtime_error("Posizione di eliminazione esercizio non valida!");
        }


        //Setup dei nomi
        nameExLayout.push_back(new QHBoxLayout);
        QLabel* auxLabel = new QLabel(QString("Nome esercizio " + QString::fromStdString(std::to_string(exPos+1)) + " :"), this);
        nameExLabel.push_back(auxLabel);
        auxLabel->setFont(font);

        QLineEdit* auxEdit;
        QTimeEdit* auxDuration;
        QTimeEdit* auxRecovery;

        if (exAct == add || exAct == insert)
        {
            auxEdit = new QLineEdit(this);
            auxDuration = new QTimeEdit(QTime(1,0,0),this);
            auxRecovery= new QTimeEdit(QTime(1,0,0),this);
        }
        else
        {
            Exercise* ex = training->getExercise(exPos);
            Time dur = ex->getDuration();
            Time rec = ex->getRecoveryTime();

            auxEdit = new QLineEdit(QString::fromStdString(ex->getName()));
            auxDuration = new QTimeEdit(QTime(dur.getHours(),dur.getMinutes(),dur.getSeconds()),this);
            auxRecovery = new QTimeEdit(QTime(rec.getHours(),rec.getMinutes(),rec.getSeconds()),this);

            if (exAct == eliminate || exAct == nothing)
            {
                auxEdit->setReadOnly(true);
                auxDuration->setReadOnly(true);
                auxRecovery->setReadOnly(true);
            }
        }


        auxEdit->setStyleSheet("QLineEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                               "selection-color : white} ");
        auxEdit->setAlignment(Qt::AlignCenter);
        auxEdit->setFixedWidth(120);
        nameEx.push_back(auxEdit);
        setLabelStyleSheet(nameExLabel[0]);
        addToLayout(nameExLayout[0],nameExLabel[0],auxEdit);

        //Setup delle durate
        exDurationLayout.push_back(new QHBoxLayout);
        QLabel* exDurationLabel = new QLabel(QString("Durata attività"), this);
        exDurationLabel->setFont(font);


        auxDuration->setStyleSheet("QTimeEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                                   "selection-color : white} ");
        auxDuration->setDisplayFormat("hh:mm:ss");
        auxDuration->setAlignment(Qt::AlignCenter);
        auxDuration->setFixedWidth(120);
        exDuration.push_back(auxDuration);
        setLabelStyleSheet(exDurationLabel);
        addToLayout(exDurationLayout[0],exDurationLabel,auxDuration);

        //Setup dei recuperi
        exRecoveryLayout.push_back(new QHBoxLayout);
        QLabel* exRecoveryLabel = new QLabel(QString("Durata recupero"), this);
        exRecoveryLabel->setFont(font);

        auxRecovery->setStyleSheet("QTimeEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                                   "selection-color : white} ");
        auxRecovery->setDisplayFormat("hh:mm:ss");
        auxRecovery->setAlignment(Qt::AlignCenter);
        auxRecovery->setFixedWidth(120);
        exRecovery.push_back(auxRecovery);
        setLabelStyleSheet(exRecoveryLabel);
        addToLayout(exRecoveryLayout[0],exRecoveryLabel,auxRecovery);

        //Setup layout
        firstLayout->setContentsMargins(0,10,5,10);
        firstLayout->addLayout(nameExLayout[0]);
        firstLayout->addLayout(exDurationLayout[0]);
        firstLayout->addLayout(exRecoveryLayout[0]);
    }
}

void trainingDialog::setupEndurance(QBoxLayout* mainL, action act, const Endurance* training)
{
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
    distance->setAlignment(Qt::AlignCenter);
    distance->setStyleSheet("QDoubleSpinBox {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                            "selection-color : white} ");
    QLabel* distanceLabel = new QLabel(QString("Distanza percorsa"), this);
    distanceLabel->setFixedWidth(150);
    distanceLabel->setFont(font);

    setLabelStyleSheet(distanceLabel);
    addToLayout(distanceLayout,distanceLabel,distance);

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

void trainingDialog::setupCommon(QBoxLayout* mainL, action act, const Training* training)
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
        QDateTime* qdatetime = new QDateTime(QDate(date.getYear(),date.getMonth(), date.getDay()), QTime(time.getHours(),time.getMinutes(),time.getSeconds()));

        name = new QLineEdit(trainingName, this);
        start = new QDateTimeEdit(*qdatetime,this);

        if( act == eliminate || act == nothing)
        {   name->setReadOnly(true);
            start->setReadOnly(true);
        }
    }
    nameLabel->setFont(font);
    name->setFixedWidth(150);
    name->setAlignment(Qt::AlignCenter);

    name->setStyleSheet("QLineEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                        "selection-color : white} ");

    start->setFixedWidth(150);
    start->setAlignment(Qt::AlignCenter);


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

int trainingDialog::showExNumberDialog()
{
    bool ok = false;
    QInputDialog* dial = new QInputDialog(this);
    this -> setStyleSheet("QInputDialog{background-color : #404244}"
                          "QInputDialog QWidget{background-color: #404244; color: white ; selection-background-color: #c26110 ;"
                          "selection-color : white}"
                          "QInputDialog  QLabel{background-color : #404244; color: white}"
                          "QInputDialog QLineEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                          "selection-color : white}");
    int remove = dial->getInt(this,tr("Esercizi da inserire"),"Quantità: ",1,1,15,1,&ok);
    if(!ok) throw std::runtime_error("Nessun numero scelto, inserimento annullato!");
    return remove;
}

trainingDialog::trainingDialog(QWidget *parent, action act, const Training* training) : QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    bool ok;
    pos = 0;
    exPos = 0;
    exAct = nothing;

    if (act == add)
    {
        type = typeDialog::getType(this,&ok);
        if (type == "Camminata" || type == "Corsa" || type == "Ciclismo")
        {
            type = "Endurance";
            setupCommon(mainL,act);
            setupEndurance(mainL,act);
        }
        else //if(type == "Tennis" || type == "Rugby")
        {
            type = "Repetition";
            setupRepetition(mainL,act);
        }

    }
    else if (act == set || act == eliminate)
    {
        if (dynamic_cast<const Endurance*>(training))
        {
            type = "Endurance";
            setupCommon(mainL,act,training);
            setupEndurance(mainL,act,static_cast<const Endurance*>(training));
        }
        else //if(type == "Tennis" || type == "Rugby")
        {
            type = "Repetition";
            setupRepetition(mainL,act, static_cast<const Repetition*>(training));
        }

    }
    else
        throw std::runtime_error("Tipo di operazione non consentito!");

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
                      this, &trainingDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
        this, &trainingDialog::reject);
    Q_ASSERT(conn);

    setLayout(mainL);
}

trainingValues trainingDialog::getValues(QWidget *parent, bool *ok, action act, const Training* training)
{
    trainingDialog *dialog = new trainingDialog(parent,act,training);

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
        int pos = 0, exPos = 0;
        action exAct = nothing;
        double distance = 0.0;
        if (ret) {
            type = dialog->type;
            name = dialog->name->text();
            start = dialog->start->dateTime();
            pos = dialog->pos;
            if(type == "Repetition")
            {
                exPos = dialog->exPos;
                exAct = dialog->exAct;
                for (unsigned int i = 0; i < dialog->nameEx.size(); ++i)
                {
                    exName.push_back(dialog->nameEx[i]->text());
                    exDuration.push_back(dialog->exDuration[i]->time());
                    recovery.push_back(dialog->exRecovery[i]->time());
                }
            }
            else if(type == "Endurance")
            {
                distance = dialog->distance->value();
                duration = dialog->duration->time();
            }
            else
                throw std::runtime_error("Tipo di allenamento errato!");
        }
        dialog->deleteLater();
        return trainingValues(type,start,name,distance,duration,exName,exDuration,recovery,act,pos,exAct, exPos);
}
