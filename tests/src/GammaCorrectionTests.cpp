//
// Created by Marius Boroica on 28.03.2024.
//

#include "GammaCorrectionTests.h"

#include "GammaCorrection.h"
#include "Image.h"

void GammaCorrectionTests::test_Process(std::string filesPath) {
    Image src = Image();
    Image dst = Image();

    src.load(filesPath+"casablanca.ascii.pgm");
    GammaCorrection g = GammaCorrection(0.8);

    g.process(src,dst);

    dst.save(filesPath+"gamma_test.ascii.pgm");
}

void GammaCorrectionTests::test_All(std::string filesPath) {
    printf("Running: GammaCorrectionTests::test_All\n");

    test_Process(filesPath);

    printf("Running: GammaCorrectionTests::test_All\n");
}
