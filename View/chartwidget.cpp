#include "chartwidget.h"

void chartWidget::addDefaultChart()
{
    line = new lineChart(this);
    bar = new barChart(this);
    pie = new pieChart(this);

    visibleChart = pie;
    mainLayout->addWidget(visibleChart->getChartView());
    visibleChart->getChartView()->hide();

    visibleChart = bar;
    mainLayout->addWidget(visibleChart->getChartView());
    visibleChart->getChartView()->hide();

    visibleChart = line;
    mainLayout->addWidget(visibleChart->getChartView());

    mainLayout->setContentsMargins(0,0,0,0);
}

void chartWidget::addControls()
{
    QHBoxLayout * controlsLayout = new QHBoxLayout();
    chartBox = new QComboBox(this);
    chartBox->addItem("Line Chart");
    chartBox->addItem("Bar Chart");
    chartBox->addItem("Pie Chart");
    chartBox->setFixedSize(100,25);

    dataBox = new QComboBox(this);
    dataBox->addItem("Durata");
    dataBox->addItem("Calorie");
    dataBox->addItem("Intensità");
    dataBox->addItem("Distanza");
    dataBox->setFixedSize(100,25);

    controlsLayout->addWidget(chartBox);
    controlsLayout->addWidget(dataBox);

    connect(chartBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text){emit updateChart(*this, text.toStdString(), dataBox->currentText().toStdString());});

    connect(dataBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [=](const QString &text){emit updateChart(*this,chartBox->currentText().toStdString(), text.toStdString());});

    controlsLayout->setContentsMargins(0,20,0,0);
    controlsLayout->setSpacing(50);
    controlsLayout->setAlignment(Qt::AlignHCenter);
    mainLayout->addLayout(controlsLayout);

}

void chartWidget::hideDataBoxEntry(int x)
{
    QListView* view = qobject_cast<QListView *>(dataBox->view());
    Q_ASSERT(view != nullptr);
    view->setRowHidden(x, true);

    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(dataBox->model());
    Q_ASSERT(model != nullptr);
    QStandardItem* item = model->item(x);
    item->setFlags(item->flags() & ~Qt::ItemIsEnabled);
}

void chartWidget::unhideDataBoxEntry(int x)
{
    QListView* view = qobject_cast<QListView *>(dataBox->view());
    Q_ASSERT(view != nullptr);
    view->setRowHidden(x, false);

    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(dataBox->model());
    Q_ASSERT(model != nullptr);
    QStandardItem* item = model->item(x);
    item->setFlags(item->flags() | Qt::ItemIsEnabled);
}



chartWidget::chartWidget(QWidget *parent) : QWidget(parent), mainLayout(new QVBoxLayout())
{
    addDefaultChart();

    addControls();

    setLayout(mainLayout);
}

void chartWidget::checkDataBoxValues(const std::list<Training*>* trainings)
{
    bool repetitionFound = false, enduranceFound = false;
    for (auto it = trainings->begin(); it != trainings->end()-- && (!repetitionFound || !enduranceFound); ++it)
    {
        if (dynamic_cast<const Endurance*>(*it))
            enduranceFound = true;
        else
            repetitionFound = true;
    }

    if(repetitionFound)
        unhideDataBoxEntry(2);
    else
        hideDataBoxEntry(2);
    if (enduranceFound)
        unhideDataBoxEntry(3);
    else
        hideDataBoxEntry(3);
}

void chartWidget::extractValues(const std::list<Training*>* trainings, std::vector<double>& values, std::vector<DateTime*>& start, const std::string& data)
{

    for (auto it = trainings->begin(); it != trainings->end(); ++it)
    {
        DateTime* aux = new DateTime((*it)->getStart());
        start.push_back(aux);
        if (data == "Durata")
            values.push_back((*it)->getDuration().getTotalSeconds());
        else if (data == "Calorie")
            values.push_back((*it)->CaloriesBurned());
        else if (data == "Intensità")
        {
            if (auto rep = dynamic_cast<const Repetition*>(*it))
                values.push_back(rep->Intensity());
            else{
                delete aux;
                start.pop_back();
            }
        }
        else if (data == "Distanza")
        {
            if (auto end = dynamic_cast<const Endurance*>(*it))
                values.push_back(end->getDistance());
            else {
                delete aux;
                start.pop_back();
            }
        }
    }
}

