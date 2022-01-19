#include "datawidget.h"

void dataWidget::adaptTable(unsigned int w, unsigned int h, QTableWidget* table)
{
    for(int i = 0; i < table->columnCount() ; i++)
        w += table->columnWidth(i);
    for(int i = 0; i < table->rowCount() ; i++)
        h += table->rowHeight(i);
    if(w > 700)
        w = 700;
    if(h > 600)
        h = 600;
    table->setFixedSize(w,h);
}

void dataWidget::addTable(QVBoxLayout* tableLayout)
{
    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"Esercizi");
    table->setStyleSheet("QHeaderView::section { color : white ; background-color: #4d7aa7}  "
                         "QTableWidget::item {color : white ;  gridline-color: #4d7aa7 ; background-color : #404244}"
                         "QTableView QLineEdit {color : white ; background-color : #404244}");

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    table->setColumnWidth(0,100);
    table->setColumnWidth(1,100);
    table->setColumnWidth(2,50);
    table->setColumnWidth(3,100);
    table->setColumnWidth(4,50);
    table->setColumnWidth(5,150);
    table->setAcceptDrops(false);

    unsigned int w = 2, h = 25;         //default values to adapt the table
    adaptTable(w, h, table);
    tableLayout->addWidget(table);
}

void dataWidget::addLabel(QVBoxLayout* tableLayout)
{
    QLabel* title = new QLabel("Dati", this);
    title->setFixedSize(50,25);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel { background-color : #4d7aa7 ; color : white; }");
    tableLayout->addWidget(title);
    tableLayout->setAlignment(title, Qt::AlignHCenter);
}



void dataWidget::addLabelTable(QHBoxLayout* mainLayout)
{
    QVBoxLayout* tableLayout = new QVBoxLayout();

    tableLayout->setSpacing(20);
    tableLayout->setAlignment(Qt::AlignCenter);
    tableLayout->setAlignment(Qt::AlignTop);

    addLabel(tableLayout);
    addTable(tableLayout);

    mainLayout->addLayout(tableLayout);
}

void dataWidget::addControls(QHBoxLayout* mainLayout)
{
    QVBoxLayout * controlLayout = new QVBoxLayout();
    controlLayout->setAlignment(Qt::AlignTop);
    controlLayout->setContentsMargins(10,30,10,30);
    controlLayout->setSpacing(10);

    QPushButton* addButton = new QPushButton("Aggiungi", this);
    QPushButton* setButton = new QPushButton("Modifica", this);
    QPushButton* removeButton = new QPushButton("Rimuovi", this);
    addButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    removeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    addButton->setFixedSize(70,25);
    setButton->setFixedSize(70,25);
    removeButton->setFixedSize(70,25);
    addButton->setStyleSheet("QPushButton { background-color : #4d7aa7 ; color : white; }");
    setButton->setStyleSheet("QPushButton { background-color : #4d7aa7 ; color : white; }");
    removeButton->setStyleSheet("QPushButton { background-color : #4d7aa7 ; color : white; }");

    controlLayout->addWidget(addButton);
    controlLayout->addWidget(setButton);
    controlLayout->addWidget(removeButton);


    mainLayout->addLayout(controlLayout);
}

dataWidget::dataWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout();

    addLabelTable(mainLayout);

    addControls(mainLayout);
    setStyleSheet("QWidget {background : #2e2f30}");        //TOGLIERE ALLA FINE DELLA CREAZIONE DELLA VIEW
    setLayout(mainLayout);
    show();
}

/*FUNZIONE PER FARE IL RESIZE DELLA TABELLA (COLONNE, RIGHE E "SFONDO BIANCO")
 *     //da qui
    table->insertRow(0);
    table->insertRow(0);
    QTableWidgetItem* it = new QTableWidgetItem("35:42");
        it->setFlags(it->flags() ^ Qt::ItemIsEditable);                             //per rendere non editabile un campo
        table->setItem(0, 2, it);
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
