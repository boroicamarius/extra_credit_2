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
    img.load(imgSavePath);



    printf("\tEnded: test_LoadAndSave\n");
}

void ImageTests::test_All() {
    printf("Running: ImageTests::test_All\n");
    test_LoadAndSave(
            "/home/boroicamarius/Development/extra_credit_2/tests/resources/apollonian_gasket.ascii.pgm",
            "/home/boroicamarius/Development/extra_credit_2/tests/resources/saved_apollonian_gasket.ascii.pgm"
    );
    printf("Running: ImageTests::test_All\n");
}
