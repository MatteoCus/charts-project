#include "datawidget.h"

dataWidget::dataWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout();

    //lable
    QVBoxLayout* tableLayout = new QVBoxLayout();
    QLabel* title = new QLabel("Dati", this);
    title->setFixedSize(50,25);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("QLabel { background-color : #6cbbf4 ; color : white; }");
    tableLayout->setSpacing(20);
    tableLayout->addWidget(title);
    tableLayout->setAlignment(title, Qt::AlignHCenter);
//#8FBE16
//#172138

    //table
    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels(QStringList()<<"Nome"<<"Inizio"<<"Durata"<<"Fine"<<"Calorie"<<"Esercizi");
    table->setColumnWidth(0,100);
    table->setColumnWidth(1,100);
    table->setColumnWidth(2,50);
    table->setColumnWidth(3,100);
    table->setColumnWidth(4,50);
    table->setColumnWidth(5,150);
    table->setAcceptDrops(false);

    unsigned int w = 2, h = 25;
    for(int i = 0; i < table->columnCount() ; i++)
        w += table->columnWidth(i);
    for(int i = 0; i < table->rowCount() ; i++)
        h += table->rowHeight(i);
    if(w > 800)
        w = 800;
    if(h > 600)
        h = 600;
    table->setFixedSize(w,h);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    tableLayout->addWidget(table);
    tableLayout->setAlignment(Qt::AlignCenter);
    tableLayout->setAlignment(Qt::AlignTop);

    //push buttons
    QVBoxLayout * controlLayout = new QVBoxLayout();
    QPushButton* addButton = new QPushButton("Aggiungi", this);
    QPushButton* setButton = new QPushButton("Modifica", this);
    QPushButton* removeButton = new QPushButton("Rimuovi", this);
    addButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    removeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    addButton->setFixedSize(70,25);
    setButton->setFixedSize(70,25);
    removeButton->setFixedSize(70,25);
    addButton->setStyleSheet("QPushButton { background-color : #6cbbf4 ; color : white; }");
    setButton->setStyleSheet("QPushButton { background-color : #6cbbf4 ; color : white; }");
    removeButton->setStyleSheet("QPushButton { background-color : #6cbbf4 ; color : white; }");
    controlLayout->setSpacing(10);
    controlLayout->addWidget(addButton);
    controlLayout->addWidget(setButton);
    controlLayout->addWidget(removeButton);
    controlLayout->setAlignment(Qt::AlignTop);
    controlLayout->setContentsMargins(10,30,10,30);

    mainLayout->addLayout(tableLayout);
    mainLayout->addLayout(controlLayout);
    setLayout(mainLayout);
    resize(1024,720);
    show();
}

/*FUNZIONE PER FARE IL RESIZE DELLA TABELLA (COLONNE, RIGHE E "SFONDO BIANCO")
 * QTableWidgetItem* it = new QTableWidgetItem("35:42");
    it->setFlags(it->flags() ^ Qt::ItemIsEditable);                             //per rendere non editabile un campo
    table->setItem(0, 2, it);
    table->resizeColumnToContents(2);
    table->resizeColumnsToContents();
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
    table->setFixedSize(w,h);*/
