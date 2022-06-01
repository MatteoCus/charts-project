#include "typedialog.h"

void typeDialog::setComboBoxStyleSheet()
{
    typeBox->setStyleSheet("QComboBox {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
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

typeDialog::typeDialog(QWidget* parent): QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *typeLayout = new QHBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    setStyleSheet("QDialog{background-color: #404244}");
    setFixedSize(250,90);

    typeBox = new QComboBox(this);
    typeBox->setFixedSize(100,25);
    setComboBoxStyleSheet();

    typeBox->addItem(QString("Corsa"));
    typeBox->addItem(QString("Camminata"));
    typeBox->addItem(QString("Ciclismo"));
    typeBox->addItem(QString("Tennis"));
    typeBox->addItem(QString("Rugby"));

    QLabel* type = new QLabel(QString("Tipo allenamento"), this);
    type->setFont(font);
    type->setStyleSheet("QWidget {background-color: #404244; color: white}");
    typeLayout->addWidget(type);
    typeLayout->addWidget(typeBox);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Orientation::Horizontal,this);

    QPushButton* first = new QPushButton(QString("Ok"), buttonBox);
    first->setStyleSheet("QPushButton {background-color: #404244; color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    first->setDefault(true);

    QPushButton* second = new QPushButton(QString("Cancel"), buttonBox);
    second->setStyleSheet("QPushButton {background-color: #404244; color: white ; selection-background-color: #c26110 ;"
                         "selection-color : white} ");
    second->setAutoDefault(false);

    buttonBox->addButton(first,QDialogButtonBox::AcceptRole);
    buttonBox->addButton(second,QDialogButtonBox::RejectRole);

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(typeLayout);
    mainL->addLayout(buttonsLayout);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                      this, &typeDialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
        this, &typeDialog::reject);
    Q_ASSERT(conn);

    setLayout(mainL);
}

QString typeDialog::getType(QWidget *parent, bool *ok)
{
    typeDialog *dialog = new typeDialog(parent);
    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret)
        return (dialog->typeBox->currentText());
    else
        throw std::runtime_error("Nessun tipo scelto, operazione annullata!");
}
