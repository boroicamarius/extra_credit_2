//
// Created by Marius Boroica on 27.03.2024.
//
#include "BrightnessAndContrast.h"


BrightnessAndConstrast::BrightnessAndConstrast(float alpha, float beta): alpha(alpha), beta(beta) {
}

void BrightnessAndConstrast::process(const Image &src, Image &dst) {
    if (beta < 0) {
        dst = Image(src) * alpha - Image::ones(src.width(), src.height()) * (beta * -1);
        return;
    }
    dst = Image(src) * alpha + Image::ones(src.width(), src.height()) * beta;
}
