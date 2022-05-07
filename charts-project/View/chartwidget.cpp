#include "chartwidget.h"

void chartWidget::addDefaultChart(QVBoxLayout * mainLayout)
{
    line = new lineChart(this);



    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setFixedSize(600,400);

    mainLayout->addWidget(chartView);
    mainLayout->setContentsMargins(0,0,0,0);
}

void chartWidget::addControls(QVBoxLayout * mainLayout)
{
    QHBoxLayout * controlsLayout = new QHBoxLayout();
    chartBox = new QComboBox(this);
    chartBox->addItem("Line Chart");
    chartBox->addItem("Bar Chart");
    chartBox->addItem("Pie Chart");
    chartBox->setFixedSize(100,25);
    chartBox->setStyleSheet("QComboBox {background-color : #404244 ; color: white ; selection-background-color: #c26110;"
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
                            "QComboBox QAbstractItemView {selection-background-color:#c26110;}");   //IMPORTANTE

    dataBox = new QComboBox(this);
    dataBox->addItem("Durata");
    dataBox->addItem("Calorie");
    dataBox->addItem("Intensità");
    dataBox->addItem("Distanza");
    dataBox->setFixedSize(100,25);
    dataBox->setStyleSheet("QComboBox {background-color : #404244 ; color: white ; selection-background-color: #c26110 ;"
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
                           "QComboBox QAbstractItemView {selection-background-color:#c26110;}");   //IMPORTANTE

    controlsLayout->addWidget(chartBox);
    controlsLayout->addWidget(dataBox);

    connect(chartBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text){showData(text.toStdString(), dataBox->currentText().toStdString());});

    connect(dataBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text){showData(chartBox->currentText().toStdString(), text.toStdString());});

    controlsLayout->setContentsMargins(0,20,0,0);
    controlsLayout->setSpacing(50);
    controlsLayout->setAlignment(Qt::AlignHCenter);
    mainLayout->addLayout(controlsLayout);

    //rimuovere Intensità e Distanza se non ci sono repetition / endurance
}

void chartWidget::hideDataEntry(int x)
{
    QListView* view = qobject_cast<QListView *>(dataBox->view());
    Q_ASSERT(view != nullptr);
    view->setRowHidden(x, true);

    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(dataBox->model());
    Q_ASSERT(model != nullptr);
    QStandardItem* item = model->item(x);
    item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
}

void chartWidget::unhideDataEntry(int x)
{
    QListView* view = qobject_cast<QListView *>(dataBox->view());
    Q_ASSERT(view != nullptr);
    view->setRowHidden(x, false);

    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(dataBox->model());
    Q_ASSERT(model != nullptr);
    QStandardItem* item = model->item(x);
    item->setFlags(item->flags() | Qt::ItemIsEnabled);
}



chartWidget::chartWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout();

    addDefaultChart(mainLayout);

    addControls(mainLayout);

    setStyleSheet("QWidget{background-color : #2e2f30}");
    mainLayout->setAlignment(Qt::AlignTop);
    setLayout(mainLayout);
}

void chartWidget::checkDataBoxValues()
{
    bool repetitionFound = false, enduranceFound = false;

    for (auto it = trainings->begin(); it != trainings->end() && !repetitionFound && !enduranceFound; ++it)
    {
        if (dynamic_cast<const Endurance*>(*it))
            enduranceFound = true;
        else
            repetitionFound = true;
    }

    if(repetitionFound)
        unhideDataEntry(2);
    else
        hideDataEntry(2);
    if (enduranceFound)
        unhideDataEntry(3);
    else
        hideDataEntry(3);
}

void chartWidget::showData(const std::string& chart, const std::string& data)
{
    //in base al valore delle combobox, campioniamo dei dati da spedire poi a mainChart (tipo chart*) tramite 'update(dati)'
    //e poi si invoca 'show()' sempre su mainChart, dopo averlo opportunamente cambiato se necessario
    //aggiungi il QChart alla QChartView quando vai a cambiare
    checkDataBoxValues();

    std::vector<int> values;
    std::vector<DateTime*> start;

    if (chart == "Line Chart" || chart == "Bar Chart")
    {
        unsigned int i = 0;
        if (data == "Durata")
        {
            for (auto it = trainings->begin(); it != trainings->end(); ++it)
            {
                values[i] = (*it)->getDuration().getTotalSeconds();
                start[i] = new DateTime((*it)->getStart());
                ++i;
            }
        }
        else if (data == "Calorie")
        {
            for (auto it = trainings->begin(); it != trainings->end(); ++it)
            {
                start[i] = new DateTime((*it)->getStart());
                values[i] = (*it)->CaloriesBurned();
                ++i;
            }
        }
        else if (data == "Intensità")
        {
            for (auto it = trainings->begin(); it != trainings->end(); ++it)
            {
                if (auto rep = dynamic_cast<const Repetition*>(*it))
                {
                    start[i] = new DateTime(rep->getStart());
                    values[i] = rep->Intensity();
                    ++i;
                }
            }
        }
        else if (data == "Distanza")
        {
            for (auto it = trainings->begin(); it != trainings->end(); ++it)
            {
                if (auto end = dynamic_cast<const Endurance*>(*it))
                {
                    start[i] = new DateTime(end->getStart());
                    values[i] = end->getDistance();
                    ++i;
                };
            }
        }

    }
    else
    {
        //manca da estrarre i dati in base al tipo di dato ed al tipo di allenamento
    }
}

void chartWidget::setData(const std::list<const Training *> *data)
{
    trainings = data;
}
