//
// Created by Marius Boroica on 28.03.2024.
//

#include "BrightnessAndContrastTests.h"

#include <cassert>
#include <cstdio>
#include <string>

#include "BrightnessAndContrast.h"
#include "Image.h"

void BrightnessAndContrastTests::test_Process(std::string filesPath) {
    Image src = Image(), dst = Image();
    BrightnessAndConstrast b(3, -30);

    assert(src.load(filesPath + "casablanca.ascii.pgm") == true);
    src.save(filesPath + "_casablanca.ascii.pgm");
    b.process(src, dst);

    assert(dst.save(filesPath + "saved_casablanca.ascii.pgm") == true);
}

void BrightnessAndContrastTests::test_All(std::string filesPath) {
    printf("Running: BrightnessAndContrastTests::test_All\n");

    test_Process(filesPath);

    printf("Running: BrightnessAndContrastTests::test_All\n");
}
