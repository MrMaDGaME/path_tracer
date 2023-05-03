#include <sstream>
#include <bitset>
#include <fstream>
#include "image.hh"

Image::Image(int width, int height) : height(height), width(width) {
    for (int i = 0; i < height * width; i++) {
        map.emplace_back(0, 0, 0);
    }
}

void Image::to_ppm(const std::string &path) const {
    std::stringstream ppm;
    ppm << "P3\n" << width << ' ' << height << "\n255\n";
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            auto r = map[j * width + i]._r / 255.0;
            auto g = map[j * width + i]._g / 255.0;
            auto b = map[j * width + i]._b / 255.0;
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);
            ppm << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::ofstream myfile;
    myfile.open(path);
    myfile << ppm.str();
    myfile.close();
}

[[maybe_unused]] void Image::set_pixel(unsigned int x, unsigned int y, const Color &color) {
    map[y * width + x] = color;
}

[[maybe_unused]] void Image::add_color(unsigned int x, unsigned int y, const Color &color) {
    map[y * width + x] += color;
}

[[maybe_unused]] void Image::avegrage_color(unsigned int x, unsigned int y, const Color &color, int n) {
    auto nf = static_cast<float>(n);
    map[y * width + x] = (map[y * width + x] * nf + color) / (nf + 1);
}

[[maybe_unused]] void Image::get_max(unsigned int x, unsigned int y, const Color &color) {
    map[y * width + x]._r = std::max(map[y * width + x]._r, color._r);
    map[y * width + x]._g = std::max(map[y * width + x]._g, color._g);
    map[y * width + x]._b = std::max(map[y * width + x]._b, color._b);
}
