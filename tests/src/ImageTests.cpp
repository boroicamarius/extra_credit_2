//
// Created by Marius Boroica on 28.03.2024.
//

#include "ImageTests.h"

void ImageTests::test_Load() {
    printf("\tRunning: test_Load\n");

    std::string IMAGE_PATH;
    IMAGE_PATH = "./tests/resources/apollonian_gasket.ascii.pgm";

    Image img = Image();
    assert(img.load(IMAGE_PATH) == true);

    printf("\tEnded: test_Load\n");
}

void ImageTests::test_Save() {
}

void ImageTests::test_All() {
    test_Load();
    test_Save();
}
