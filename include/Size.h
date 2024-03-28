//
// Created by Marius Boroica on 22.03.2024.
//

#ifndef SIZE_H
#define SIZE_H

/*

Implement a Size class that encapsulates the dimensions of an object. The class should contain as
attributes two unsigned int for the width and height of the object. Implement a default constructor
and a parameterized constructor, as well as getters and setters for the class attributes. Also implement
the comparison operators for this class (==, <, <=, >, >=). Use the area of the objects to compare
them.

*/

class Size {
public:
    Size();

    Size(unsigned int width, unsigned int height);

    void setWidth(unsigned int width);

    void setHeight(unsigned int height);

    unsigned int getWidth();

    unsigned int getHeight();

    unsigned int getArea();

    bool operator==(Size &other);

    bool operator<(Size &other);

    bool operator>(Size &other);

    bool operator<=(Size &other);

    bool operator>=(Size &other);

private:
    unsigned int width;
    unsigned int height;
};


#endif //SIZE_H
