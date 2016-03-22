#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QtGui>
#include <QtCore>

class Ellipse
{
public:
    Ellipse(int x, int y, int rx, int ry, QPen& pen, QBrush& brush);
    Ellipse(int x, int y, int rx, int ry, Qt::PenStyle penColor, Qt::BrushStyle brushColor);
    ~Ellipse();

    void draw(QPainter *painter);
    void rotate(int degrees);
    void setX(int x);
    void setY(int y);

private:
    int _x;
    int _y;
    int _rx;
    int _ry;
    int _rotation;
    QPen _pen;
    QBrush _brush;
};

#endif // ELLIPSE_H
