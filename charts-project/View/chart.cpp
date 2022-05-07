#include "chart.h"

chart::chart(QWidget *parent) : QWidget(parent)
{
    graph = new QChart();
    graph->legend()->hide();

    graph->setTheme(QChart::ChartThemeDark);
    QFont font;
    font.setBold(true);
    font.setPixelSize(15);
    graph->setTitleFont(font);
    graph->setTitle("Statistiche di allenamento");

    graph->setBackgroundBrush(QBrush(QColor(QRgb(0x404244))));
    graph->setAnimationOptions(QChart::GridAxisAnimations);
}

QChart *chart::getChart() const
{
    return graph;
}
