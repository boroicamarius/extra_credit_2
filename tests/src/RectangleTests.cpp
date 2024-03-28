//
// Created by Marius Boroica on 22.03.2024.
//

#include <cassert>
#include <cstdio>

#include "RectangleTests.h"

void RectangleTests::test_Intersection() {
    printf("\tRunning: test_Intersection\n");

    Rectangle a(0, 0, 2, 2);
    Rectangle b(2, 2, 2, 2);

    Rectangle c(0, 0, 3, 3);
    Rectangle d(0, 0, 3, 2);

    assert((a&b)==0);
    assert((a&c)==4);
    assert((c&d)==6);
    assert((c&b)==1);

    printf("\tEnded: test_Intersection\n");
}

void RectangleTests::test_Union() {
    printf("\tRunning: test_Union\n");

    Rectangle a(0, 0, 2, 2);
    Rectangle b(2, 2, 2, 2);

    Rectangle c(0, 0, 3, 3);
    Rectangle d(0, 0, 3, 2);

    assert((a|b)==8);
    assert((a|c)==9);
    assert((c|d)==9);
    assert((c|b)==12);

    printf("\tEnded: test_Union\n");
}

void RectangleTests::test_All() {
    printf("Running: test_All\n");

    test_Intersection();
    test_Union();

    printf("Ended: test_All\n");
}
