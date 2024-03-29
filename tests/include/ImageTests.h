//
// Created by Marius Boroica on 28.03.2024.
//

#ifndef IMAGETESTS_H
#define IMAGETESTS_H

#include "Image.h"
#include <assert.h>
#include <cstdio>


class ImageTests  {
public:
    static void test_LoadAndSave(std::string imgLoadPath, std::string imgSavePath);

    static void test_All();
};


#endif //IMAGETESTS_H
