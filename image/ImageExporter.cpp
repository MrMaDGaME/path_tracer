#include "ImageExporter.h"

void ImageExporter::exportToPpm(const Image &image, const std::string &path) {
    std::stringstream ppm;
    ppm << "P3\n" << image.getWidth() << ' ' << image.getHeight() << "\n255\n";

    const auto &map = image.getMap();
    int width = image.getWidth();

    for (int j = 0; j < image.getHeight(); ++j) {
        for (int i = 0; i < width; ++i) {
            auto r = map[j * width + i].getR() / 255.0;
            auto g = map[j * width + i].getG() / 255.0;
            auto b = map[j * width + i].getB() / 255.0;
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            ppm << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::ofstream myfile(path);
    myfile << ppm.str();
    myfile.close();
}
