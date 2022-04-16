#include "chartviewer.h"
#include <iostream>

void chartViewer::addMenu(QHBoxLayout* mainLayout)
{
    QMenuBar* menuBar = new QMenuBar(this);

    menuBar->setStyleSheet("QMenuBar {background-color : #404244 ; color: white; }"
                           "QMenuBar::item:selected {background-color : #c26110;}"
                           "QMenu {background-color : #404244 ; color: white; }"
                           "QMenu::item:selected {background-color : #c26110;}");

    QMenu *file = new QMenu("File", menuBar);
    QMenu *visualizza = new QMenu("Visualizza", menuBar);
    QMenu *allenamenti= new QMenu("Allenamenti", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(visualizza);
    menuBar->addMenu(allenamenti);

    //Menù "File"
    file->addAction(new QAction("Apri", file));
    file->addAction(new QAction("Nuovo", file));
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Salva col nome", file));
    file->addAction(new QAction("Chiudi", file));
    file->addAction(new QAction("Esci", file));

    //Menù "visualizza"
    visualizza->addAction(new QAction("Line Chart", visualizza));
    visualizza->addAction(new QAction("Bar Chart", visualizza));
    visualizza->addAction(new QAction("Other Chart", visualizza));

    //Menù "allenamenti"
    allenamenti->addAction(new QAction("Aggiungi", allenamenti));
    allenamenti->addAction(new QAction("Modifica", allenamenti));
    allenamenti->addAction(new QAction("Rimuovi", allenamenti));

    mainLayout->setMenuBar(menuBar);
}

chartViewer::chartViewer(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QHBoxLayout;

    dataW = new dataWidget(this);
    chartW = new chartWidget(this);
    mainLayout->setSpacing(40);
    mainLayout->addWidget(dataW);
    mainLayout->addWidget(chartW);
    mainLayout->setContentsMargins(10,90,10,20);
    addMenu(mainLayout);
    setLayout(mainLayout);
    setStyleSheet("QWidget{background-color : #2e2f30}");
    trainingValues t = showAddDialog();
    std::cout<<t.name.toStdString()<<" "<<t.start.date().day()<<" "<<t.start.date().month()<<" "<<t.start.date().year()<<" "<<std::endl;
    if (t.type.toStdString() == "Corsa" || t.type.toStdString() == "Ciclismo" || t.type.toStdString() == "Ciclismo")
        std::cout<<t.duration.hour()<<":"<<t.duration.minute()<<":"<<t.duration.second()<<" "<<t.distance<<std::endl;
    resize(1200,700);
}

void chartViewer::showWarning(const QString &message)
{
    dialog = new QDialog(this);
    dialog->setModal(true);
    QFont serifFont("Arial", 11);
    dialog->setLayout(new QHBoxLayout);
    QLabel* label = new QLabel(message, dialog);
    label->setFont(serifFont);
    dialog->layout()->addWidget(label);
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMinimumWidth(120);
    dialog->setMaximumWidth(500);
    dialog->setMaximumHeight(400);
    dialog->setStyleSheet("QWidget {background-color: #404244 ; color: white}");
    dialog->show();
}

QString chartViewer::showImportDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Documenti (*.xml)"));
    if (fileName == "")
        throw std::runtime_error("Nessun file scelto, aggiunta annullata!");

    return fileName;
}

trainingValues chartViewer::showAddDialog()
{
    bool ok;
    return addDialog::getValues(this, &ok);
}

/*trainingValues chartViewer::showRemoveDialog()
{
    bool ok;
    return trainingDialog::getValues(this, &ok,eliminate, trainings);
}

trainingValues chartViewer::showSetDialog()
{
    bool ok;
    return trainingDialog::getValues(this, &ok,set,trainings);
}*/
