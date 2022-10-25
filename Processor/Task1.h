

#ifndef MAIN_CPP_TASK1_H
#define MAIN_CPP_TASK1_H
#include "CImg.h"
using namespace cimg_library;





int median(CImg<unsigned char> &image1,int x,int y,int z);
int stage_A(int zxy, int zmed, int zmin, int zmax, int Sxy, int Smax);
int stage_B(int zxy, int zmed, int zmin, int zmax);
void horizontal_flip();
void vertical_flip();
void diagonal_flip();
void shrink(float multiplier);
void enlarge(float multiplier);
void adaptive_median_filter(const char*name1,const char*name2);   //  (--adaptive)
void arithmetic_mean_filter();   //  (--amean).
void insertion_sort(int arr[], int n);
void brightness_modification(int constant);
void contrast_modification(int intensity);
void negative();
float mean_square_error();
float peak_mean_square_error();//why nan lol
float signal_to_noise_ratio();
float peak_signal_to_noise_ratio();
float maximum_difference();
#endif //MAIN_CPP_TASK1_H


