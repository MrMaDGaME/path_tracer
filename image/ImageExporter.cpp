#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"
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

void ImageExporter::exportToPng(const Image &image, const std::string &path) {
    int width = image.getWidth();
    int height = image.getHeight();
    const auto &map = image.getMap();

    // Créer un vecteur pour stocker les données de l'image au format RGBA.
    std::vector<unsigned char> pngData(width * height * 3);

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            auto r = map[j * width + i].getR();
            auto g = map[j * width + i].getG();
            auto b = map[j * width + i].getB();

            int index = (j * width + i) * 3;
            pngData[index] = static_cast<unsigned char>(r);
            pngData[index + 1] = static_cast<unsigned char>(g);
            pngData[index + 2] = static_cast<unsigned char>(b);
        }
    }

    // Utiliser stb_image_write pour écrire le fichier PNG.
    if (!stbi_write_png(path.c_str(), width, height, 3, pngData.data(), width * 3)) {
        throw std::runtime_error("Erreur lors de l'exportation de l'image en PNG");
    }
}
