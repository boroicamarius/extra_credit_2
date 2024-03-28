//
// Created by Marius Boroica on 22.03.2024.
//

#include "Point.h"

Point::Point() {
}

Point::Point(int x, int y): x(x), y(y) {
}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}
