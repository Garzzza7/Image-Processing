#include "CImg.h"
using namespace cimg_library;

int main() {
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp"); // create the image from a file (must exist in the working dir)
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() / 2; y++) { // only upper half of the image gets processed
            float valR = image(x, y, 0); // Read red value at coordinates (x, y)
            float valG = image(x, y, 1); // Read green value at coordinates (x, y)
            float valB = image(x, y, 2); // Read blue value at coordinates (x, y)
            float avg = (valR + valG + valB) / 3; // Compute average pixel value (grey)
            image(x, y, 0) = avg;
            image(x, y, 1) = avg;
            image(x, y, 2) = avg;
        }
    }
    image.save_bmp("..\\..\\images\\out.bmp"); // save the modified image to a file
    return 0;
}