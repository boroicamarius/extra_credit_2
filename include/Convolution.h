//
// Created by Marius Boroica on 28.03.2024.
//

#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include "Image.h"
#include "ImageProcessing.h"

class Convolution : public ImageProcessing {
public:
    Convolution(unsigned int width, unsigned int height, unsigned char (*apply_kernel)(Point,const Image &));
    void process(const Image &src, Image &dst) override;

private:
    unsigned int width;
    unsigned int height;

    unsigned char (*apply_kernel)(Point,const Image &);
};


#endif //CONVOLUTION_H
