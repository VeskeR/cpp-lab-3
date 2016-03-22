#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height, QPen& pen, QBrush& brush)
{
    this->_x = x;
    this->_y = y;
    this->_width = width;
    this->_height = height;
    this->_pen = pen;
    this->_brush = brush;
    this->_rotation = 0;
}

Rectangle::Rectangle(int x, int y, int width, int height, Qt::PenStyle penColor, Qt::BrushStyle brushColor)
{
    this->_x = x;
    this->_y = y;
    this->_width = width;
    this->_height = height;
    this->_pen = QPen(penColor);
    this->_brush = QBrush(brushColor);
    this->_rotation = 0;
}

Rectangle::~Rectangle()
{

}

void Rectangle::draw(QPainter *painter)
{
    QPen oldPen = painter->pen();
    QBrush oldBrush = painter->brush();

    painter->setPen(this->_pen);
    painter->setBrush(this->_brush);
    painter->translate(this->_x + this->_width / 2, this->_y + this->_height / 2);
    painter->rotate(this->_rotation);

    painter->drawRect(-(this->_width / 2), -(this->_height / 2), this->_width, this->_height);

    painter->rotate(-this->_rotation);
    painter->translate(-(this->_x + this->_width / 2), -(this->_y + this->_height / 2));
    painter->setBrush(oldBrush);
    painter->setPen(oldPen);
}

void Rectangle::rotate(int degrees)
{
    this->_rotation += degrees;
}
