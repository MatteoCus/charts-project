#include "chartviewer.h"
#include "../Controller/controller.h"

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
    visualizza->addAction(new QAction("Grafico", visualizza));
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

    tableW = new tableWidget(this);
    chartW = new chartWidget(this);
    mainLayout->setSpacing(40);
    mainLayout->addWidget(tableW);
    mainLayout->addWidget(chartW);
    mainLayout->setContentsMargins(10,90,10,20);
    addMenu(mainLayout);
    setLayout(mainLayout);
    setStyleSheet("QWidget{background-color : #2e2f30}");

    /*auto aux = new std::list<Training*>;
    Date d = Date(21,04,2021);
    Date d2 = Date(21,05,2021);
    Time ti = Time(17);
    Training* t = new Run("C",DateTime(d,ti) ,17.59,TimeSpan(1,25));
    aux->push_back(t);
    trainings = aux;

    Tennis* tr = new Tennis("Tennis del martedì",DateTime(d2,ti));
    Exercise* ex = new Exercise("Primo", Time(0,15,0),Time(0,5,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,16,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,16,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,16,0));
    tr->addExercise(ex);
    ex = new Exercise("Secondo", Time(0,15,1),Time(0,6,0));
    tr->addExercise(ex);
    aux->push_back(tr);

    Date d3 = Date(21,06,2021);
    Time tim = Time(17);
    Rugby* tr2 = new Rugby("Cristo",DateTime(d3,tim));
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

    Date d4 = Date(29,07,2021);
    Time t4 = Time(17);
    Training* tr4 = new Cycling("C",DateTime(d4,t4) ,7.59,TimeSpan(0,15));
    aux->push_back(tr4);
    trainingValues val = showSetDialog();
    std::cout<<val.name.toStdString()<<" "<<val.exName.size()<<std::endl;
    setData(aux);
    showData();*/
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

QString chartViewer::showPathDialog()
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
    QString type = typeDialog::getType(this,&ok);
    if (type == "Camminata" || type == "Corsa" || type == "Ciclismo")
    {
        trainingValues values = enduranceDialog::getValues(this,&ok,add);
        values.type = type;
        return values;
    }
    else
    {
        trainingValues values = repetitionDialog::getValues(this,&ok,add);
        values.type = type;
        return values;
    }
}

trainingValues chartViewer::showRemoveDialog()
{
    bool ok, found = false;
    QString start = selectTrainingDialog::getDate(this,&ok,trainings);
    unsigned int n = 0;
    findTraining(n,found,start);
    auto training = trainings->begin();
    std::advance(training,n);
    if (auto aux = dynamic_cast<Endurance*>(*training))
    {
        trainingValues values = enduranceDialog::getValues(this,&ok,eliminate,aux);
        values.pos = n;
        return values;
    }
    else if (auto aux = dynamic_cast<Repetition*>(*training))
    {
        trainingValues values = repetitionDialog::getValues(this,&ok,eliminate,aux);
        values.pos = n;
        return values;
    }
    else
        throw std::runtime_error("Allenamento non corretto selezionato!");
}

trainingValues chartViewer::showSetDialog()
{
    bool ok, found = false;
    QString start = selectTrainingDialog::getDate(this,&ok,trainings);
    unsigned int n = 0;
    findTraining(n,found,start);
    auto training = trainings->begin();
    std::advance(training,n);

    if (auto aux = dynamic_cast<Endurance*>(*training))
    {
        trainingValues values = enduranceDialog::getValues(this,&ok,set,aux);
        values.pos = n;
        return values;
    }
    else if (auto aux = dynamic_cast<Repetition*>(*training))
    {
        trainingValues values = repetitionDialog::getValues(this,&ok,set,aux);
        values.pos = n;
        return values;
    }
    else
        throw std::runtime_error("Allenamento non corretto selezionato!");
}

void chartViewer::setData(const std::list<Training *> *data)
{
    trainings = data;
    tableW->setData(trainings);
    chartW->setData(trainings);
}

void chartViewer::showData()
{
    tableW->showData();
    chartW->showData();
}
