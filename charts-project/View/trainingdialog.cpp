#include "trainingdialog.h"
#include <iostream>

void trainingDialog::setLabelStyleSheet(QLabel* name)
{
    name->setStyleSheet("QLabel {background-color: #404244; color: white}");
}

void trainingDialog::addToLayout(QBoxLayout* layout, QWidget* w1, QWidget* w2)
{
    layout->addWidget(w1);
    layout->addWidget(w2);
}

void trainingDialog::setupCommon(QBoxLayout* mainL, action act, const Training* training)
{
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *startLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    QLabel* nameLabel = new QLabel(QString("Nome"), this);

    if (act == add)
    {
        name = new QLineEdit(QString("Nome Allenamento"), this);
        start = new QDateTimeEdit(QDateTime::currentDateTime());
    }
    else
    {
        if (!training)
            throw std::runtime_error("Allenamento non valido!");
        Date date = training->getStart().getDate();
        Time time = training->getStart().getTime();
        QString trainingName = QString::fromStdString(training->getName());
        QDateTime* qdatetime = new QDateTime(QDate(date.getYear(),date.getMonth(), date.getDay()), QTime(time.getHours(),time.getMinutes(),time.getSeconds()));

        name = new QLineEdit(trainingName, this);
        start = new QDateTimeEdit(*qdatetime,this);

        if( act == eliminate || act == nothing)
        {   name->setReadOnly(true);
            start->setReadOnly(true);
        }
    }
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

int trainingDialog::showExNumberDialog()
{
    bool ok = false;
    QInputDialog* dial = new QInputDialog(this);
    this -> setStyleSheet("QInputDialog{background-color : #404244}"
                          "QInputDialog QWidget{background-color: #404244; color: white ; selection-background-color: #c26110 ;"
                          "selection-color : white}"
                          "QInputDialog  QLabel{background-color : #404244; color: white}"
                          "QInputDialog QLineEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                          "selection-color : white}");
    int remove = dial->getInt(this,tr("Esercizi da inserire"),"Quantità: ",1,1,15,1,&ok);
    if(!ok) throw std::runtime_error("Nessun numero scelto, inserimento annullato!");
    return remove;
}

void trainingDialog::addButtons()
{
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Orientation::Horizontal,this);

    QPushButton* first = new QPushButton(QString("Ok"), buttonBox);
    first->setStyleSheet("QPushButton {color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    first->setDefault(true);

    QPushButton* second = new QPushButton(QString("Cancel"), buttonBox);
    second->setStyleSheet("QPushButton {color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    second->setAutoDefault(false);

    buttonBox->addButton(first,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(second,QDialogButtonBox::RejectRole);

    buttonBox->setStyleSheet("QDialogButtonBox {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                             "selection-color : white} ");

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(buttonsLayout);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                      this, &trainingDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
        this, &trainingDialog::reject);
    Q_ASSERT(conn);

    setLayout(mainL);
}

trainingDialog::trainingDialog(QWidget *parent) : QDialog(parent)
{
    mainL = new QVBoxLayout;
    this->setStyleSheet("QWidget{background-color : #404244; color : white}");
}
