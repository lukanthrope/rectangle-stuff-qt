#include "rectangle.h"

Rectangle::Rectangle(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Rectangle::getWidth() {
    return this->width;
}

double Rectangle::getHeight() {
    return this->height;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

void Rectangle::setHeight(double height) {
    this->height = height;
}

QPair<double, double> Rectangle::getPoint() {
    return this->point;
}

void Rectangle::setPoint(QPair<double, double> point) {
    this->point = point;
}

void Rectangle::moveX(double x) {
    this->point.first += x;
}

void Rectangle::moveY(double y) {
    this->point.second += y;
}

double Rectangle::square() {
    return this->height * this->width;
}

QString Rectangle::getShortInfo() {
    return "Width = " + QString::number(this->getWidth()) + "\nHeight = "
        + QString::number(this->getHeight()) + "\nSquare = " + QString::number(this->square());
}
