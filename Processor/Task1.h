

#ifndef MAIN_CPP_TASK1_H
#define MAIN_CPP_TASK1_H

#include <complex>
#include "CImg.h"
#include "vector"
#include <cmath>
using namespace cimg_library;
using namespace std;
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

void min_filter(CImg<unsigned char> &image,int constant);
void min_filter_test(CImg<unsigned char> &image);


float image_variance(CImg<unsigned char> &image, int channel);
float image_mean(CImg<unsigned char> &image, int channel);
float standard_devation(CImg<unsigned char> &image, int channel);
float variation_coefficient_I(CImg<unsigned char> &image, int channel);
float asymmetry_coefficient(CImg<unsigned char> &image, int channel);
float flattening_coefficient(CImg<unsigned char> &image, int channel);
float variation_coefficient_II(CImg<unsigned char> &image, int channel);
float information_source_entropy(CImg<unsigned char> &image, int channel);

void histogram(CImg<unsigned char> &image,int a);
void power_two_third_final_probability_density_function(CImg<unsigned char> &image,int a,int maximum,int minimmum);
void kirsh_operator(CImg<unsigned char> &image);
void edge_sharpening(CImg<unsigned char> &image,int mask_size);
void optimized_edge_sharpening(CImg<unsigned char> &image);


void dilation(CImg<unsigned char> &image);
void erosion(CImg<unsigned char> &image);
void opening(CImg<unsigned char> &image);
void closing(CImg<unsigned char> &image);
void HMT(CImg<unsigned char> &image,int mask_size);

CImg<unsigned char> HTM(CImg<unsigned char> &image,int mask[3][3]);

void m6(CImg<unsigned char> &image);
void region_growing(CImg<unsigned char> &image,int x, int y,int threshold);



void fast_dicrete_DFT(CImg<unsigned char> &image);
void slow_dicrete_DFT(CImg<unsigned char> &image);
void fast_dicrete_IDFT(CImg<unsigned char> &image);
void slow_dicrete_IDFT(CImg<unsigned char> &image);
void I_fast_FT(CImg<unsigned char> &image);
void fast_FT(CImg<unsigned char> &image);
void fft(std::vector<std::complex<double>> &arr, int n);
void FFT(CImg<unsigned char> &image);
void ifft(std::vector<std::complex<double>> &arr, int n);
void IFFT(CImg<unsigned char> &image);

vector<complex<double>> ApplyFft1D (vector<complex<double>> input);
vector<vector<complex<double>>> ApplyFft(CImg<double> image);
vector<complex<double>> ApplyInverseFft1D (vector<complex<double>> input);
CImg<double> ApplyInverseFft(CImg<double> image);
CImg<double> ApplyInverseFft(vector<vector<complex<double>>> fourierTransformComplexNumbers);
CImg<double> ApplyLowPassFilter(CImg<double> image, int threshold, bool preservePhase);
CImg<double> ApplyHighPassFilter(CImg<double> image, int threshold, bool preservePhase);
CImg<double> ApplyBandPassFilter(CImg<double> image, int minThreshold, int maxThreshold, bool preservePhase);
CImg<double> ApplyBandCutFilter(CImg<double> image, int minThreshold, int maxThreshold, bool preservePhase);
CImg<double> ApplyHighPassEdgeDetectionFilter(CImg<double> image, CImg<double> mask, int threshold, bool preservePhase);
CImg<double> ApplyPhaseModifying(CImg<double> lol, double k, double l);


void mask_maker(int width, int height, double circleRadius, double angl, double rotationAngle);
#endif //MAIN_CPP_TASK1_H


