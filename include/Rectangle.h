//
// Created by Marius Boroica on 22.03.2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

/*

Implement a Rectangle class which encapsulates a rectangular area. The attributes of this class are x, y
two integers which represent the coordinates of the top-left corner of the rectangle, and width and
height the dimensions of the rectangle. Implement a default constructor, a parameterized constructor
and getters and setters for all the class attributes. This class should also overload the addition and
subtraction operators with a Point; these functions will be used to translate the rectangle. Overload
the binary and & and or | operators. The & operator will compute the intersection between two
rectangles, while the | operator will compute the union of two rectangles.

*/

#include "Point.h"

class Rectangle {
public:
    Rectangle();

    Rectangle(int x,int y,unsigned int width,unsigned int height);

    void setX(int x);
    void setY(int y);
    void setWidth(unsigned int width);
    void setHeight(unsigned int height);

    int getX();
    int getY(); 
    unsigned int getWidth();
    unsigned int getHeight();

    Rectangle& operator+(Point& other);
    Rectangle& operator-(Point& other);

    int operator&(Rectangle& other);
    int operator|(Rectangle& other);

private:
    int x;
    int y;
    unsigned int width;
    unsigned int height;
};


#endif //RECTANGLE_H
