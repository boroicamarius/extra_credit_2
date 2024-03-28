//
// Created by Marius Boroica on 27.03.2024.
//

#ifndef GAMMACORRECTION_H
#define GAMMACORRECTION_H

#include "Image.h"
#include "ImageProcessing.h"

class GammaCorrection : public ImageProcessing {
public:
    ~GammaCorrection() override = default;

    explicit GammaCorrection(float gamma);

    void process(const Image &src, Image &dst) override;

private:
    float gamma;
};


#endif //GAMMACORRECTION_H
