#include "polygon.h"

Polygon::Polygon(QPen& pen, QBrush& brush)
{
    this->_poly = QPolygon();
    this->_pen = pen;
    this->_brush = brush;
    this->_rotation = 0;
}

Polygon::Polygon(Qt::PenStyle penColor, Qt::BrushStyle brushColor)
{
    this->_poly = QPolygon();
    this->_pen = QPen(penColor);
    this->_brush = QBrush(brushColor);
    this->_rotation = 0;
}

Polygon::~Polygon()
{

}

void Polygon::addPoint(QPoint point)
{
    this->_poly << point;
}

void Polygon::draw(QPainter *painter)
{
    QPen oldPen = painter->pen();
    QBrush oldBrush = painter->brush();

    painter->setPen(this->_pen);
    painter->setBrush(this->_brush);
    painter->rotate(this->_rotation);

    painter->drawPolygon(this->_poly);

    painter->rotate(-this->_rotation);
    painter->setBrush(oldBrush);
    painter->setPen(oldPen);
}

void Polygon::rotate(int degrees)
{
    this->_rotation += degrees;
}

