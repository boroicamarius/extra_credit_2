//
// Created by Marius Boroica on 23.03.2024.
//

#ifndef BRIGHTNESSANDCONSTRAST_H
#define BRIGHTNESSANDCONSTRAST_H

#include "Image.h"
#include "ImageProcessing.h"

class BrightnessAndConstrast : public ImageProcessing {
public:
    BrightnessAndConstrast(float alpha, float beta);

    void process(const Image &src, Image &dst) override;

private:
    float alpha;
    float beta;
};

#endif //BRIGHTNESSANDCONSTRAST_H
