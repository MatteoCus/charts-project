#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent)
{
    chartViewer* mainWidget = new chartViewer(this);
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
    allenamenti->addAction(new QAction("Rimuovi", allenamenti));

    setStyleSheet("QMainWindow {background-color : #2e2f30}");
    setMenuBar(menuBar);
    setCentralWidget(mainWidget);
    show();
}
