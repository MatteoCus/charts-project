#include "selecttrainingdialog.h"

selectTrainingDialog::selectTrainingDialog(QWidget* parent, const std::vector<Training*>* trainings): QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *dateLayout = new QHBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;

    setStyleSheet("QDialog{background-color: #404244}");
    setFixedSize(250,90);

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

    std::vector<Training*> tr = *trainings;
    for (auto it = tr.begin(); it != tr.end(); ++it)
    {
        dateBox->addItem(QString::fromStdString((*it)->getStart().toString()));
    }

    QLabel* lab = new QLabel(QString("Giorno inizio allenamento"), this);
    lab->setStyleSheet("QWidget {background-color: #404244; color: white}");
    dateLayout->addWidget(lab);
    dateLayout->addWidget(dateBox);

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
    mainL->addLayout(buttonsLayout);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                      this, &selectTrainingDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
        this, &selectTrainingDialog::reject);
    Q_ASSERT(conn);

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
        throw std::runtime_error("Errore nella scelta del tipo di allenamento");
}
