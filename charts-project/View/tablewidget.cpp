#include "tablewidget.h"
#include <iostream>
using namespace std;

std::string value2string(double value)
{
  std::ostringstream out;
  out << std::fixed << std::setprecision(2) << value;
  return out.str();
}

void tableWidget::setLabelColor(QLabel *label)
{
    label->setStyleSheet("QLabel { color: white}");
}

void tableWidget::setLabelBackground(QLabel *label)
{
    QString style = label->styleSheet();
    style +=" QLabel{background-color: #404244 }";
    label->setStyleSheet(style);
}

void tableWidget::setCheckBoxStyleSheet(QCheckBox *checkBox)
{
    checkBox->setStyleSheet("QCheckBox { color : white} "
                                "QCheckBox::indicator {background-color: #c26110 ; border : 1px solid #c26110}"
                                 "QCheckBox::indicator:unchecked:pressed {"
                                     "background-color : #ca7833;"
                                 "}"

                                 "QCheckBox::indicator:checked {"
                                     "image: url(/home/matteo/Documenti/GitHub/charts-project/charts-project/icons/tick.png);"
                                    " width : 12 px; height : 12 px"
                                 "}"

                                 "QCheckBox::indicator:checked:pressed {"
                                     "image: url(/home/matteo/Documenti/GitHub/charts-project/charts-project/icons/tickPressed.png);"
                                    ""
                                 "}" );
}

void tableWidget::addToLayout(QBoxLayout *layout, QWidget *w1, QWidget *w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void tableWidget::adaptSingleTableHeight(unsigned int h, QTableWidget* table)
{
    for(int i = 0; i < table->rowCount() ; i++)
        h += table->rowHeight(i);

    if(h > 460)
        h = 460;

    table->setFixedHeight(h);
}

void tableWidget::adaptDoubleTableHeight(unsigned int h, QTableWidget *table)
{
    for(int i = 0; i < table->rowCount() ; i++)
        h += table->rowHeight(i);

    if(h > 200)
        h = 200;

    table->setFixedHeight(h);
}

void tableWidget::adaptTableWidth(unsigned int w, QTableWidget *table)
{
    for(int i = 0; i < table->columnCount() ; i++)
    {
            w += table->columnWidth(i);
            //table1->resizeColumnsToContents();
    }
    if(w > 700)
        w = 700;
    table->setFixedWidth(w);
}

void tableWidget::insertEmptyRow(QTableWidget* table)
{
    table->insertRow(0);

    QTableWidgetItem* it;
    for(unsigned int i = 0 ; i < 7 ; i++)
    {
        it = new QTableWidgetItem;
        it->setFlags(it->flags() ^ Qt::ItemIsEditable);
        table->setItem(0, i, it);
    }
   delete it;
}

void tableWidget::setTableStyleSheet(QTableWidget* table)
{

    table->setColumnCount(7);

    table->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Tipo"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"Intensità");
    table->setStyleSheet("QHeaderView::section { color : white ; background-color: #c26110}  "
                         "QTableWidget::item {color : white ;  gridline-color: #c26110 ; background-color : #404244; selection-background-color: #c26110 ;"
                         "selection-color : white}"
                         "QLineEdit {color : white ; background-color : #404244; selection-background-color: #c26110 ;"
                         "selection-color : white}");

    insertEmptyRow(table);

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->setColumnWidth(0,150);
    table->setColumnWidth(1,75);
    table->setColumnWidth(2,133);
    table->setColumnWidth(3,64);
    table->setColumnWidth(4,133);
    table->setColumnWidth(5,48);
    table->setColumnWidth(6,67);

}



void tableWidget::addControlTable()
{

    table1 = new QTableWidget(this);
    table2= new QTableWidget(this);
    table2->setVisible(false);

    tableLayout = new QVBoxLayout();
    table1Layout = new QVBoxLayout();
    table2Layout = new QVBoxLayout();

    table1Layout->setContentsMargins(0,0,0,20);
    addControls();


    label1 = new QLabel("Allenamenti in ordine cronologico",this);
    setLabelColor(label1);
    label1->setFixedSize(300,25);

    setTableStyleSheet(table1);
    table1Layout->addWidget(label1);
    table1Layout->addWidget(table1);

    adaptSingleTableHeight(22,table1);
    adaptTableWidth(15,table1);
    adaptTableWidth(15,table2);


    label2 = new QLabel("Allenamenti di resistenza in ordine cronologico",this);
    label2->setVisible(false);
    setLabelColor(label2);
    label2->setFixedSize(300,25);

    setTableStyleSheet(table2);
    table2Layout->addWidget(label2);
    table2Layout->addWidget(table2);

    table2->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Tipo"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"Distanza");

    tableLayout->addLayout(table1Layout);
    tableLayout->addLayout(table2Layout);
    mainLayout->addLayout(tableLayout);


}

void tableWidget::addControls()
{
    QHBoxLayout* controlBoxLayout = new QHBoxLayout;
    QHBoxLayout * controlLayout = new QHBoxLayout;

    controlBoxLayout->setAlignment(Qt::AlignLeft);
    controlBoxLayout->setContentsMargins(0,0, 0,10);

    controlLayout->setContentsMargins(0,0,50,0);
    controlLayout->setSpacing(10);

    addButton = new QPushButton("Aggiungi", this);
    setButton = new QPushButton("Modifica", this);
    removeButton = new QPushButton("Rimuovi", this);
    exerciseButton = new QPushButton("Visualizza esercizi", this);
    splitCheckBox = new QCheckBox("Split allenamenti resistenza");

    addButton->setFixedSize(70,25);
    setButton->setFixedSize(70,25);
    removeButton->setFixedSize(70,25);
    exerciseButton->setFixedSize(130,25);

    exerciseButton->hide();
    splitCheckBox->hide();

    addButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");
    setButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");
    removeButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");
    exerciseButton->setStyleSheet("QPushButton { background-color : #c26110 ; color : white; }");
    setCheckBoxStyleSheet(splitCheckBox);

    controlLayout->addWidget(addButton);
    controlLayout->addWidget(setButton);
    controlLayout->addWidget(removeButton);
    controlLayout->addWidget(exerciseButton);

    controlBoxLayout->addLayout(controlLayout);
    controlBoxLayout->addWidget(splitCheckBox);

    connect(exerciseButton, SIGNAL(clicked()), this, SIGNAL(showExercises()));
    connect(splitCheckBox, &QCheckBox::stateChanged, [this](int state){changeState(state,true);});

    mainLayout->addLayout(controlBoxLayout);
}

void tableWidget::changeState(int state, bool show)
{
    splitState = (state == Qt::CheckState::Unchecked ? false : true);

    if (splitState)
        label1->setText(QString::fromStdString("Allenamenti di ripetizione in ordine cronologico"));
    else        
        label1->setText(QString::fromStdString("Allenamenti in ordine cronologico"));

    label1->adjustSize();

    if(show)
        showData();
}

tableWidget::tableWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout();
    mainLayout->setAlignment(Qt::AlignTop);

    splitState = false;

    trainings = nullptr;

    addControlTable();

    setLayout(mainLayout);

    connect(addButton,SIGNAL(clicked()), this, SIGNAL(add()));
    connect(removeButton,SIGNAL(clicked()), this, SIGNAL(remove()));
    connect(setButton,SIGNAL(clicked()), this, SIGNAL(set()));
}

