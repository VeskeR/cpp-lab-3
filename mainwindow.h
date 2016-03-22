#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected slots:
    void ChangeT();

protected:
    void paintEvent(QPaintEvent *e);

private:
  Ui::MainWindow *ui;
  QTimer *m_timer_p;
  int movingCircleX;
  int movingCircleY;
  int pxPerFrame;
};

#endif // MAINWINDOW_H
