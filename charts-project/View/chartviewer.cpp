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
    visualizza->addAction(new QAction("Esercizi", visualizza));

    //Menù "allenamenti"
    allenamenti->addAction(new QAction("Aggiungi", allenamenti));
    allenamenti->addAction(new QAction("Modifica", allenamenti));
    allenamenti->addAction(new QAction("Rimuovi", allenamenti));

    mainLayout->setMenuBar(menuBar);
}

void chartViewer::findTraining(unsigned int &n, bool found, const QString& start)
{
    int i=0;
    for (auto it = trainings->begin(); it != trainings->end() && !found ; ++it)
    {
        i++;
        if (((*it)->getStart().toString() == start.toStdString()))
            found = true;
    }
    n = i-1;
}

chartViewer::chartViewer(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QHBoxLayout;

    dataW = new tableWidget(this);
    chartW = new chartWidget(this);
    mainLayout->setSpacing(40);
    mainLayout->addWidget(dataW);
    mainLayout->addWidget(chartW);
    mainLayout->setContentsMargins(10,90,10,20);
    addMenu(mainLayout);
    setLayout(mainLayout);
    setStyleSheet("QWidget{background-color : #2e2f30}");

    auto aux = new std::list<const Training*>;
    Date d = Date(21,04,2021);
    Date d2 = Date(21,05,2021);
    Time ti = Time(17);
    Training* t = new Run("C",DateTime(d,ti) ,7.59,TimeSpan(0,15));
    aux->push_back(t);
    trainings = aux;

    Tennis* tr = new Tennis("Tennis del martedì",DateTime(d2,ti));
    Exercise* ex = new Exercise("Primo", Time(0,15,0),Time(0,5,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    aux->push_back(tr);

    Date d3 = Date(21,06,2021);
    Time tim = Time(17);
    Tennis* tr2 = new Tennis("Cristo",DateTime(d3,tim));
    Exercise* ex2 = new Exercise("Primo", Time(0,15,0),Time(0,5,0));
    tr2->addExercise(ex2);
    ex2 = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr2->addExercise(ex2);
    ex2 = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr2->addExercise(ex2);
    ex2 = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr2->addExercise(ex2);
    ex2 = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr2->addExercise(ex2);
    ex2 = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr2->addExercise(ex2);
    ex2 = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr2->addExercise(ex2);
    aux->push_back(tr2);

    Date d4 = Date(21,07,2021);
    Time t4 = Time(17);
    Training* tr4 = new Cycling("C",DateTime(d4,t4) ,7.59,TimeSpan(0,15));
    aux->push_back(tr4);
    trainingValues val = showRemoveDialog();
    std::cout<<val.pos<<" "<<val.exName.size()<<std::endl;
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
    return trainingDialog::getValues(this, &ok,add);
}

trainingValues chartViewer::showRemoveDialog()
{
    bool ok, found = false;
    QString start = selectTrainingDialog::getDate(this,&ok,trainings);
    unsigned int n = 0;
    findTraining(n,found,start);
    auto training = trainings->begin();
    std::advance(training,n);
    trainingValues values = trainingDialog::getValues(this,&ok,eliminate,*training);
    values.pos = n;
    return values;
}

trainingValues chartViewer::showSetDialog()
{
    bool ok, found = false;
    QString start = selectTrainingDialog::getDate(this,&ok,trainings);
    unsigned int n = 0;
    findTraining(n,found,start);
    std::cout<<n<<std::endl;
    auto training = trainings->begin();
    std::advance(training,n);

    trainingValues values = trainingDialog::getValues(this,&ok,set,*training);
    values.pos = n;
    return values;
//fare dialog separati
}

void chartViewer::setData(const std::list<const Training *> *data)
{
    trainings = data;
}

void chartViewer::showData()
{
    dataW->setData(trainings);
    dataW->showData();
    //chartW->showData(trainings);
}
