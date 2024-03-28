//
// Created by Marius Boroica on 22.03.2024.
//

#ifndef POINT_H
#define POINT_H

/*

Write a Point class to represent a point in a two-dimensional space; the class should have two integer
attributes for the x and y coordinates of the point, getters and setters for these variables. Implement a
default constructor which initializes a point to (0, 0), and a parameterized constructor.

*/

class Point {
public:
    Point();
    Point(int x, int y);

    void setX(int x);
    void setY(int y);

    int getX();
    int getY();

private:
    int x;
    int y;
};


#endif //POINT_H
