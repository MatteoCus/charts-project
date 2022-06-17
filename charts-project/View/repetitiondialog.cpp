#include "repetitiondialog.h"
#include <iostream>
using namespace std;

repetitionDialog::repetitionDialog(QWidget *parent, action act, Repetition *training)
    :trainingDialog(parent)
{
    std::vector<QHBoxLayout *> exNameLayout;
    std::vector<QHBoxLayout *> exDurationLayout;
    std::vector<QHBoxLayout *> exRecoveryLayout;
    std::vector<QLabel*> exNameLabel;
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
        items << tr("Aggiungi esercizio") << tr("Inserisci esercizio") << tr("Modifica") << tr("Rimuovi esercizio");

        bool ok;
        std::string item = QInputDialog::getItem(this, tr("Esercizi"),
                                                 tr("Azione da effettuare:"), items, 0, false, &ok).toStdString();
        if (ok && item !="")
        {
            if (item == items.at(0).toStdString())
                exAct = add;
            else if (item == items.at(1).toStdString())
                exAct = insert;
            else if (item == items.at(2).toStdString())
                exAct = set;
            else //if (item == "Rimuovi")
                exAct = eliminate;
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
            exNameLayout.push_back(new QHBoxLayout);
            QLabel* auxLabel = new QLabel(QString("Nome esercizio " + QString::fromStdString(std::to_string(i+1))), this);
            exNameLabel.push_back(auxLabel);
            auxLabel->setFont(font);

            QLineEdit* auxEdit;
            QTimeEdit* auxDuration;
            QTimeEdit* auxRecovery;

            if (act == add)
            {
                auxEdit = new QLineEdit("Nome esercizio", this);
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

                if (act == eliminate || act == nothing)
                {
                    auxEdit->setReadOnly(true);
                    auxDuration->setReadOnly(true);
                    auxRecovery->setReadOnly(true);
                }
            }

            auxEdit->setAlignment(Qt::AlignCenter);
            auxEdit->setFixedWidth(120);
            exName.push_back(auxEdit);
            addToLayout(exNameLayout[i],exNameLabel[i],auxEdit);

            //Setup delle durate
            exDurationLayout.push_back(new QHBoxLayout);
            QLabel* exDurationLabel = new QLabel(QString("Durata attività"), this);
            exDurationLabel->setFont(font);


            auxDuration->setDisplayFormat("hh:mm:ss");
            auxDuration->setAlignment(Qt::AlignCenter);
            auxDuration->setFixedWidth(120);
            exDuration.push_back(auxDuration);
            addToLayout(exDurationLayout[i],exDurationLabel,auxDuration);

            //Setup dei recuperi
            exRecoveryLayout.push_back(new QHBoxLayout);
            QLabel* exRecoveryLabel = new QLabel(QString("Durata recupero"), this);
            exRecoveryLabel->setFont(font);

            auxRecovery->setDisplayFormat("hh:mm:ss");
            auxRecovery->setAlignment(Qt::AlignCenter);
            auxRecovery->setFixedWidth(120);
            exRecovery.push_back(auxRecovery);
            addToLayout(exRecoveryLayout[i],exRecoveryLabel,auxRecovery);

            //Setup layout
            repetitionLayout->setContentsMargins(0,10,5,10);
            repetitionLayout->addLayout(exNameLayout[i]);
            repetitionLayout->addLayout(exDurationLayout[i]);
            repetitionLayout->addLayout(exRecoveryLayout[i]);
        }

    }
    else
    {
        setupCommon(firstLayout,eliminate,training);

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
            exPos = QInputDialog::getInt(this,QString("Elimina esercizio"),QString("Posizione"),1,1,training->getSize(),1,&ok);
            exPos--;
            if (!ok)
                throw std::runtime_error("Posizione di eliminazione esercizio non valida!");
        }

        //Setup dei nomi
        exNameLayout.push_back(new QHBoxLayout);
        QLabel* auxLabel = new QLabel(QString("Nome esercizio " + QString::fromStdString(std::to_string(exPos+1))), this);
        exNameLabel.push_back(auxLabel);
        auxLabel->setFont(font);

        QLineEdit* auxEdit;
        QTimeEdit* auxDuration;
        QTimeEdit* auxRecovery;

        if (exAct == add || exAct == insert)
        {
            auxEdit = new QLineEdit("Nome esercizio",this);
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

        auxEdit->setAlignment(Qt::AlignCenter);
        auxEdit->setFixedWidth(120);
        exName.push_back(auxEdit);
        addToLayout(exNameLayout[0],exNameLabel[0],auxEdit);

        //Setup delle durate
        exDurationLayout.push_back(new QHBoxLayout);
        QLabel* exDurationLabel = new QLabel(QString("Durata attività"), this);
        exDurationLabel->setFont(font);

        auxDuration->setDisplayFormat("hh:mm:ss");
        auxDuration->setAlignment(Qt::AlignCenter);
        auxDuration->setFixedWidth(120);
        exDuration.push_back(auxDuration);
        addToLayout(exDurationLayout[0],exDurationLabel,auxDuration);

        //Setup dei recuperi
        exRecoveryLayout.push_back(new QHBoxLayout);
        QLabel* exRecoveryLabel = new QLabel(QString("Durata recupero"), this);
        exRecoveryLabel->setFont(font);

        auxRecovery->setDisplayFormat("hh:mm:ss");
        auxRecovery->setAlignment(Qt::AlignCenter);
        auxRecovery->setFixedWidth(120);
        exRecovery.push_back(auxRecovery);
        addToLayout(exRecoveryLayout[0],exRecoveryLabel,auxRecovery);

        //Setup layout
        firstLayout->setContentsMargins(0,10,5,10);
        firstLayout->addLayout(exNameLayout[0]);
        firstLayout->addLayout(exDurationLayout[0]);
        firstLayout->addLayout(exRecoveryLayout[0]);
    }
    addButtons();

    setFixedSize((exName.size()+2)/3 * 250 + 15, exName.size() < 3? 100 + exName.size() * 110 : 440);
}

dialogValues repetitionDialog::getValues(QWidget *parent, bool *ok, action act, Repetition *training)
{
    repetitionDialog *dialog = new repetitionDialog(parent,act,training);
    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    QString name;
    std::vector<QString> exName;
    std::vector<QTime> exDuration;
    std::vector<QTime> recovery;
    QDateTime start;
    int pos = 0, exPos = 0;
    action exAct = nothing;
    if (ret) {
        name = dialog->name->text();
        start = dialog->start->dateTime();
        pos = dialog->pos;
        exPos = dialog->exPos;
        exAct = dialog->exAct;
        for (unsigned int i = 0; i < dialog->exName.size(); ++i)
        {
            exName.push_back(dialog->exName[i]->text());
            exDuration.push_back(dialog->exDuration[i]->time());
            recovery.push_back(dialog->exRecovery[i]->time());
        }

    }
    else
        throw std::runtime_error("Operazione annullata!");
    dialog->deleteLater();
    return dialogValues("",start,name,0,QTime(),exName,exDuration,recovery,pos,exAct, exPos);
}
