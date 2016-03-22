#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ellipse.h"

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
    QPainter *painter = new QPainter(this);

    // Applies soft edges
    painter->setRenderHint(QPainter::Antialiasing);

    // Pens and brushes
    QPen leftCirclePen(Qt::gray);
    QBrush leftCircleBrush(Qt::gray);

    QPen rightCirclePen(Qt::darkMagenta);
    rightCirclePen.setWidth(5);
    QBrush rightCircleBrush(Qt::gray);

    // Draw polygon
    QPolygon poly;
    poly << QPoint(70, 180) << QPoint(200, 90) << QPoint(330, 180) << QPoint(280, 320) << QPoint(120, 320);
    painter->setPen(Qt::darkMagenta);
    painter->setBrush(Qt::darkMagenta);
    painter->drawPolygon(poly);

    // Draw left circle
    Ellipse leftEl(100, 100, 50, 50, leftCirclePen, leftCircleBrush);
    leftEl.draw(painter);

    // Draw right circle
    Ellipse rightEl(300, 100, 50, 50, rightCirclePen, rightCircleBrush);
    rightEl.draw(painter);

    // Draw rectangle
    painter->setPen(Qt::yellow);
    painter->setBrush(Qt::yellow);
    painter->drawRect(50, 250, 300, 50);

    // Draw text
    painter->setPen(Qt::yellow);
    painter->setBrush(Qt::yellow);
    painter->drawText(145, 200, 100, 20, 2, "COOL STRING");
}
