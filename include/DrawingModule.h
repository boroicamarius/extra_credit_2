//
// Created by Marius Boroica on 28.03.2024.
//

#ifndef DRAWINGMODULE_H
#define DRAWINGMODULE_H
#include "Image.h"


class DrawingModule {
public:
    static bool pointNotInBoundaries(Point &point, Image &img);

    static void drawCircle(Image &img, Point center, int radius, unsigned char color);

    static void drawLine(Image &img, Point p1, Point p2, unsigned char color);

    static void drawRectangle(Image &img, Rectangle r, unsigned char color);

    static void drawRectangle(Image &img, Point tl, Point br, unsigned char color);
};


#endif //DRAWINGMODULE_H
