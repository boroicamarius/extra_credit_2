//
// Created by Marius Boroica on 28.03.2024.
//

#include "ConvolutionTest.h"

#include "Convolution.h"
#include "Image.h"
#include "Point.h"

int kernel[3][3] = {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1},
};

unsigned char conv_fun(Point origin, const Image &img) {

    int val = 0;
    unsigned int x = origin.getX(), y = origin.getY();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            val += kernel[i][j] * img.get(Point(x + j, y + i));
        }
    }
    double blur = std::abs(val);
    return static_cast<unsigned char>(std::min(255, static_cast<int>(blur)));
}

void ConvolutionTest::test_Process(std::string filesPath) {
    Image src = Image();
    Image dst = Image();

    src.load(filesPath + "casablanca.ascii.pgm");
    Convolution c = Convolution(3, 3, conv_fun);
    c.process(src, dst);
    dst.save(filesPath + "convolution_test.ascii.pgm");
}

void ConvolutionTest::test_All(std::string filesPath) {
    printf("Running: ConvolutionTest::test_All\n");

    test_Process(filesPath);

    printf("Running: ConvolutionTest::test_All\n");
}
