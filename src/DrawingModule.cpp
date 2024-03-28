//
// Created by Marius Boroica on 28.03.2024.
//

#include "DrawingModule.h"

#include <complex>
#define M_PI           3.14159265358979323846  /* pi */


bool DrawingModule::pointNotInBoundaries(Point &point, Image &img) {
    return (point.getX() < 0 || point.getY() < 0 ||
            point.getX() >= img.width() || point.getY() >= img.height());
}

void DrawingModule::drawCircle(Image &img, Point center, int radius, unsigned char color) {
    int ox = center.getX();
    int oy = center.getY();

    for (double deg = 0.0; deg <= 360; deg += 0.5) {
        Point pixel = Point(ox + radius * std::cos((M_PI / 360.0) * deg),
                            oy + radius * std::sin((M_PI / 360.0) * deg)
        );

        if (pointNotInBoundaries(pixel, img))
            continue;

        img.at(pixel) = color;
    }
}

void DrawingModule::drawLine(Image &img, Point p1, Point p2, unsigned char color) {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();

    double d = dy / dx;

    for (double x = p1.getX(); x < static_cast<double>(p2.getX()); x += d) {
        Point pixel = Point(static_cast<int>(x),
                            static_cast<int>(d * x + dy));
        if (pointNotInBoundaries(pixel, img))
            continue;

        img.at(pixel) = color;
    }
}

void DrawingModule::drawRectangle(Image &img, Rectangle r, unsigned char color) {
    for (int x = r.getX(); x < r.getX() + r.getWidth(); ++x) {
        Point up = Point(x, r.getY());
        Point down = Point(x, r.getY() + r.getHeight() - 1);

        if (!pointNotInBoundaries(up, img))
            img.at(up) = color;
        if (!pointNotInBoundaries(down, img))
            img.at(down) = color;
    }

    for (int y = r.getY(); y < r.getY() + r.getHeight(); ++y) {
        Point left = Point(r.getX(), y);
        Point right = Point(r.getX() + r.getWidth() - 1, y);

        if (!pointNotInBoundaries(left, img))
            img.at(left) = color;
        if (!pointNotInBoundaries(right, img))
            img.at(right) = color;
    }
}

void DrawingModule::drawRectangle(Image &img, Point tl, Point br, unsigned char color) {
    Rectangle r = Rectangle(tl.getX(), tl.getY(), br.getX() - tl.getX(), br.getY() - tl.getY());
    drawRectangle(img, r, color);
}
