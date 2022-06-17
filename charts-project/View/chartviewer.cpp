#include "chartviewer.h"
#include "../Controller/controller.h"
#include <iostream>
using namespace std;

void chartViewer::addMenu()
{
    menuBar = new QMenuBar(this);

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

    connect(file->actions().at(0),SIGNAL(triggered()),this,SIGNAL(open()));
    connect(file->actions().at(1),SIGNAL(triggered()),this,SIGNAL(newPlan()));
    connect(file->actions().at(2),SIGNAL(triggered()),this,SIGNAL(save()));
    connect(file->actions().at(3),SIGNAL(triggered()),this,SIGNAL(saveAs()));
    connect(file->actions().at(4),SIGNAL(triggered()),this,SLOT(close()));

    connect(visualizza->actions().at(0),SIGNAL(triggered()),this,SLOT(showChart()));
    connect(visualizza->actions().at(1),SIGNAL(triggered()),this,SLOT(showExercises()));

    connect(allenamenti->actions().at(0), SIGNAL(triggered()), this, SIGNAL(addTrainings()));
    connect(allenamenti->actions().at(1), SIGNAL(triggered()), this, SIGNAL(setTrainings()));
    connect(allenamenti->actions().at(2), SIGNAL(triggered()), this, SIGNAL(removeTrainings()));

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

void chartViewer::closeEvent(QCloseEvent *event)
{
    if(QMessageBox::question(this,"Chiusura", "Sei sicuro di voler uscire?", QMessageBox::Close | QMessageBox::Yes) == QMessageBox::Yes)
    {
        emit closeAll();
        event->accept();
    }
    else
        event->ignore();
}

void chartViewer::showExercises()
{
    bool ok;
    try{
        QString start = selectTrainingDialog::getDate(this,&ok,trainings,"Repetition");
        if (start != "")
        {
            unsigned int n = 0;
            findTraining(n,QDateTime::fromString(start, "dd/MM/yyyy hh:mm:ss"));
            auto training = trainings->begin();
            std::advance(training,n);
            if (dynamic_cast<Repetition*>(*training))
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
    QDialog *dialog = new QDialog(this);

    aux->setStyleSheet("QWidget{background-color: #404244}");
    dialog->setStyleSheet("QDialog{background-color: #404244}");


    Qt::WindowFlags flags = Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint| Qt::WindowCloseButtonHint;
    dialog->setWindowFlags(flags);

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(aux);
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    dialog->resize(800,450);
    dialog->show();
}

void chartViewer::screenChanged()
{
    tableW->screenChanged();
}

void chartViewer::setStyle()
{
    setStyleSheet("QWidget{background-color : #323235} "
                  "QMessageBox {background-color : #404244} "
                  "QMessageBox QPushButton {background-color: #404244; color: white ; selection-background-color: green ; "
                  "selection-color : white}"
                  "QMessageBox QLabel{color: white; background-color : #404244}"
                  "QComboBox {background-color : #404244; color: white ; selection-background-color: green; "
                  "selection-color : white} "
                  "QComboBox::drop-down"
                  "{"
                  "background-color : green;"
                  "border : 1px solid;"
                  "border-bottom: 0px;"
                  "border-color : #77c213 #335407 #335407 #77c213 ;} "
                  "QComboBox::drop-down:pressed{"
                  "border : 1px solid;"
                  "border-color : #77c213 #335407 #335407 #77c213} "
                  "QComboBox::down-arrow{image : url(:/images/down-arrow.png); width: 10px;"
                  "height: 10px} "
                  "QComboBox QAbstractItemView {background-color : #404244 ; color : green; selection-background-color:green} "
                  "QCheckBox { color : white} "
                  "QCheckBox::indicator {background-color: green ; border : 1px solid green}"
                  "QCheckBox::indicator:unchecked:pressed {"
                  "background-color : #269226;"
                  "} "
                  "QCheckBox::indicator:checked {"
                  "image: url(:/images/tick.png);"
                  " width : 12 px; height : 12 px"
                  "} "
                  "QCheckBox::indicator:checked:pressed {"
                  "image: url(:/images/tick_pressed.png);"
                  "} "
                  "QPushButton {background-color : green ; color: white ; selection-background-color: green; selection-color : white}  "
                  "QHeaderView::section { color : white ; background-color: green}  "
                  "QTableWidget::item {color : white ;  gridline-color: green ; background-color : #404244; selection-background-color: green ;"
                  "selection-color : white}"
                  "QLabel {color : white ; background-color : #404244; selection-background-color: green ;"
                  "selection-color : white} "
                  "QTimeEdit {background-color: #56585a; color: white ; selection-background-color: green ;"
                  "selection-color : white} "
                  "QLineEdit {background-color: #56585a; color: white ; selection-background-color: green ;"
                  "selection-color : white} "
                  "QDateTimeEdit {background-color: #56585a;   color: white ; selection-background-color: green ;"
                  "selection-color : white} "
                  "QDialog {background-color : #404244;} "
                  "QDoubleSpinBox {background-color: #56585a; color: white ; selection-background-color: green ;"
                  "selection-color : white} "
                  "QSpinBox {background-color: #56585a; color: white ; selection-background-color: green ;"
                  "selection-color : white} "
                  "QMenuBar {background-color : #404244 ; color: white; }"
                  "QMenuBar::item:selected {background-color : green;}"
                  "QMenu {background-color : #404244 ; color: white; }"
                  "QMenu::item:selected {background-color : green;} "
                  "QMessageBox QPushButton {background-color : green ; color: white ; selection-background-color: green; selection-color : white} "
                  "QCalendarWidget QToolButton { "
                      "color: white; "
                  "} "
                  "QCalendarWidget QMenu { "
                      "color: white; "
                     " background-color: #404244 "
                  "} "
                  "QCalendarWidget QSpinBox { "
                      "color: white; "
                      "selection-background-color: green; "
                      "selection-color: white; "
                      " background-color: #404244 "
                 " } "
                  "QCalendarWidget QSpinBox::up-button { subcontrol-origin: border;  subcontrol-position: top right;  } "
                  "QCalendarWidget QSpinBox::down-button {subcontrol-origin: border; subcontrol-position: bottom right; } "
                  "QCalendarWidget QWidget { alternate-background-color: #3b3c3d; } "

                  "QCalendarWidget QAbstractItemView:enabled  "
                  "{ "
                      "color: white; "
                      "background-color: #56585a;  "
                      "selection-background-color: #323235; "
                      "selection-color: rgb(0, 255, 0); "
                  "} "

                  "QCalendarWidget QAbstractItemView:disabled { color: orange; }");
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
    addMenu();
    setLayout(mainLayout);
    setStyle();

    winId();

    connect(tableW, SIGNAL(showExercises()), this, SLOT(showExercises()));
    connect(tableW,SIGNAL(add()), this, SIGNAL(addTrainings()));
    connect(tableW,SIGNAL(remove()), this, SIGNAL(removeTrainings()));
    connect(tableW,SIGNAL(set()), this, SIGNAL(setTrainings()));
    connect(window()->windowHandle(), SIGNAL(screenChanged(QScreen*)), this, SLOT(screenChanged()));
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
    connect(this, SIGNAL(closeAll()), controller, SLOT(closePlan()));
}

void chartViewer::showWarning(const QString &message)
{
    QMessageBox::warning(this, "Errore", "<FONT COLOR='#ffffff'>"+message+"</FONT>",QMessageBox::Ok);
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
        visualizza->actions().at(1)->setVisible(true);
    else
        visualizza->actions().at(1)->setVisible(false);

    if(!repetition || !endurance)
        tableW->setSplitState(false);


    tableW->hide();
    chartW->hide();

    tableW->showData();
    chartW->showData();

    tableW->show();
    chartW->show();

}
