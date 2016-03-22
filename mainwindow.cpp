#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    // Applies soft edges
    painter.setRenderHint(QPainter::Antialiasing);

    // Pens
    QPen rightCirclePen( Qt::darkMagenta );
    rightCirclePen.setWidth(5);

    // Draw polygon
    QPolygon poly;
    poly << QPoint(70, 180) << QPoint(200, 90) << QPoint(330, 180) << QPoint(280, 320) << QPoint(120, 320);
    painter.setPen(Qt::darkMagenta);
    painter.setBrush(Qt::darkMagenta);
    painter.drawPolygon(poly);

    // Draw left circle
    painter.setPen(Qt::gray);
    painter.setBrush(Qt::gray);
    painter.drawEllipse(75, 75, 50, 50);

    // Draw right circle
    painter.setPen(rightCirclePen);
    painter.setBrush(Qt::gray);
    painter.drawEllipse(275, 75, 50, 50);

    // Draw rectangle
    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::yellow);
    painter.drawRect(50, 250, 300, 50);

    // Draw text
    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::yellow);
    painter.drawText(145, 200, 100, 20, 2, "COOL STRING");
}
