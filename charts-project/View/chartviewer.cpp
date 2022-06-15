#include "chartviewer.h"
#include "../Controller/controller.h"
#include <iostream>
using namespace std;

void chartViewer::addMenu(QHBoxLayout* mainLayout)
{
    menuBar = new QMenuBar(this);

    menuBar->setStyleSheet("QMenuBar {background-color : #404244 ; color: white; }"
                           "QMenuBar::item:selected {background-color : green;}"
                           "QMenu {background-color : #404244 ; color: white; }"
                           "QMenu::item:selected {background-color : green;}");

    file = new QMenu("File", menuBar);
    visualizza = new QMenu("Visualizza", menuBar);
    allenamenti= new QMenu("Allenamenti", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(visualizza);
    menuBar->addMenu(allenamenti);

    //Menù "File"
    file->addAction(new QAction("Apri", file));
    file->addAction(new QAction("Nuovo", file));
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Salva col nome", file));
    file->addAction(new QAction("Esci", file));

    //Menù "visualizza"
    visualizza->addAction(new QAction("Grafico", visualizza));
    visualizza->addAction(new QAction("Esercizi", visualizza));

    //Menù "allenamenti"
    allenamenti->addAction(new QAction("Aggiungi", allenamenti));
    allenamenti->addAction(new QAction("Modifica", allenamenti));
    allenamenti->addAction(new QAction("Rimuovi", allenamenti));

    connect(file->actions()[0],SIGNAL(triggered()),this,SIGNAL(open()));
    connect(file->actions()[1],SIGNAL(triggered()),this,SIGNAL(newPlan()));
    connect(file->actions()[2],SIGNAL(triggered()),this,SIGNAL(save()));
    connect(file->actions()[3],SIGNAL(triggered()),this,SIGNAL(saveAs()));
    connect(file->actions()[4],SIGNAL(triggered()),this,SLOT(close()));

    connect(visualizza->actions()[0],SIGNAL(triggered()),this,SLOT(showChart()));
    connect(visualizza->actions()[1],SIGNAL(triggered()),this,SLOT(showExercises()));

    connect(allenamenti->actions()[0], SIGNAL(triggered()), this, SIGNAL(addTrainings()));
    connect(allenamenti->actions()[1], SIGNAL(triggered()), this, SIGNAL(setTrainings()));
    connect(allenamenti->actions()[2], SIGNAL(triggered()), this, SIGNAL(removeTrainings()));

    mainLayout->setMenuBar(menuBar);
}

void chartViewer::findTraining(unsigned int &n, const QDateTime& start)
{
    int i=0;
    bool found = false;

    for (auto it = trainings->begin(); it != trainings->end() && !found ; ++it)
    {
        i++;

        DateTime datetime = (*it)->getStart();

        Date date = datetime.getDate();
        Time time = datetime.getTime();

        QDate qdate = start.date();
        QTime qtime = start.time();


        if (static_cast<int>(date.getDay()) == qdate.day() && static_cast<int>(date.getMonth()) == qdate.month()
                && static_cast<int>(date.getYear()) == qdate.year()
                && static_cast<int>(time.getHours()) == qtime.hour() && static_cast<int>(time.getMinutes()) == qtime.minute()
                && static_cast<int>(time.getSeconds()) == qtime.second())
            found = true;
    }
    n = i-1;
}

void chartViewer::showExercises()
{
        bool ok, found = false;
        try{
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
                if (found && dynamic_cast<Repetition*>(*training))
                {
                    Repetition* aux = static_cast<Repetition*>(*training);
                    repetitionDialog* rep = new repetitionDialog(this,nothing,aux);
                    rep->exec();
                }
                else
                    throw std::runtime_error("Tipo di allenamento selezionato non valido!");
            }
        }
        catch(std::runtime_error e)
        {
            showWarning(e.what());
        }
}

void chartViewer::showChart()
{
    chartWidget* aux = chartW->clone();
    dialog = new QDialog( this);

    Qt::WindowFlags flags = Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint| Qt::WindowCloseButtonHint;
    dialog->setWindowFlags(flags);

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(aux);
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    dialog->resize(800,450);
    dialog->show();
}

chartViewer::chartViewer(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QHBoxLayout;

    tableW = new tableWidget(this);
    chartW = new chartWidget(this);

    mainLayout->setSpacing(20);
    mainLayout->addWidget(tableW);
    mainLayout->addWidget(chartW);
    mainLayout->setContentsMargins(10,50,10,20);
    addMenu(mainLayout);
    setLayout(mainLayout);
    setStyleSheet("QWidget{background-color : #2e2f30} "
                  "QMessageBox {background-color : #404244}"
                  "QMessageBox QPushButton {background-color: #404244; color: white ; selection-background-color: green ;"
                  "selection-color : white}"
                  "QMessageBox QLabel{color: white; background-color : #404244}");
    showMaximized();


    connect(tableW, SIGNAL(showExercises()), this, SLOT(showExercises()));
    connect(tableW,SIGNAL(add()), this, SIGNAL(addTrainings()));
    connect(tableW,SIGNAL(remove()), this, SIGNAL(removeTrainings()));
    connect(tableW,SIGNAL(set()), this, SIGNAL(setTrainings()));
}

