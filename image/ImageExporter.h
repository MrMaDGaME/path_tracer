#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include "Image.h"

class ImageExporter {
public:
    static void exportToPpm(const Image &image, const std::string &path);

    static void exportToPng(const Image &image, const std::string &path);
};