void tableWidget::setLineEdit(QLineEdit* item)
{
    item->setAlignment(Qt::AlignCenter);
    item->setReadOnly(true);
}

void tableWidget::showCommonData(Training* it, unsigned int i)
{
    i == 1? table1->insertRow(0) : table2->insertRow(0);
    QLineEdit* item = new QLineEdit(QString::fromStdString(it->getName()),this);
    setLineEdit(item);
    i == 1? table1->setCellWidget(0,0,item) : table2->setCellWidget(0,0,item);

    item = new QLineEdit(QString::fromStdString(it->getStart().toString()),this);
    setLineEdit(item);
    i == 1? table1->setCellWidget(0,2,item) : table2->setCellWidget(0,2,item);

    item = new QLineEdit(QString::fromStdString(it->getDuration().toString()),this);
    setLineEdit(item);
    i == 1? table1->setCellWidget(0,3,item) : table2->setCellWidget(0,3,item);

    item = new QLineEdit(QString::fromStdString(it->getEnd().toString()),this);
    setLineEdit(item);
    i == 1? table1->setCellWidget(0,4,item) : table2->setCellWidget(0,4,item);

    item = new QLineEdit(QString::fromStdString(std::to_string(it->CaloriesBurned())),this);
    setLineEdit(item);
    i == 1? table1->setCellWidget(0,5,item) : table2->setCellWidget(0,5,item);

    if (dynamic_cast<Endurance*>(it))
    {
        if (dynamic_cast<const Run*>(it))
            item = new QLineEdit(QString::fromStdString("Corsa"));
        else if (dynamic_cast<const Walk*>(it))
            item = new QLineEdit(QString::fromStdString("Camminata"));
        else
            item = new QLineEdit(QString::fromStdString("Ciclismo"));
    }
    else
    {
        if (dynamic_cast<const Tennis*>(it))
            item = new QLineEdit(QString::fromStdString("Tennis"));
        else
            item = new QLineEdit(QString::fromStdString("Rugby"));
    }
    setLineEdit(item);
    i == 1? table1->setCellWidget(0,1,item) : table2->setCellWidget(0,1,item);
}

