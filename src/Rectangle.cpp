//
// Created by Marius Boroica on 22.03.2024.
//

#include "Rectangle.h"

#include <algorithm>
#include <Point.h>
#include <Size.h>

Rectangle::Rectangle() {
}

Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height) : x(x), y(y), width(width), height(height) {
}

void Rectangle::setX(int x) {
    this->x = x;
}

void Rectangle::setY(int y) {
    this->y = y;
}

void Rectangle::setWidth(unsigned int width) {
    this->width = width;
}

void Rectangle::setHeight(unsigned int height) {
    this->height = height;
}

int Rectangle::getX() {
    return x;
}

int Rectangle::getY() {
    return y;
}

unsigned int Rectangle::getWidth() {
    return width;
}

unsigned int Rectangle::getHeight() {
    return height;
}

Rectangle &Rectangle::operator+(Point &other) {
    x += other.getX();
    y += other.getY();

    return *this;
}

Rectangle &Rectangle::operator-(Point &other) {
    x -= other.getX();
    y -= other.getY();

    return *this;
}


int Rectangle::operator&(Rectangle &other) {
    Point pa,pb;
    Size sa,sb;

    if(x<=other.x) {
        pa = Point(x,y), pb=Point(other.x,other.y);
        sa = Size(width,height), sb=Size(other.width,other.height);
    }
    else {
        pb = Point(x,y), pa=Point(other.x,other.y);
        sb = Size(width,height), sa=Size(other.width,other.height);
    }

    unsigned int maxIntersectionWidth = std::max(0,pa.getX()+(int)sa.getWidth()-pb.getX());
    unsigned int intersectionWidth = std::min(sb.getWidth(),maxIntersectionWidth);

    if(y<=other.y) {
        pa = Point(x,y), pb=Point(other.x,other.y);
        sa = Size(width,height), sb=Size(other.width,other.height);
    }
    else {
        pb = Point(x,y), pa=Point(other.x,other.y);
        sb = Size(width,height), sa=Size(other.width,other.height);
    }

    unsigned int maxIntersectionHeight = std::max(0,pa.getY()+(int)sa.getHeight()-pb.getY());
    unsigned int intersectionHeight = std::min(sb.getHeight(),maxIntersectionHeight);

    return intersectionHeight*intersectionWidth;
}

int Rectangle::operator|(Rectangle &other) {
    return (width*height) + (other.width*other.height) - this->operator&(other);
}
