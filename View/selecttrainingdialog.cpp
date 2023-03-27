#include "selecttrainingdialog.h"
#include <iostream>

void selectTrainingDialog::setComboBoxStyleSheet()
{
    dateBox->setStyleSheet("QComboBox {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                           "selection-color : white} "
                           "QComboBox::drop-down{background-color : #c26110 ;}"
                           "QComboBox::drop-down"
                           "{"
                           "border : 2px solid;"
                           "border-color : #df7012 #81410b #81410b #df7012;}"
                           "QComboBox::drop-down:pressed{"
                           "border : 2px solid;"
                           "border-color : #81410b #df7012 #df7012 #81410b;}"
                           "QComboBox::down-arrow{image : url(/home/matteo/Documenti/GitHub/charts-project/charts-project/icons/pngwing.com.png); width: 10px;"
                           "height: 10px;}"
                           "QComboBox QListView {background-color : #56585a ; color : white;}"
                           "QComboBox QAbstractItemView {selection-background-color:#c26110;}");
}

selectTrainingDialog::selectTrainingDialog(QWidget* parent, const std::list<Training*>* trainings, std::string type): QDialog(parent)
{
    if (!trainings)
        throw std::runtime_error("Non ci sono allenamenti adatti!");

    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *dateLayout = new QHBoxLayout;
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QVBoxLayout *dataLayout = new QVBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;

    QFont font;
    font.setBold(true);

    dateLayout->setAlignment(Qt::AlignTop);

    nameLayout->setContentsMargins(0,0,0,10);

    setStyleSheet("QDialog{background-color: #404244}");
    setFixedSize(250,120);

    dateBox = new QComboBox(this);
    dateBox->setFixedSize(100,25);
    setComboBoxStyleSheet();
    dateBox->setFixedWidth(150);

    auto it = trainings->begin();
    std::string trainingName = (*it)->getName();
    std::list<Training*> aux;
    it = trainings->end();
    bool foundFirst = false;

    for (--it; it != --trainings->begin(); --it)
    {
        if(type == "All" || (type == "Repetition" && dynamic_cast<const Repetition*>(*it))
                         || (type == "Endurance" && dynamic_cast<const Endurance*>(*it)))
        {
            if (!foundFirst)
            {
                foundFirst = true;
                trainingName = (*it)->getName();
            }
            dateBox->addItem(QString::fromStdString((*it)->getStart().toString()));
            aux.push_back(*it);
        }

    }
    name = new QLineEdit(QString::fromStdString(trainingName),this);
    name->setAlignment(Qt::AlignCenter);
    name->setReadOnly(true);



    QLabel* startLabel = new QLabel(QString("Inizio"), this);
    startLabel->setStyleSheet("QWidget {background-color: #404244; color: white}");
    startLabel->setFont(font);
    dateLayout->addWidget(startLabel);
    dateLayout->addWidget(dateBox);

    QLabel* nameLabel = new QLabel(QString("Nome"), this);
    nameLabel->setStyleSheet("QWidget {background-color: #404244; color: white}");
    nameLabel->setFont(font);
    name->setStyleSheet("QWidget {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                        "selection-color : white} ");
    name->setFixedWidth(150);
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(name);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Orientation::Horizontal,this);

    QPushButton* first = new QPushButton(QString("Ok"), buttonBox);
    first->setStyleSheet("QPushButton {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    first->setDefault(true);

    QPushButton* second = new QPushButton(QString("Cancel"), buttonBox);
    second->setStyleSheet("QPushButton {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    second->setAutoDefault(false);

    buttonBox->addButton(first,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(second,QDialogButtonBox::RejectRole);

    buttonsLayout->addWidget(buttonBox);
    dataLayout->addLayout(dateLayout);
    dataLayout->addLayout(nameLayout);
    mainL->addLayout(dataLayout);
    mainL->addLayout(buttonsLayout);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                      this, &selectTrainingDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
        this, &selectTrainingDialog::reject);
    Q_ASSERT(conn);

    connect(dateBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){auto training = aux.begin(); std::advance(training, index); name->setText(QString::fromStdString((*training)->getName())); });

    setLayout(mainL);
}

QString selectTrainingDialog::getDate(QWidget *parent, bool *ok, const std::list<Training *> *trainings, std::string type)
{
    if (trainings->size())
    {
        selectTrainingDialog *dialog = new selectTrainingDialog(parent, trainings, type);
        const int ret = dialog->exec();
        if (ok)
            *ok = !!ret;

        if (ret)
            return (dialog->dateBox->currentText());
        else if (type == "Repetition")
            return "";
    }
    else
        throw std::runtime_error("Non vi sono allenamenti fra cui scegliere");
}
