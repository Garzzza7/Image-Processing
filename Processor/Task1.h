

#ifndef MAIN_CPP_TASK1_H
#define MAIN_CPP_TASK1_H
#include "CImg.h"
using namespace cimg_library;





int median(CImg<unsigned char> &image1,int x,int y,int z);
int stage_A(int zxy, int zmed, int zmin, int zmax, int Sxy, int Smax);
int stage_B(int zxy, int zmed, int zmin, int zmax);
void horizontal_flip(CImg<unsigned char> &image);
void vertical_flip(CImg<unsigned char> &image);
void diagonal_flip(CImg<unsigned char> &image);
void shrink(CImg<unsigned char> &image,float multiplier);
void enlarge(CImg<unsigned char> &image,float multiplier);
void adaptive_median_filter(CImg<unsigned char> &image);   //  (--adaptive)
void arithmetic_mean_filter(CImg<unsigned char> &image,int constant);   //  (--amean).
void insertion_sort(int arr[], int n);
void brightness_modification(CImg<unsigned char> &image,int constant);
void contrast_modification(CImg<unsigned char> &image,int intensity);
void negative(CImg<unsigned char> &image);
float mean_square_error(CImg<unsigned char> &image1,CImg<unsigned char> &image2);
float peak_mean_square_error(CImg<unsigned char> &image1,CImg<unsigned char> &image2);
float signal_to_noise_ratio(CImg<unsigned char> &image1,CImg<unsigned char> &image2);
float peak_signal_to_noise_ratio(CImg<unsigned char> &image1,CImg<unsigned char> &image2);
float maximum_difference(CImg<unsigned char> &image1,CImg<unsigned char> &image2);
#endif //MAIN_CPP_TASK1_H


