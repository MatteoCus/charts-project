#include "selecttrainingdialog.h"
#include <iostream>

/*void selectTrainingDialog::updateName(const QString &text)
{
    name->setText(text);
}*/

selectTrainingDialog::selectTrainingDialog(QWidget* parent, const std::vector<const Training*>* trainings, std::string type): QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *dateLayout = new QHBoxLayout;
    QHBoxLayout *nameLayout = new QHBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;

    nameLayout->setContentsMargins(0,0,0,10);

    setStyleSheet("QDialog{background-color: #404244}");
    setFixedSize(250,120);

    dateBox = new QComboBox(this);
    dateBox->setFixedSize(100,25);
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
                           "QComboBox QListView {background-color : #404244 ; color : white;}"
                           "QComboBox QAbstractItemView {selection-background-color:#c26110;}");
    dateBox->setFixedWidth(150);

    bool found = false;
    auto it = trainings->begin();
    std::string trainingName = (*it)->getName();
    std::vector<const Training*> aux;
    for (auto it = trainings->begin(); it != trainings->end(); ++it)
        if(type == "All" || (type == "Repetition" && dynamic_cast<const Repetition*>(*it))
                         || (type == "Endurance" && dynamic_cast<const Endurance*>(*it)))
        {
            if (!found)
            {
                found = true;
                trainingName = (*it)->getName();
            }
            dateBox->addItem(QString::fromStdString((*it)->getStart().toString()));
            aux.push_back(*it);
        }

    name = new QLineEdit(QString::fromStdString(trainingName),this);
    name->setReadOnly(true);



    QLabel* lab = new QLabel(QString("Inizio"), this);
    lab->setStyleSheet("QWidget {background-color: #404244; color: white}");
    dateLayout->addWidget(lab);
    dateLayout->addWidget(dateBox);

    QLabel* nameLab = new QLabel(QString("Nome"), this);
    nameLab->setStyleSheet("QWidget {background-color: #404244; color: white}");
    name->setStyleSheet("QLineEdit {background-color: #56585a; color: white ; selection-background-color: #c26110 ;"
                        "selection-color : white} ");
    name->setFixedWidth(150);
    nameLayout->addWidget(nameLab);
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
    mainL->addLayout(dateLayout);
    mainL->addLayout(nameLayout);
    mainL->addLayout(buttonsLayout);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                      this, &selectTrainingDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
        this, &selectTrainingDialog::reject);
    Q_ASSERT(conn);

    if (type == "All")
        connect(dateBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){ name->setText(QString::fromStdString(((*trainings)[index])->getName())); });
    else
        connect(dateBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){ name->setText(QString::fromStdString((aux[index])->getName())); });


    setLayout(mainL);
}

QString selectTrainingDialog::getDate(QWidget *parent, bool *ok, const std::vector<const Training *> *trainings, std::string type)
{
    selectTrainingDialog *dialog = new selectTrainingDialog(parent, trainings, type);
    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret)
        return (dialog->dateBox->currentText());
    else if (type == "Repetition")
        return "";
    else
        throw std::runtime_error("Errore nella scelta dell'allenamento");
}
