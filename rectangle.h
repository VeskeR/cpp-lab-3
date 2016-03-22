#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QtGui>
#include <QtCore>

class Rectangle
{
public:
    Rectangle(int x, int y, int width, int height, QPen& pen, QBrush& brush);
    Rectangle(int x, int y, int width, int height, Qt::PenStyle penColor, Qt::BrushStyle brushColor);
    ~Rectangle();

    void draw(QPainter *painter);
    void rotate(int degrees);

private:
    int _x;
    int _y;
    int _width;
    int _height;
    int _rotation;
    QPen _pen;
    QBrush _brush;
};

#endif // RECTANGLE_H
