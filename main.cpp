//
// Created by Marius Boroica on 22.03.2024.
//

#include "BrightnessAndContrastTests.h"
#include "ConvolutionTest.h"
#include "GammaCorrectionTests.h"
#include "ImageTests.h"
#include "RectangleTests.h"

int main() {
    std::string filesDir = "/Users/boroicamarius/Development/ubblab/extra_credit_2/tests/resources/";
    RectangleTests::test_All();
    ImageTests::test_All();
    BrightnessAndContrastTests::test_All(filesDir);
    GammaCorrectionTests::test_All(filesDir);
    ConvolutionTest::test_All(filesDir);
}
