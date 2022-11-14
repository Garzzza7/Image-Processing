#include <iostream>
#include "CImg.h"
#include "Task1.h"

using namespace cimg_library;

float image_variances(CImg<unsigned char> &image){
   // CImg<unsigned char> buffer = image;

  return image.variance();

};

float image_mean(CImg<unsigned char> &image){
    // CImg<unsigned char> buffer = image;

    return image.mean();

};