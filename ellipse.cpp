#include "ellipse.h"

Ellipse::Ellipse(int x, int y, int rx, int ry, QPen& pen, QBrush& brush)
{
    this->_x = x;
    this->_y = y;
    this->_rx = rx;
    this->_ry = ry;
    this->_pen = pen;
    this->_brush = brush;
    this->_rotation = 0;
}

Ellipse::Ellipse(int x, int y, int rx, int ry, Qt::PenStyle penColor, Qt::BrushStyle brushColor)
{
    this->_x = x;
    this->_y = y;
    this->_rx = rx;
    this->_ry = ry;
    this->_pen = QPen(penColor);
    this->_brush = QBrush(brushColor);
    this->_rotation = 0;
}

Ellipse::~Ellipse()
{

}

void Ellipse::draw(QPainter *painter)
{
    QPen oldPen = painter->pen();
    QBrush oldBrush = painter->brush();

    painter->setPen(this->_pen);
    painter->setBrush(this->_brush);
    painter->translate(this->_x, this->_y);
    painter->rotate(this->_rotation);

    painter->drawEllipse(-(this->_rx / 2), -(this->_ry / 2), this->_rx, this->_ry);

    painter->setPen(oldPen);
    painter->setBrush(oldBrush);
    painter->rotate(-this->_rotation);
    painter->translate(-this->_x, -this->_y);
}

void Ellipse::rotate(int degrees)
{
    this->_rotation += degrees;
}

void Ellipse::setX(int x)
{
    this->_x = x;
}

void Ellipse::setY(int y)
{
    this->_y = y;
}
