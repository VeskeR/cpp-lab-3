#ifndef POLYGON_H
#define POLYGON_H

#include <QtGui>
#include <QtCore>

class Polygon
{
public:
    Polygon(QPen& pen, QBrush& brush);
    Polygon(Qt::PenStyle penColor, Qt::BrushStyle brushColor);
    ~Polygon();

    void addPoint(QPoint point);
    void draw(QPainter *painter);
    void rotate(int degrees);

private:
    int _rotation;
    QPolygon _poly;
    QPen _pen;
    QBrush _brush;
};

#endif // POLYGON_H
