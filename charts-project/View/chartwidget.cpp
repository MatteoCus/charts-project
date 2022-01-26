#include "chartwidget.h"

void chartWidget::addDefaultChart(QVBoxLayout * mainLayout)
{
    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries(chart);

    chart->addSeries(series);
    chart->legend()->hide();
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

    chart->setTheme(QChart::ChartThemeDark);
    chart->setBackgroundBrush(QBrush(QColor(QRgb(0x404244))));
    chart->setAnimationOptions(QChart::GridAxisAnimations);

    QChartView *chartView = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMaximumSize(1200,600);
    chartView->setMinimumSize(600,300);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->resize(800,400);
    mainLayout->addWidget(chartView);
}

void chartWidget::addControls(QVBoxLayout * mainLayout)
{
    QHBoxLayout * controlsLayout = new QHBoxLayout();
    QComboBox* chartBox = new QComboBox(this);
    chartBox->addItem("Line Chart");
    chartBox->addItem("Bar Chart");
    chartBox->addItem("Other Chart");
    chartBox->setFixedSize(100,25);
    chartBox->setStyleSheet("QComboBox{ background-color : #c26110 ; color : white; selection-background-color: #c26110 }"
                            "QComboBox QListView {background-color : #c26110 ; color : white;}");

    QComboBox* dataBox = new QComboBox(this);
    dataBox->addItem("Durata");
    dataBox->addItem("Calorie");
    dataBox->addItem("Intensità (*)");
    dataBox->setFixedSize(100,25);
    dataBox->setStyleSheet("QComboBox {background-color : #404244 ; color: white ; selection-background-color: #404244 ;"
                           "selection-color : white} "
                           "QComboBox::drop-down{background-color : #c26110 ;}"
                           "QComboBox::drop-down"
                           "{"
                           "border : 1px solid;"
                           "border-color : #404244 #2e2f30 #2e2f30 #404244;}"
                           "QComboBox::drop-down:pressed{"
                           "border : 1px solid;"
                           "border-color :  gray gray gray gray}"
                           "QComboBox::down-arrow{image : url(C:/Users/Matteo/Documents/GitHub/charts-project/charts-project/icons/pngwing.com.png); width: 12px;"
                           "height: 12px;}"
                           "QComboBox QListView {background-color : #404244 ; color : white;}"
                           "QComboBox QAbstractItemView {selection-background-color:#c26110;}");   //IMPORTANTE

    controlsLayout->addWidget(chartBox);
    controlsLayout->addWidget(dataBox);
    controlsLayout->setSpacing(20);
    controlsLayout->setAlignment(Qt::AlignHCenter);
    mainLayout->addLayout(controlsLayout);
}

chartWidget::chartWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * mainLayout = new QVBoxLayout();

    addDefaultChart(mainLayout);

    addControls(mainLayout);

    mainLayout->setAlignment(Qt::AlignHCenter);

    setLayout(mainLayout);

    setStyleSheet("QWidget {background : #2e2f30}");        //TOGLIERE ALLA FINE DELLA CREAZIONE DELLA VIEW

    show();
}
