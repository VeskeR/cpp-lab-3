#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ellipse.h"
#include "rectangle.h"
#include "polygon.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timer_p = new QTimer(this);

    movingCircleX = 50;
    movingCircleY = 250;
    pxPerFrame = 7;

    connect( m_timer_p, SIGNAL( timeout() ), this, SLOT( ChangeT() ) );
    m_timer_p->start( 1000 / 60 );
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
    QPen polygonPen(Qt::darkMagenta);
    QBrush polygonBrush(Qt::darkMagenta);

    QPen leftCirclePen(Qt::gray);
    QBrush leftCircleBrush(Qt::gray);

    QPen rightCirclePen(Qt::darkMagenta);
    rightCirclePen.setWidth(5);
    QBrush rightCircleBrush(Qt::gray);

    QPen rectanglePen(Qt::yellow);
    QBrush rectangleBrush(Qt::yellow);

    QPen movingCirclePen(Qt::darkRed);
    QBrush movingCircleBrush(Qt::darkRed);

    // Draw polygon
    Polygon polygon(polygonPen, polygonBrush);

    polygon.addPoint(QPoint(70, 180));
    polygon.addPoint(QPoint(200, 90));
    polygon.addPoint(QPoint(330, 180));
    polygon.addPoint(QPoint(280, 320));
    polygon.addPoint(QPoint(120, 320));

    polygon.draw(painter);

    // Draw left circle
    Ellipse leftEl(100, 100, 50, 50, leftCirclePen, leftCircleBrush);
    leftEl.draw(painter);

    // Draw right circle
    Ellipse rightEl(300, 100, 50, 50, rightCirclePen, rightCircleBrush);
    rightEl.draw(painter);

    // Draw rectangle
    Rectangle rect(50, 250, 300, 50, rectanglePen, rectangleBrush);
    rect.draw(painter);

    // Draw text
    painter->setPen(Qt::yellow);
    painter->setBrush(Qt::yellow);
    painter->drawText(145, 200, 100, 20, 2, "COOL STRING");

    // Draw moving circle
    Ellipse movingCircle(movingCircleX, movingCircleY, 25, 25, movingCirclePen, movingCircleBrush);
    movingCircle.draw(painter);
}

void MainWindow::ChangeT()
{
    if (movingCircleY == 250 && movingCircleX != 350)
    {
        movingCircleX += pxPerFrame;
        if (movingCircleX > 350)
        {
            movingCircleX = 350;
        }
    }
    else if (movingCircleX == 350 && movingCircleY != 300)
    {
        movingCircleY += pxPerFrame;
        if (movingCircleY > 300)
        {
            movingCircleY = 300;
        }
    }
    else if (movingCircleY == 300 && movingCircleX != 50)
    {
        movingCircleX -= pxPerFrame;
        if (movingCircleX < 50)
        {
            movingCircleX = 50;
        }
    }
    else if (movingCircleX == 50 && movingCircleY != 250)
    {
        movingCircleY -= pxPerFrame;
        if (movingCircleY < 250)
        {
            movingCircleY = 250;
        }
    }

    update();
}