void chartWidget::extractValues(const std::list<Training*>* trainings, std::vector<double>& values, const std::string& data)
{
    int j = 0;

    for(unsigned int i=0; i < 5; i++)
        values.push_back(0);

    for (auto it = trainings->begin(); it != trainings->end(); ++it)
    {
        //values[0] = valori di cycling, [1] = run, [2] = walk, [3] rugby, [4] tennis
        //values[0] : rugby, values[1]: tennis
        //values[0] = valori di cycling, [1] = run, [2] = walk

        if (dynamic_cast<const Cycling*>(*it)) {j = (data != "Intensità"? 0 : -1);}
        else if (dynamic_cast<const Run*>(*it)) { j = (data != "Intensità"? 1 : -1);}

        else if (dynamic_cast<const Walk*>(*it)) { j = (data != "Intensità"? 2 : -1);}

        else if (dynamic_cast<const Rugby*>(*it)) { j = (data == "Intensità"? 0 : data != "Distanza"? 3: -1);}

        else if (dynamic_cast<const Tennis*>(*it)) {j = (data == "Intensità"? 1 : data != "Distanza"? 4: -1);}

        else throw std::runtime_error("Tipo di allenamento sconosciuto");

        //j: se vale -1 vuol dire che un attributo non deve essere incluso in values, altrimenti indica la sua posizione

        if (j >= 0)
        {
            if (data == "Durata")
                values.at(j) += (*it)->getDuration().getTotalSeconds();
            else if (data == "Calorie")
                values.at(j) += (*it)->CaloriesBurned();
            else if (data == "Intensità")
            {
                if (auto rep = dynamic_cast<const Repetition*>(*it))
                    values.at(j) += rep->Intensity();
            }
            else if (data == "Distanza")
            {
                if (auto end = dynamic_cast<const Endurance*>(*it))
                    values.at(j) += end->getDistance();
            }
        }
    }
}

void chartWidget::showData(const std::list<Training*>* trainings, std::string chart, std::string data)
{
    //in base al valore delle combobox, campioniamo dei dati da spedire poi a mainChart (tipo chart*) tramite 'update(dati)'
    //e poi si invoca 'show()' sempre su mainChart, dopo averlo opportunamente cambiato se necessario
    //aggiungi il QChart alla QChartView quando vai a cambiare
    bool durationFlag = false, repetitionFlag = false, enduranceFlag = false;

    visibleChart->getChartView()->setVisible(false);

    checkDataBoxValues(trainings);

    if ( chart == "" && data == "")
    {
        chart = chartBox->currentText().toStdString();
        data = dataBox->currentText().toStdString();
    }
    std::vector<double> values;
    std::vector<DateTime*> start;

    if (chart == "Line Chart" || chart == "Bar Chart")
    {
        extractValues(trainings,values,start,data);
        if (chart == "Line Chart")
            visibleChart = line;
        else
            visibleChart = bar;
    }
    else if (chart == "Pie Chart")
    {
        extractValues(trainings,values,data);
        visibleChart = pie;
    }
    else throw std::runtime_error("Grafico non identificato!");


    if (data == "Durata")
        durationFlag = true;
    else if (data == "Intensità")
        repetitionFlag = true;
    else if (data == "Distanza")
        enduranceFlag = true;

    if (dynamic_cast<axedChart*>(visibleChart) && (chart == "Line Chart" || chart == "Bar Chart"))
    {
        axedChart* c = static_cast<axedChart*>(visibleChart);
        c->addSeries(&values,&start,durationFlag);
        c->setAxes("Inizio allenamento", data);
    }
    else if(dynamic_cast<nonAxedChart*>(visibleChart) && chart == "Pie Chart")
    {
        nonAxedChart* c = static_cast<nonAxedChart*>(visibleChart);
        c->addSeries(&values,repetitionFlag,enduranceFlag);
    }
    else
        throw std::runtime_error("Errore nella visualizzazione del grafico!");

    visibleChart->getChartView()->setVisible(true);

    for (auto values : start)
        delete values;
}

chart *chartWidget::getVisibleChart() const
{
    return visibleChart;
}

void chartWidget::setChartsSize(int w, int h)
{
    line->getChartView()->setFixedSize(w,h);
    bar->getChartView()->setFixedSize(w,h);
    pie->getChartView()->setFixedSize(w,h);
}

chartWidget *chartWidget::clone(const std::list<Training*>* trainings) const
{
    chartWidget* aux = new chartWidget();
    aux->showData(trainings);
    return aux;
}
