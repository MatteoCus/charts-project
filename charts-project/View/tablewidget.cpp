#include "tablewidget.h"
#include <iostream>

std::string value2string(double value)
{
  std::ostringstream out;
  out << std::fixed << std::setprecision(2) << value;
  return out.str();
}

void tableWidget::setLabelStyleSheet(QLabel *name)
{
    name->setStyleSheet("QLabel {background-color: #404244; color: white}");
}

void tableWidget::addToLayout(QBoxLayout *layout, QWidget *w1, QWidget *w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void tableWidget::adaptTable(unsigned int w, unsigned int h, QTableWidget* table)
{
    for(int i = 0; i < table->columnCount() ; i++)
    {
        w += table->columnWidth(i);
        //table->resizeColumnsToContents();
    }

    for(int i = 0; i < table->rowCount() ; i++)
        h += table->rowHeight(i);
    if(w > 700)
        w = 700;
    if(h > 600)
        h = 600;

    table->setFixedSize(w,h);
}

void tableWidget::addTable(QVBoxLayout* tableLayout)
{
    table = new QTableWidget(this);
    table->setColumnCount(7);
    table->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Tipo"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"*");
    table->setStyleSheet("QHeaderView::section { color : white ; background-color: #c26110}  "
                         "QTableWidget::item {color : white ;  gridline-color: #c26110 ; background-color : #404244; selection-background-color: #c26110 ;"
                         "selection-color : white}"
                         "QLineEdit {color : white ; background-color : #404244; selection-background-color: #c26110 ;"
                         "selection-color : white}");

    table->insertRow(0);
    QTableWidgetItem* it[7];
    for(unsigned int i = 0 ; i < 7 ; i++)
    {
        it[i] = new QTableWidgetItem();
        it[i]->setFlags(it[i]->flags() ^ Qt::ItemIsEditable);                             //per rendere non editabile un campo
        table->setItem(0, i, it[i]);
    }
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->setColumnWidth(0,150);
    table->setColumnWidth(1,65);
    table->setColumnWidth(2,135);
    table->setColumnWidth(3,65);
    table->setColumnWidth(4,135);
    table->setColumnWidth(5,50);
    table->setColumnWidth(6,80);
    unsigned int w = 17, h = 25;         //default values to adapt the table
    adaptTable(w, h, table);


    tableLayout->addWidget(table);
}



void tableWidget::addControlTable(QVBoxLayout* mainLayout)
{
    tableLayout = new QVBoxLayout();

    //tableLayout->setSpacing(20);
    tableLayout->setAlignment(Qt::AlignCenter);
    tableLayout->setAlignment(Qt::AlignTop);

    addControls(mainLayout);
    addTable(tableLayout);
    mainLayout->addLayout(tableLayout);
    addLabel(tableLayout);
}

void tableWidget::addControls(QVBoxLayout* mainLayout)
{
    QHBoxLayout * controlLayout = new QHBoxLayout();
    controlLayout->setAlignment(Qt::AlignTop);
    controlLayout->setContentsMargins(0,0,0,10);
    controlLayout->setSpacing(10);

    addButton = new QPushButton("Aggiungi", this);
    setButton = new QPushButton("Modifica", this);
    removeButton = new QPushButton("Rimuovi", this);
    exerciseButton = new QPushButton("Visualizza esercizi", this);

    addButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    removeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    exerciseButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    addButton->setFixedSize(70,25);
    setButton->setFixedSize(70,25);
    removeButton->setFixedSize(70,25);
    exerciseButton->setFixedSize(130,25);

    addButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");
    setButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");
    removeButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");
    exerciseButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");

    controlLayout->addWidget(addButton);
    controlLayout->addWidget(setButton);
    controlLayout->addWidget(removeButton);
    controlLayout->addWidget(exerciseButton);

    connect(exerciseButton, SIGNAL(clicked()), this, SLOT(showExercises()));

    mainLayout->addLayout(controlLayout);
}

void tableWidget::addLabel(QVBoxLayout *tableLayout)
{
    QLabel* label = new QLabel(QString::fromStdString("* : Distanza percorsa in allenamento / Intensità dell'allenamento"),this);
    label->setFixedSize(380,20);
    label->setStyleSheet("QLabel {color: white}");
    tableLayout->addWidget(label);
}

void tableWidget::setupCommon(QVBoxLayout* mainL, const Training* training)
{
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *startLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    QLabel* nameLabel = new QLabel(QString("Nome"), this);

    if (!training)
            throw std::runtime_error("Allenamento non valido!");
    Date date = training->getStart().getDate();
    Time time = training->getStart().getTime();
    QString trainingName = QString::fromStdString(training->getName());
    QDateTime* qdatetime = new QDateTime(QDate(date.getYear(),date.getMonth(), date.getDay()), QTime(time.getHours(),time.getMinutes(),time.getSeconds()));

    QLineEdit* name = new QLineEdit(trainingName, this);
    QDateTimeEdit* start = new QDateTimeEdit(*qdatetime,this);

    name->setReadOnly(true);
    start->setReadOnly(true);
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

void tableWidget::setupExercises(QVBoxLayout *mainL, const Repetition *training)
{
    std::vector<QHBoxLayout *> nameExLayout;
    std::vector<QHBoxLayout *> exDurationLayout;
    std::vector<QHBoxLayout *> exRecoveryLayout;

    std::vector<QLineEdit*> nameEx;
    std::vector<QTimeEdit*> exDuration;
    std::vector<QTimeEdit*> exRecovery;

    std::vector<QLabel*> nameExLabel;
    std::vector<QVBoxLayout *> rowLayout;
    QVBoxLayout * firstLayout = new QVBoxLayout;
    QFont font;
    font.setItalic(true);

    setupCommon(firstLayout,training);

    firstLayout->setContentsMargins(0,0,15,0);
    rowLayout.push_back(firstLayout);
    unsigned int exNumber = training->getExercises().size();
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

        Exercise* ex = training->getExercise(i);
        Time dur = ex->getDuration();
        Time rec = ex->getRecoveryTime();

        auxEdit = new QLineEdit(QString::fromStdString(ex->getName()));
        auxDuration = new QTimeEdit(QTime(dur.getHours(),dur.getMinutes(),dur.getSeconds()),this);
        auxRecovery = new QTimeEdit(QTime(rec.getHours(),rec.getMinutes(),rec.getSeconds()),this);

         auxEdit->setReadOnly(true);
         auxDuration->setReadOnly(true);
         auxRecovery->setReadOnly(true);


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


void tableWidget::showExercises()
{
    //showTrainingExercises();
    QDialog* dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->setStyleSheet("QDialog{background-color: #404244}");
    QVBoxLayout* mainLayout = new QVBoxLayout;
    bool ok, found = false;
    QString start = selectTrainingDialog::getDate(this,&ok,trainings,"Repetition");
    if (start != "")
    {
        unsigned int n = 0;
        auto training = trainings->begin();
        for (unsigned int i = 0; i < trainings->size() && !found ; ++i)
        {
            if ((*training)->getStart().toString() == start.toStdString())
            {
                found = true;
                n = i;
            }
            if (training != trainings->end())
                std::advance(training,1);
        }
        training = trainings->begin();
        std::advance(training,n);
        if (found && dynamic_cast<const Repetition*>(*training))
        {
            const Repetition* aux = static_cast<const Repetition*>(*training);
            setupExercises(mainLayout,aux);
            dialog->setLayout(mainLayout);
            dialog->exec();
        }
        else
            throw std::runtime_error("Tipo di allenamento selezionato non valido!");
    }
    else
        delete mainLayout;
}

tableWidget::tableWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout();

    addControlTable(mainLayout);

    setLayout(mainLayout);
}

void tableWidget::setLineEdit(QLineEdit* item)
{
    item->setAlignment(Qt::AlignCenter);
    item->setReadOnly(true);
}

void tableWidget::showData()
{
    for (int i=0 ; i < table->rowCount(); ++i)
        table->removeRow(i);

    for (auto it = trainings->begin(); it != trainings->end(); ++it)
    {
        table->insertRow(0);
        QLineEdit* item = new QLineEdit(QString::fromStdString((*it)->getName()),this);
        setLineEdit(item);
        table->setCellWidget(0,0,item);

        item = new QLineEdit(QString::fromStdString((*it)->getStart().toString()),this);
        setLineEdit(item);
        table->setCellWidget(0,2,item);

        item = new QLineEdit(QString::fromStdString((*it)->getDuration().toString()),this);
        setLineEdit(item);
        table->setCellWidget(0,3,item);

        item = new QLineEdit(QString::fromStdString((*it)->getEnd().toString()),this);
        setLineEdit(item);
        table->setCellWidget(0,4,item);

        item = new QLineEdit(QString::fromStdString(std::to_string((*it)->CaloriesBurned())),this);
        setLineEdit(item);
        table->setCellWidget(0,5,item);

        if (dynamic_cast<const Endurance*>(*it))
        {
            item = new QLineEdit(QString::fromStdString(value2string(static_cast<const Endurance*>(*it)->getDistance()) + " km"),this);
            setLineEdit(item);
            table->setCellWidget(0,6,item);

            if (dynamic_cast<const Run*>(*it))
                item = new QLineEdit(QString::fromStdString("Corsa"));
            else if (dynamic_cast<const Walk*>(*it))
                item = new QLineEdit(QString::fromStdString("Camminata"));
            else
                item = new QLineEdit(QString::fromStdString("Ciclismo"));
        }
        else
        {
            item = new QLineEdit(QString::fromStdString(value2string(static_cast<const Repetition*>(*it)->Intensity()) + " %"),this);
            setLineEdit(item);
            table->setCellWidget(0,6,item);

            if (dynamic_cast<const Tennis*>(*it))
                item = new QLineEdit(QString::fromStdString("Tennis"));
            else
                item = new QLineEdit(QString::fromStdString("Rugby"));
        }
        setLineEdit(item);
        table->setCellWidget(0,1,item);
        adaptTable(14,22,table);
    }
}

void tableWidget::setData(const std::list<const Training *> *data)
{
    trainings = data;
}

/*FUNZIONE PER FARE IL RESIZE DELLA TABELLA (COLONNE, RIGHE E "SFONDO BIANCO")
 *     //da qui
    table->insertRow(0);
    table->insertRow(0);
    QLineEdit* it = new QLineEdit("35:42");
        it->setFlags(it->flags() ^ Qt::ItemIsEditable);                             //per rendere non editabile un campo
        table->setCellWidget(0, 2, it);
        table->resizeColumnToContents(2);
        //table->resizeColumnsToContents();
        table->resizeRowsToContents();
        w = 17, h = 25;     //W ha 17 invece di 2 a causa dei numeri sui lati della tabella--> vedi te
        for(int i = 0; i < table->columnCount() ; i++)
            w += table->columnWidth(i);
        for(int i = 0; i < table->rowCount() ; i++)
            h += table->rowHeight(i);
        if(w > 800)
            w = 800;
        if(h > 600)
            h = 600;
        table->setFixedSize(w,h);
    //a qui*/
