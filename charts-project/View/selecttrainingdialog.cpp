#include "selecttrainingdialog.h"
#include <iostream>

/*void selectTrainingDialog::updateName(const QString &text)
{
    name->setText(text);
}*/

selectTrainingDialog::selectTrainingDialog(QWidget* parent, const std::vector<Training*>* trainings): QDialog(parent)
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

    std::vector<Training*> tr = *trainings;
    for (auto it = tr.begin(); it != tr.end(); ++it)
    {
        dateBox->addItem(QString::fromStdString((*it)->getStart().toString()));
    }

    name = new QLineEdit(QString::fromStdString((tr[0])->getName()),this);
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


    connect(dateBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){ name->setText(QString::fromStdString((tr[index])->getName())); });



    setLayout(mainL);
}

QString selectTrainingDialog::getDate(QWidget *parent, bool *ok, const std::vector<Training *> *trainings)
{
    selectTrainingDialog *dialog = new selectTrainingDialog(parent, trainings);
    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret)
        return (dialog->dateBox->currentText());
    else
        throw std::runtime_error("Errore nella scelta dell'allenamento");
}
