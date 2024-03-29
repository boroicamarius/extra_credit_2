//
// Created by Marius Boroica on 27.03.2024.
//
#include "BrightnessAndContrast.h"


BrightnessAndConstrast::BrightnessAndConstrast(float alpha, float beta): alpha(alpha), beta(beta) {
}

void BrightnessAndConstrast::process(const Image &src, Image &dst) {
    Image x = Image(src);
    Image y = Image::ones(src.width(), src.height());

    if (beta < 0) {
        dst = x * alpha - y * (beta * -1);
        return;
    }
    dst = x * alpha + y * beta;
}
