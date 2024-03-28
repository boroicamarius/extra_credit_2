//
// Created by Marius Boroica on 28.03.2024.
//

#include "Convolution.h"

Convolution::Convolution(unsigned int width, unsigned int height,
                         unsigned char (*apply_kernel)(Point, const Image &)): width(width), height(height),
                                                                               apply_kernel(apply_kernel) {
}

void Convolution::process(const Image &src, Image &dst) {
    dst = Image::zeros(width, height);
    for (int y = 0; y < src.height() - height + 1; ++y) {
        for (int x = 0; x < src.width() - width + 1; ++x) {
            dst.at(x, y) = apply_kernel(Point(x, y), src);
        }
    }
}
