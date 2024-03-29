//
// Created by Marius Boroica on 22.03.2024.
//

#include <iostream>
#include "Image.h"

#include <sstream>

#include "ImageExceptions.h"

Image::Image() {
    m_data = NULL;
    m_width = 0;
    m_height = 0;
}

Image::Image(unsigned int w, unsigned int h) : m_width(w), m_height(h) {
    m_data = new unsigned char *[h];
    for (int i = 0; i < h; ++i)
        m_data[i] = new unsigned char[w];
}

Image::Image(const Image &other) {
    m_width = other.m_width;
    m_height = other.m_height;

    m_data = new unsigned char *[m_height];
    for (int i = 0; i < m_height; ++i) {
        m_data[i] = new unsigned char [m_width];
        for (int j = 0; j < m_width; ++j) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

Image &Image::operator=(const Image &other) {
    if (&other == NULL) {
        return *this;
    }
    if (!isEmpty()) release();

    m_width = other.width();
    m_height = other.height();
    m_data = new unsigned char *[m_height];
    for (int i = 0; i < m_height; ++i) {
        m_data[i] = new unsigned char[m_width];
        for (int j = 0; j < m_width; ++j) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
    return *this;
}

Image::~Image() {
    release();
}

bool Image::load(std::string imagePath) {
    if (!isEmpty()) release();

    std::ifstream file(imagePath);

    std::string fileType;
    int contentWidth = 0, contentHeight = 0;
    std::string description;
    int maxPixelValue;

    file >> fileType;

    if (fileType != "P2") {
        file.close();
        return false;
    }

    file >> contentWidth >> contentHeight;
    file.ignore();

    std::getline(file, description);
    if (description.size() > 0 && description[0] != '#') {
        std::stringstream stream(description);
        stream >> maxPixelValue;
    } else {
        file >> maxPixelValue;
    }

    m_width = contentWidth;
    m_height = contentHeight;

    m_data = new unsigned char *[m_height];
    for (int i = 0; i < m_height; ++i)
        m_data[i] = new unsigned char[m_width];

    int value;
    for (int i = 0; i < m_height; ++i)
        for (int j = 0; j < m_width; ++j) {
            file >> value;
            m_data[i][j] = value % 256;
        }

    file.close();
    return true;
}

bool Image::save(std::string imagePath) const {
    std::ofstream file(imagePath);

    file << "P2\n";
    file << (int) m_width << ' ' << (int) m_height << '\n';
    file << "# Saved image\n";
    file << "255\n";

    for (int i = 0; i < m_height; ++i) {
        for (int j = 0; j < m_width; ++j)
            file << (int) m_data[i][j] << ' ';
        file << '\n';
    }

    file.close();
    return true;
}

Image Image::operator+(const Image &i) {
    if (isEmpty() || i.isEmpty())
        throw IMAGE_EMPTY;

    if (m_width != i.m_width || m_height != i.m_height)
        throw IMAGE_DIFFERENT_SIZE;

    Image res(*this);

    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            res.at(x, y) = std::min(255, (int) res.at(x, y) + (int) i.m_data[y][x]);
        }
    }

    return res;
}

Image Image::operator-(const Image &i) {
    if (isEmpty() || i.isEmpty())
        throw IMAGE_EMPTY;

    if (m_width != i.m_width || m_height != i.m_height)
        throw IMAGE_DIFFERENT_SIZE;

    Image res(*this);

    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            res.at(x, y) = std::max(0, (int) res.at(x, y) - (int) i.m_data[y][x]);
        }
    }

    return res;
}

Image Image::operator*(double s) {
    Image res(*this);

    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            res.at(x, y) = std::min(255, (int) (res.at(x, y) * s));
        }
    }

    return res;
}

bool Image::getROI(Image &roiImg, Rectangle roiRect) {
    if (roiRect.getX() + roiRect.getWidth() > m_width || roiRect.getY() + roiRect.getHeight() > m_height)
        return false;

    Image res(roiRect.getWidth(), roiRect.getHeight());

    for (int y = roiRect.getY(); y < m_height; ++y) {
        for (int x = roiRect.getX(); x < m_width; ++x) {
            res.at(x, y) = m_data[y][x];
        }
    }

    roiImg = res;
    return true;
}

bool Image::getROI(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if (x + width > m_width || y + height > m_height)
        return false;

    Image res(width, height);

    for (int i = y; i < y + height; ++i) {
        for (int j = x; j < x + width; ++j) {
            res.at(x, y) = m_data[y][x];
        }
    }

    roiImg = res;
    return true;
}

bool Image::isEmpty() const {
    return m_data == NULL && m_width == 0 && m_height == 0;
}

Size Image::size() const {
    return Size(m_width, m_height);
}

unsigned int Image::width() const {
    return m_width;
}

unsigned int Image::height() const {
    return m_height;
}

unsigned char &Image::at(unsigned int x, unsigned int y) {
    return m_data[y][x];
}

unsigned char &Image::at(Point pt) {
    return m_data[pt.getY()][pt.getX()];
}

unsigned char Image::get(Point pt) const {
    return m_data[pt.getY()][pt.getX()];
}

unsigned char *Image::row(int y) {
    return m_data[y];
}

void Image::release() {
    if (isEmpty()) return;

    m_width = 0;
    m_height = 0;

    for (int i = 0; i < m_height; ++i)
        delete[] m_data[i];

    delete[] m_data;
}

std::ostream &operator<<(std::ostream &os, const Image &dt) {
    if (dt.isEmpty()) {
        os << "Empty image\n";
        return os;
    }

    os << dt.width() << ' ' << dt.height() << '\n';
    for (unsigned int y = 0; y < dt.height(); ++y) {
        for (unsigned int x = 0; x < dt.width(); ++x) {
            os << dt.m_data[y][x] << ' ';
        }
        os << '\n';
    }

    return os;
}

std::istream &operator>>(std::istream &is, Image &dt) {
    unsigned int width, height;

    is >> width >> height;

    dt = Image(width, height);

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            is >> dt.m_data[y][x];
        }
    }

    return is;
}

Image Image::zeros(unsigned int width, unsigned int height) {
    return Image(width, height);
}

Image Image::ones(unsigned int width, unsigned int height) {
    Image res(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            res.at(x, y) = 1;
        }
    }

    return res;
}
