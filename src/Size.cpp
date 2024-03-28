//
// Created by Marius Boroica on 22.03.2024.
//

#include "Size.h"

Size::Size() {
}

Size::Size(unsigned int width, unsigned int height): width(width), height(height) {
}

void Size::setWidth(unsigned int width) {
    this->width = width;
}

void Size::setHeight(unsigned int height) {
    this->height = height;
}

unsigned int Size::getWidth() { return width; }
unsigned int Size::getHeight() { return height; }
unsigned int Size::getArea() { return width * height; }

bool Size::operator==(Size &other) {
    return getArea() == other.getArea();
}

bool Size::operator<(Size &other) {
    return getArea() < other.getArea();
}

bool Size::operator>(Size &other) {
    return getArea() > other.getArea();
}

bool Size::operator<=(Size &other) {
    return getArea() <= other.getArea();
}

bool Size::operator>=(Size &other) {
    return getArea() >= other.getArea();
}