void tableWidget::showRepetitionData(Repetition *training, unsigned int i)
{

    QLineEdit* item = new QLineEdit(QString::fromStdString(value2string(training->Intensity()) + " %"),this);
    setLineEdit(item);
    if(i == 1)
        table1->setCellWidget(0,6,item);
    else
        table2->setCellWidget(0,6,item);
}

void tableWidget::showEnduranceData(Endurance *training, unsigned int i)
{
    QLineEdit* item = new QLineEdit(QString::fromStdString(value2string(training->getDistance()) + " km"),this);
    setLineEdit(item);

    if(i == 1)
        table1->setCellWidget(0,6,item);
    else
        table2->setCellWidget(0,6,item);
}

void tableWidget::showData()
{
    table1->setVisible(false);
    table2->setVisible(false);

    while (table1->rowCount() > 0)
        table1->removeRow(0);

    while (table2->rowCount() > 0)
        table2->removeRow(0);

    bool foundRepetition = false, foundEndurance = false;

    for(auto it = trainings->begin(); it != trainings->end(); ++it)
    {
        if (!foundRepetition && dynamic_cast<Repetition*>(*it))
            foundRepetition = true;
        else if (!foundEndurance && dynamic_cast<Endurance*>(*it))
            foundEndurance = true;
    }

    if(splitState && foundEndurance != foundRepetition)
        changeState(Qt::CheckState::Unchecked,false);

    if (splitState)
    {
        table1->showColumn(6);
        table1->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Tipo"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"Intensità");
        tableLayout->setContentsMargins(0,0,0,0);

        for (auto it = trainings->begin(); it != trainings->end(); ++it)
        {
            if (dynamic_cast<Repetition*>(*it))
            {
                showCommonData(*it);
                showRepetitionData(static_cast<Repetition*>(*it));
            }
            else
            {
                showCommonData(*it,2);
                showEnduranceData(static_cast<Endurance*>(*it),2);
            }
        }
    }
    else
    {
        tableLayout->setContentsMargins(0,0,70,0);


        if(foundRepetition && !foundEndurance)
        {
            table1->showColumn(6);
            table1->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Tipo"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"Intensità");
        }
        else if(foundEndurance && !foundRepetition)
        {
            table1->showColumn(6);
            table1->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Tipo"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"Distanza");
        }
        else
            table1->hideColumn(6);

        for (auto it = trainings->begin(); it != trainings->end(); ++it)
        {
            showCommonData(*it);

            if (foundRepetition != foundEndurance)
            {
                if(foundRepetition)
                    showRepetitionData(static_cast<Repetition*>(*it));
                else
                    showEnduranceData(static_cast<Endurance*>(*it));
            }
        }
    }

    if (trainings->size() == 0)
    {
        table1->hideColumn(6);
        insertEmptyRow(table1);
    }

    if (!foundRepetition)
    {
        exerciseButton->setVisible(false);
        splitCheckBox->setVisible(false);
    }
    else
    {
        exerciseButton->setVisible(true);
        if (foundEndurance)
            splitCheckBox->setVisible(true);
        else
            splitCheckBox->setVisible(false);
    }

    if (splitState)
    {
        adaptDoubleTableHeight(22,table1);
        adaptDoubleTableHeight(22,table2);

        if (table1->rowCount() > 5)
            table1->setFixedWidth(698);
        else
            adaptTableWidth(15,table1);

        if(table2->rowCount() > 5)
            table2->setFixedWidth(698);
        else
            adaptTableWidth(15,table2);
    }
    else
    {
        adaptSingleTableHeight(22,table1);
        if(table1->rowCount() > 9)
            table1->setFixedWidth(622);
        else
            adaptTableWidth(15,table1);
    }



    table1->setVisible(true);
    table2->setVisible(splitState);
    label2->setVisible(splitState);
}

void tableWidget::setData(const std::list<Training *> *data)
{
    trainings = data;
}
