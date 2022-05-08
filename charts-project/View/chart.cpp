#include "chart.h"

QTime *chart::convertTime(TimeSpan *time)
{
    return new QTime(time->getHours(),time->getMinutes(), time->getSeconds());
}

QDateTime *chart::convertDateTime(DateTime *dateTime)
{
    Date d = dateTime->getDate();
    Time t = dateTime->getTime();
    return new QDateTime(QDate(d.getYear(), d.getMonth(), d.getDay()),*(convertTime(&t)));
}

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
    graph->setAnimationOptions(QChart::GridAxisAnimations);
}

QChartView *chart::getChartView() const
{
    return chartView;
}
