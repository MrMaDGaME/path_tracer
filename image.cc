#include "image.hh"

Image::Image(int width, int height) : height_(height), width_(width) {
    for (int i = 0; i < height * width; i++) {
        map.emplace_back(0, 0, 0);
    }
}

void Image::to_ppm(const std::string &path) const {
    std::stringstream ppm;
    ppm << "P3\n" << width_ << ' ' << height_ << "\n255\n";
    for (int j = 0; j < height_; ++j) {
        for (int i = 0; i < width_; ++i) {
            auto r = map[j * width_ + i]._r / 255.0;
            auto g = map[j * width_ + i]._g / 255.0;
            auto b = map[j * width_ + i]._b / 255.0;
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
    map[y * width_ + x] = color;
}

[[maybe_unused]] void Image::add_color(unsigned int x, unsigned int y, const Color &color) {
    map[y * width_ + x] += color;
}

[[maybe_unused]] void Image::average_color(unsigned int x, unsigned int y, const Color &color, int n) {
    auto nf = static_cast<float>(n);
    map[y * width_ + x] = {(map[y * width_ + x]._r * nf + color._r * 2 * static_cast<float>(M_PI)) / (nf + 1),
                           (map[y * width_ + x]._g * nf + color._g * 2 * static_cast<float>(M_PI)) / (nf + 1),
                           (map[y * width_ + x]._b * nf + color._b * 2 * static_cast<float>(M_PI)) / (nf + 1)};
}

[[maybe_unused]] void Image::get_max(unsigned int x, unsigned int y, const Color &color) {
    map[y * width_ + x]._r = std::max(map[y * width_ + x]._r, color._r);
    map[y * width_ + x]._g = std::max(map[y * width_ + x]._g, color._g);
    map[y * width_ + x]._b = std::max(map[y * width_ + x]._b, color._b);
}
