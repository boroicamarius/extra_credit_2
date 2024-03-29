//
// Created by Marius Boroica on 28.03.2024.
//

#include <iostream>
#include "ImageTests.h"

void ImageTests::test_LoadAndSave(std::string imgLoadPath, std::string imgSavePath) {
    printf("\tRunning: test_LoadAndSave\n");

    Image img = Image();

    assert(img.load(imgLoadPath) == true);

    assert(img.width() == 600);
    assert(img.height() == 600);

    assert(img.save(imgSavePath) == true);
    printf("\t\tLoading image\n");
    img.load(imgSavePath);

    printf("\tEnded: test_LoadAndSave\n");
}

void ImageTests::test_All() {
    printf("Running: ImageTests::test_All\n");
    std::string FILES_DIR = "/Users/boroicamarius/Development/ubblab/extra_credit_2/tests/resources/";
    test_LoadAndSave(FILES_DIR + "apollonian_gasket.ascii.pgm",
                     FILES_DIR + "saved_apollonian_gasket.ascii.pgm"
    );
    printf("Running: ImageTests::test_All\n");
}
