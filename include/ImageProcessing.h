//
// Created by Marius Boroica on 23.03.2024.
//

#ifndef IMAGEPROCESSING_H
#define IMAGEPROCESSING_H

class ImageProcessing {
public:
    virtual ~ImageProcessing();

    virtual void process(const Image &src, Image &dst);
};

#endif //IMAGEPROCESSING_H
