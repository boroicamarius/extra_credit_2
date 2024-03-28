//
// Created by Marius Boroica on 27.03.2024.
//

#include "GammaCorrection.h"
#include <cmath>

GammaCorrection::GammaCorrection(float gamma): gamma(gamma) {
}

void GammaCorrection::process(const Image &src, Image &dst) {
    if (gamma == 1) {
        dst = src;
        return;
    }

    dst = Image(src);

    for (int y = 0; y < dst.height(); ++y) {
        for (int x = 0; x < dst.width(); ++x) {
            dst.at(x, y) = std::min(static_cast<unsigned char>(255),
                                    static_cast<unsigned char>(std::pow(static_cast<double>(dst.at(x, y)), gamma)));
        }
    }
}