void chartViewer::setController(Controller *c)
{
    controller = c;
    connect(this, SIGNAL(addTrainings()), controller, SLOT(add()));
    connect(this, SIGNAL(setTrainings()), controller, SLOT(set()));
    connect(this, SIGNAL(removeTrainings()), controller, SLOT(remove()));
    connect(this, SIGNAL(newPlan()), controller, SLOT(newPlan()));
    connect(this, SIGNAL(open()), controller, SLOT(open()));
    connect(this, SIGNAL(save()), controller, SLOT(save()));
    connect(this, SIGNAL(saveAs()), controller, SLOT(saveAs()));
}

void chartViewer::showWarning(const QString &message)
{
    QMessageBox::warning(this, "Warning", "<FONT COLOR='#ffffff'>"+message+"</FONT>",QMessageBox::Ok);
}

dialogValues chartViewer::showAddDialog()
{
    bool ok = false;
    QString type = typeDialog::getType(this,&ok);
    if(ok)
    {
        if (type == "Camminata" || type == "Corsa" || type == "Ciclismo")
        {
            dialogValues values = enduranceDialog::getValues(this,&ok,add);
            values.type = type;
            return values;
        }
        else
        {
            dialogValues values = repetitionDialog::getValues(this,&ok,add);
            values.type = type;
            return values;
        }
    }
    else
        throw std::runtime_error("Nessun tipo scelto, operazione annullata!");
}

dialogValues chartViewer::showRemoveDialog()
{
    bool ok = false;
    QString start = selectTrainingDialog::getDate(this,&ok,trainings);
    if(ok)
    {
        unsigned int n = 0;
        findTraining(n,QDateTime::fromString(start, "dd/MM/yyyy hh:mm:ss"));
        auto training = trainings->begin();
        std::advance(training,n);
        if (auto aux = dynamic_cast<Endurance*>(*training))
        {
            dialogValues values = enduranceDialog::getValues(this,&ok,eliminate,aux);
            values.pos = n;
            return values;
        }
        else if (auto aux = dynamic_cast<Repetition*>(*training))
        {
            dialogValues values = repetitionDialog::getValues(this,&ok,eliminate,aux);
            values.pos = n;
            return values;
        }
        else
            throw std::runtime_error("Allenamento non corretto selezionato!");
    }
    else
        throw std::runtime_error("Nessun allenamento scelto, operazione annullata!");
}

dialogValues chartViewer::showSetDialog()
{
    bool ok = false;
    QString start = selectTrainingDialog::getDate(this,&ok,trainings);

    if(ok)
    {
        unsigned int n = 0;

        findTraining(n,QDateTime::fromString(start, "dd/MM/yyyy hh:mm:ss"));
        auto training = trainings->begin();
        std::advance(training,n);

        if (auto aux = dynamic_cast<Endurance*>(*training))
        {
            dialogValues values = enduranceDialog::getValues(this,&ok,set,aux);
            values.pos = n;
            values.type = "Endurance";
            return values;
        }
        else if (auto aux = dynamic_cast<Repetition*>(*training))
        {
            dialogValues values = repetitionDialog::getValues(this,&ok,set,aux);
            values.pos = n;
            values.type = "Repetition";
            return values;
        }
        else
            throw std::runtime_error("Allenamento non corretto selezionato!");
    }
    else
        throw std::runtime_error("Nessun allenamento scelto, operazione annullata!");
}

void chartViewer::setData(const std::list<Training *> *data)
{
    trainings = data;
    tableW->setData(trainings);
    chartW->setData(trainings);
}

void chartViewer::showData()
{
    bool repetition = false, endurance = false;

    for (auto it = trainings->begin(); it != trainings->end() && (!repetition || !endurance); ++it)
    {
        if (dynamic_cast<Repetition*>(*it))
            repetition = true;
        else
            endurance = true;
    }

    if(repetition)
       visualizza->actions()[1]->setVisible(true);
    else
        visualizza->actions()[1]->setVisible(false);

    if(!repetition || !endurance)
        tableW->setSplitState(false);


    tableW->hide();
    chartW->hide();

    tableW->showData();
    chartW->showData();

    tableW->show();
    chartW->show();

}
