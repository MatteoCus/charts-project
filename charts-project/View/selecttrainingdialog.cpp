#include "selecttrainingdialog.h"
#include <iostream>
using namespace std;

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

    setFixedSize(250,120);

    dateBox = new QComboBox(this);
    dateBox->setFixedSize(100,25);
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
    startLabel->setFont(font);
    dateLayout->addWidget(startLabel);
    dateLayout->addWidget(dateBox);

    QLabel* nameLabel = new QLabel(QString("Nome"), this);
    nameLabel->setFont(font);
    name->setStyleSheet("QWidget {background-color: #56585a; color: white ; selection-background-color: green ;"
                        "selection-color : white} ");
    name->setFixedWidth(150);
    nameLayout->addWidget(nameLabel);
    nameLayout->addWidget(name);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                       | QDialogButtonBox::Close,this);

    buttonsLayout->addWidget(buttonBox);
    dataLayout->addLayout(dateLayout);
    dataLayout->addLayout(nameLayout);
    mainL->addLayout(dataLayout);
    mainL->addLayout(buttonsLayout);

    connect(buttonBox, &QDialogButtonBox::accepted,
                      this, &selectTrainingDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected,
        this, &selectTrainingDialog::reject);

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
        else
            return "";
    }
    else
        throw std::runtime_error("Non vi sono allenamenti fra cui scegliere");
}
