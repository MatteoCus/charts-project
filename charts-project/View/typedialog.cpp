#include "typedialog.h"

typeDialog::typeDialog(QWidget* parent): QDialog(parent)
{
    QVBoxLayout *mainL = new QVBoxLayout;
    QHBoxLayout *typeLayout = new QHBoxLayout;
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QFont font;
    font.setBold(true);

    setFixedSize(250,90);

    typeBox = new QComboBox(this);
    typeBox->setFixedSize(100,25);

    typeBox->addItem(QString("Corsa"));
    typeBox->addItem(QString("Camminata"));
    typeBox->addItem(QString("Ciclismo"));
    typeBox->addItem(QString("Tennis"));
    typeBox->addItem(QString("Rugby"));

    QLabel* type = new QLabel(QString("Tipo allenamento"), this);
    type->setFont(font);
    typeLayout->addWidget(type);
    typeLayout->addWidget(typeBox);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
                                                       | QDialogButtonBox::Cancel,this);

    buttonsLayout->addWidget(buttonBox);
    mainL->addLayout(typeLayout);
    mainL->addLayout(buttonsLayout);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &typeDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &typeDialog::reject);


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
