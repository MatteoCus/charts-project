#include "trainingdialog.h"

void trainingDialog::setLabelStyleSheet(QLabel* name)
{
    name->setStyleSheet("QLabel {background-color: #404244; color: white}");
}

void trainingDialog::addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void trainingDialog::setupRepetition(QBoxLayout* mainL)
{
    QHBoxLayout *nameExLayout = new QHBoxLayout;
    QLabel* nameExLabel = new QLabel(QString("Nome primo esercizio"), this);
    nameEx = new QLineEdit(this);
    nameEx->setStyleSheet("QLineEdit {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                          "selection-color : white} ");

    setLabelStyleSheet(nameExLabel);

    addToLayout(nameExLayout,nameExLabel,nameEx);

    QHBoxLayout *exDurationLayout = new QHBoxLayout;
    exDuration = new QTimeEdit(QTime(1,0,0),this);
    exDuration->setStyleSheet("QTimeEdit {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                              "selection-color : white} ");
    QLabel* exDurationLabel = new QLabel(QString("Durata attività esercizio"), this);
    exDuration->setDisplayFormat("hh:mm:ss");

    setLabelStyleSheet(exDurationLabel);
    addToLayout(exDurationLayout,exDurationLabel,exDuration);

    QHBoxLayout *recoveryLayout = new QHBoxLayout;
    recovery = new QTimeEdit(QTime(1,0,0),this);
    recovery->setStyleSheet("QTimeEdit {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                            "selection-color : white} ");
    QLabel* recoveryLabel = new QLabel(QString("Durata recupero esercizio"), this);
    exDuration->setDisplayFormat("hh:mm:ss");

    setLabelStyleSheet(recoveryLabel);
    addToLayout(recoveryLayout,recoveryLabel,recovery);

    mainL->addLayout(exDurationLayout);
    mainL->addLayout(recoveryLayout);
    mainL->addLayout(nameExLayout);
}

void trainingDialog::setupEndurance(QBoxLayout* mainL)
{
    QHBoxLayout *distanceLayout = new QHBoxLayout;
    distance = new QDoubleSpinBox(this);
    distance->setStyleSheet("QDoubleSpinBox {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                            "selection-color : white} ");
    QLabel* distanceLabel = new QLabel(QString("Distanza percorsa"), this);

    setLabelStyleSheet(distanceLabel);
    addToLayout(distanceLayout,distanceLabel,distance);

    QHBoxLayout *durationLayout = new QHBoxLayout;
    duration = new QTimeEdit(QTime(1,0,0),this);
    duration->setStyleSheet("QTimeEdit {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                            "selection-color : white} ");
    QLabel* durationLabel = new QLabel(QString("Durata allenamento"), this);
    duration->setDisplayFormat("hh:mm:ss");

    setLabelStyleSheet(durationLabel);
    addToLayout(durationLayout,durationLabel,duration);

    mainL->addLayout(distanceLayout);
    mainL->addLayout(durationLayout);
}

void trainingDialog::setupCommon(QBoxLayout* mainL, action act, QString nameTraining, QString startTraining) //name e date possono essere vuoti
{
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *startLayout = new QHBoxLayout;

    setStyleSheet("QDialog{background-color: #404244}");

    QLabel* nameLabel = new QLabel(QString("Nome allenamento"), this);
    if (act == add)
    {
        name = new QLineEdit(QString("Nome Allenamento"), this);
        start = new QDateTimeEdit(QDateTime::currentDateTime());
    }
    else
    {
        name = new QLineEdit(nameTraining, this);
        start->setMinimumDate(QDate(1970,1,1));
        start->setMaximumDate(QDate::currentDate());
        start->setDisplayFormat("dd.MM.yyyy hh:mm:ss");
        start = new QDateTimeEdit(QDateTime()); //serve un parser per le date

    }

    if (act == eliminate)
    {
        name->setReadOnly(true);
        start->setReadOnly(true);
    }

    name->setStyleSheet("QLineEdit {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                        "selection-color : white} ");

    setLabelStyleSheet(nameLabel);

    addToLayout(nameLayout,nameLabel,name);

    QLabel* startLabel = new QLabel(QString("Inizio"), this);
    start->setStyleSheet("QDateTimeEdit {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");

    setLabelStyleSheet(startLabel);

    addToLayout(startLayout,startLabel,start);

    mainL->addLayout(nameLayout);
    mainL->addLayout(startLayout);
}

trainingDialog::trainingDialog(QWidget *parent, action act, const std::vector<Training*>* trainings) : QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    bool ok;
    if (act == add)
    {
        setupCommon(mainL,act);
        type = typeDialog::getType(this,&ok);
        if(type == "Tennis" || type == "Rugby")
            setupRepetition(mainL);
        else //if (type == "Camminata" || type == "Corsa" || type == "Ciclismo")
            setupEndurance(mainL);
    }
    else
    {
        QString date = selectTrainingDialog::getDate(this,&ok,trainings);
        //trova valori del training
        setupCommon(mainL,act,date);
        //fai metodo privato setup che faccia vedere solamente durata, data di fine e dati comuni a tutti
        //gli allenamenti se siamo in una remove... se siamo in una set, occorre specificare il tipo di training
        // e quindi occorre andare a creare due setup diversi (di cui uno deve far vedere tutti gli esercizi di un training)
    }

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Orientation::Horizontal,this);

    QPushButton* first = new QPushButton(QString("Ok"), buttonBox);
    first->setStyleSheet("QPushButton {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    first->setDefault(true);

    QPushButton* second = new QPushButton(QString("Cancel"), buttonBox);
    second->setStyleSheet("QPushButton {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
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

trainingValues trainingDialog::getValues(QWidget *parent, bool *ok, action act, const std::vector<Training*>* trainings)
{
    trainingDialog *dialog = new trainingDialog(parent, act, trainings);

        const int ret = dialog->exec();
        if (ok)
            *ok = !!ret;

        QString name;
        QString exName;
        QTime duration;
        QTime exDuration;
        QTime recovery;
        QDateTime start;
        QString type;
        double distance = 0.0;
        if (ret) {      //modifica per modifica di tutti gli esercizi di un repetition (metti un indice dell'esercizio modificato)

            type = dialog->type;
            name = dialog->name->text();
            start = dialog->start->dateTime();
            if(type == "Tennis" || type == "Rugby")
            {
                exName = dialog->nameEx->text();
                exDuration = dialog->exDuration->time();
                recovery = dialog->recovery->time();
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
