#include "chartwidget.h"

void chartWidget::addDefaultChart(QVBoxLayout * mainLayout)
{
    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries(chart);

    chart->addSeries(series);
    chart->legend()->hide();

    chart->setTheme(QChart::ChartThemeDark);
    QFont font;
    font.setBold(true);
    font.setPixelSize(15);
    chart->setTitleFont(font);
    chart->setTitle("Statistiche di allenamento");

    QDateTimeAxis *axisX = new QDateTimeAxis(chart);
    axisX->setFormat("dd.MM.yyyy");
    axisX->setTitleText("Data di allenamento");
    chart->setAxisX(axisX, series);

    QValueAxis *axisY = new QValueAxis(chart);
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Durata");
    chart->setAxisY(axisY, series);

    QPen pen(QRgb(0xc26110));
    pen.setWidth(3);
    series->setPen(pen);

    chart->setBackgroundBrush(QBrush(QColor(QRgb(0x404244))));
    chart->setAnimationOptions(QChart::GridAxisAnimations);

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setFixedSize(600,400);
    mainLayout->addWidget(chartView);
}

void chartWidget::addControls(QVBoxLayout * mainLayout)
{
    QHBoxLayout * controlsLayout = new QHBoxLayout();
    QComboBox* chartBox = new QComboBox(this);
    chartBox->addItem("Line Chart");
    chartBox->addItem("Bar Chart");
    chartBox->addItem("Other Chart");
    chartBox->setFixedSize(80,25);
    chartBox->setStyleSheet("QComboBox {background-color : #404244 ; color: white ; selection-background-color: #404244 ;"
                            "selection-color : white} "
                            "QComboBox::drop-down{background-color : #c26110 ;}"
                            "QComboBox::drop-down"
                            "{"
                            "border : 2px solid;"
                            "border-color : #df7012 #81410b #81410b #df7012;}"
                            "QComboBox::drop-down:pressed{"
                            "border : 2px solid;"
                            "border-color : #81410b #df7012 #df7012 #81410b;}"
                            //"QComboBox::down-arrow{image : url(/home/matteo/Documenti/GitHub/charts-project/charts-project/pngwing.com.png); width: 10px;"
                            //"height: 10px;}"
                            "QComboBox QListView {background-color : #404244 ; color : white;}"
                            "QComboBox QAbstractItemView {selection-background-color:#c26110;}");   //IMPORTANTE

    QComboBox* dataBox = new QComboBox(this);
    dataBox->addItem("Durata");
    dataBox->addItem("Calorie");
    dataBox->addItem("Intensità (*)");
    dataBox->setFixedSize(70,25);
    dataBox->setStyleSheet("QComboBox {background-color : #404244 ; color: white ; selection-background-color: #404244 ;"
                           "selection-color : white} "
                           "QComboBox::drop-down{background-color : #c26110 ;}"
                           "QComboBox::drop-down"
                           "{"
                           "border : 2px solid;"
                           "border-color : #df7012 #81410b #81410b #df7012;}"
                           "QComboBox::drop-down:pressed{"
                           "border : 2px solid;"
                           "border-color : #81410b #df7012 #df7012 #81410b;}"
                           "QComboBox::down-arrow{image : url(/home/matteo/Documenti/GitHub/charts-project/charts-project/pngwing.com.png); width: 10px;"
                           "height: 10px;}"
                           "QComboBox QListView {background-color : #404244 ; color : white;}"
                           "QComboBox QAbstractItemView {selection-background-color:#c26110;}");   //IMPORTANTE

    controlsLayout->addWidget(chartBox);
    controlsLayout->addWidget(dataBox);
    controlsLayout->setContentsMargins(10,20,10,10);
    controlsLayout->setSpacing(50);
    controlsLayout->setAlignment(Qt::AlignHCenter);
    mainLayout->addLayout(controlsLayout);
}

chartWidget::chartWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * mainLayout = new QVBoxLayout();

    addDefaultChart(mainLayout);

    addControls(mainLayout);

    setStyleSheet("QWidget{background-color : #2e2f30}");
    mainLayout->setAlignment(Qt::AlignTop);
    setLayout(mainLayout);
}
