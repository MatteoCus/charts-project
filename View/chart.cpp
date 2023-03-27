#include "chart.h"

chart::chart(QWidget *parent) : QWidget(parent)
{
    graph = new QChart();

    chartView = new QChartView(graph,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setFixedSize(600,450);

    graph->setTheme(QChart::ChartThemeDark);
    QFont font;
    font.setBold(true);
    font.setPixelSize(15);
    graph->setTitleFont(font);
    graph->setTitle("Statistiche di allenamento");

    graph->setBackgroundBrush(QBrush(QColor(QRgb(0x404244))));
    graph->setAnimationOptions(QChart::AllAnimations);
}

QChartView *chart::getChartView() const
{
    return chartView;
}
