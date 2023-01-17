//
// Created by aleks on 05/01/2023.
//
#include <complex>
#include <cmath>
#include <iostream>
#include <queue>
#include "CImg.h"
#include "Task1.h"
#include <math.h>

using namespace std;

void fast_FT(CImg<unsigned char> &image){

}

void slow_dicrete_DFT(CImg<unsigned char> &image){
    CImg<unsigned char> buffer=image;
    complex<long double> ii(0.0,1.0);
    int M=image.width();
    int N=image.height();
    std::complex<double> z1 = 1i * 1i;
    for(int x=1;x<M;x++){
        for(int y=1;y<N;y++){
            long double sum=0;
            complex<long double> com(0.0,0.0);
            for(int k=1;k<M;k++){
                for(int j=1;j<N;j++){
                  //  for(int z=0;z<3;z++){
                        complex<long double> complex1(cos(2*M_PI*(((k*x)/M + (j*y)/N))), sin(2*M_PI*(((k*x)/M) + (j*y)/N)));
                        //com+=(long double)image(k,j,z)* exp(-1i*(long double)2.0*(long double)M_PI*(long double)((k*x)/M + (j*y)/N));
                        sum+=(long double)image(k,j,0)/abs(complex1);
                        std::cout<<sum<<std::endl;
                       // std::cout<<"complex - "<<complex1<<" sum- "<<sum<<" M - "<<M<<" N - "<<N<<" x - "<<x<<" y - "<<y<<" k - "<<k<<" j - "<<j<<std::endl;
                        //real(com) +=(long double)image(k,j,z)/(long double)(cos(2*M_PI*((k*x)/M + (j*y)/N)));
                        //imag(com) +=(long double)image(k,j,z)/sin(2*M_PI*((k*x)/M + (j*y)/N));
                        //buffer=image(i,j,z)* exp(-sqrt(-1)*2*M_PI*(pow(i,2)/M + pow(j,2)/N));
                   //com+=(long double)image(k,j,z)*(complex1(2.0,4.0));

                        //std::cout<<com<<std::endl;
                  //  }
                }
            }
            buffer(x,y,0)=sum;
        }
    }
    buffer.save_bmp("..\\..\\images\\slow_dicrete_DFT.bmp");
}
void I_fast_FT(CImg<unsigned char> &image){

}
void slow_dicrete_IDFT(CImg<unsigned char> &image){
    CImg<unsigned char> buffer=image;
    const  complex<long double> ii(0.0,1.0);
    complex<long double> com(0.0,0.0);
    int M=image.width();
    int N=image.height();
    long double sum=0;
    for(int x=0;x<M;x++){
        for(int y=0;y<N;y++){
            for(int i=0;i<M;i++){
                for(int j=0;j<N;j++){
                    for(int z=0;z<3;z++){
                        com+=(long double)image(i,j,z)* exp(ii*(long double)2.0*(long double)M_PI*(long double)((i*x)/M + (j*y)/N));
                        //buffer=image(i,j,z)* exp(-sqrt(-1)*2*M_PI*(pow(i,2)/M + pow(j,2)/N));
                    }
                }
            }
            buffer(x,y,0)= abs(com)/(M*N);
        }
    }
    buffer.save_bmp("..\\..\\images\\slow_dicrete_IDFT.bmp");
}

void fft(std::vector<std::complex<double>> &arr, int n) {

    if (n == 1) return;

    std::vector<std::complex<double>> even(n/2);
    std::vector<std::complex<double>> odd(n/2);
    for (int i = 0; i < n/2; i++) {
        even[i] = arr[2*i];
        odd[i] = arr[2*i + 1];
    }
    fft(even, n/2);
    fft(odd, n/2);

    double theta = -2.0 * M_PI /(double)n;
    std::complex<double> v(1);
    std::complex<double> wn(cos(theta), sin(theta));
    for (int k = 0; k < n/2; k++) {
        arr[k] = even[k] + v * odd[k];
        arr[k + n/2] = even[k] - v * odd[k];
        v *= wn;
    }
}

std::vector<std::vector<std::complex<double>>> FFT(CImg<unsigned char> &image) {

    CImg<unsigned char> buffer=image;
    const int ROWS = (int)image.width();
    std::vector<std::vector<std::complex<double>>> img;
    img.resize(image.width());
    for(int i = 0; i < image.width(); i++){
        img[i].resize(image.height());
    }

    cimg_library::CImg<unsigned char>::iterator it;
    for(int i = 0; i < image.width(); i++){
        it = image.get_shared_channel(i).begin();
        for(int j = 0; j < image.height(); j++, ++it) {
            img[i][j] = std::complex<double>(*it,0);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        fft(img[i], ROWS);
    }

    std::vector<std::complex<double>> temp(ROWS);
    for (int j = 0; j < ROWS; j++) {
        for (int i = 0; i < ROWS; i++) {
            temp[i] = img[i][j];
        }
        fft(temp, ROWS);
        for (int i = 0; i < ROWS; i++) {
            img[i][j] = temp[i];
        }
    }
    return img;
}

void ifft(std::vector<std::complex<double>> &arr, int n) {
    if (n == 1) return;

    std::vector<std::complex<double>> even(n/2);
    std::vector<std::complex<double>> odd(n/2);
    for (int i = 0; i < n/2; i++) {
        even[i] = arr[2*i];
        odd[i] = arr[2*i + 1];
    }
    fft(even, n/2);
    fft(odd, n/2);

    double theta = 2.0 * M_PI /(double)n;
    std::complex<double> v(1);
    std::complex<double> wn(cos(theta), -sin(theta));
    for (int k = 0; k < n/2; k++) {
        arr[k] = even[k] + v * odd[k];
        arr[k + n/2] = even[k] - v * odd[k];
        v *= wn;
    }
}

std::vector<std::vector<std::complex<double>>> IFFT(CImg<unsigned char> &image) {

    const int ROWS = (int)image.width();
    std::vector<std::vector<std::complex<double>>> img;
    img.resize(image.width());
    for(int i = 0; i < image.width(); i++){
        img[i].resize(image.height());
    }

    cimg_library::CImg<unsigned char>::iterator it;
    for(int i = 0; i < image.width(); i++){
        it = image.get_shared_channel(i).begin();
        for(int j = 0; j < image.height(); j++, ++it) {
            img[i][j] = std::complex<double>(*it,0);
        }
    }
    for (int i = 0; i < ROWS; i++) {
        ifft(img[i], ROWS);
    }

    std::vector<std::complex<double>> temp(ROWS);
    for (int j = 0; j < ROWS; j++) {
        for (int i = 0; i < ROWS; i++) {
            temp[i] = img[i][j];
        }
        ifft(temp, ROWS);
        for (int i = 0; i < ROWS; i++) {
            img[i][j] = temp[i];
        }
    }

    return img;
}

//// Perform in-place FFT on the given complex array using the Cooley-Tukey algorithm
//void FFT(complex<double> *a, int n) {
//    // Base case: if n == 1, return
//    if (n == 1) return;
//
//    // Split the array into even and odd halves
//    complex<double> *a_even = new complex<double>[n/2];
//    complex<double> *a_odd = new complex<double>[n/2];
//    for (int i = 0; i < n/2; i++) {
//        a_even[i] = a[2*i];
//        a_odd[i] = a[2*i + 1];
//    }
//
//    // Recursively compute the FFT of the even and odd halves
//    FFT(a_even, n/2);
//    FFT(a_odd, n/2);
//
//    // Combine the results using the Cooley-Tukey algorithm
//    for (int k = 0; k < n/2; k++) {
//        complex<double> t = polar(1.0, -2 * M_PI * k / n) * a_odd[k];
//        a[k] = a_even[k] + t;
//        a[k + n/2] = a_even[k] - t;
//    }
//
//    // Clean up
//    delete[] a_even;
//    delete[] a_odd;
//}

// Perform in-place IFFT on the given complex array using the Cooley-Tukey algorithm
//void IFFT(complex<double> *a, int n) {
//    // Base case: if n == 1, return
//    if (n == 1) return;
//
//    // Split the array into even and odd halves
//    complex<double> *a_even = new complex<double>[n/2];
//    complex<double> *a_odd = new complex<double>[n/2];
//    for (int i = 0; i < n/2; i++) {
//        a_even[i] = a[2*i];
//        a_odd[i] = a[2*i + 1];
//    }
//
//    // Recursively compute the IFFT of the even and odd halves
//    IFFT(a_even, n/2);
//    IFFT(a_odd, n/2);
//
//    // Combine the results using the Cooley-Tukey algorithm
//    for (int k = 0; k < n/2; k++) {
//        complex<double> t = polar(1.0, 2 * M_PI * k / n) * a_odd[k];
//        a[k] = a_even[k] + t;
//        a[k + n/2] = a_even[k] - t;
//    }
//
//    // Clean up
//    delete[] a_even;
//    delete[] a_odd;
//}
// Apply a low-pass filter to the given image
void lowPassFilter(int *image, int width, int height) {
    // Allocate memory for the complex arrays
    complex<double> *fft_real = new complex<double>[width * height];
    complex<double> *fft_imag = new complex<double>[width * height];

    // Copy the image into the complex arrays
    for (int i = 0; i < width * height; i++) {
        fft_real[i] = image[i];
        fft_imag[i] = 0;
    }

    // Compute the FFT of the image
//    FFT(fft_real, width * height);
//    FFT(fft_imag, width * height);

    // Apply the low-pass filter by setting the high-frequency coefficients to zero
    int n = width * height;
    for (int i = n/2; i < n; i++) {
        fft_real[i] = 0;
        fft_imag[i] = 0;
    }

    // Compute the IFFT of the filtered FFT
//    IFFT(fft_real, n);
//    IFFT(fft_imag, n);

    // Copy the result back into the image array
    for (int i = 0; i < width * height; i++) {
        image[i] = (int)(fft_real[i].real() / n + 0.5);
    }

    // Clean up
    delete[] fft_real;
    delete[] fft_imag;
}
void highPassFilter(int *image, int width, int height) {
    // Allocate memory for the complex arrays
    complex<double> *fft_real = new complex<double>[width * height];
    complex<double> *fft_imag = new complex<double>[width * height];

    // Copy the image into the complex arrays
    for (int i = 0; i < width * height; i++) {
        fft_real[i] = image[i];
        fft_imag[i] = 0;
    }

    // Compute the FFT of the image
   // fft(fft_real, width * height);
   // fft(fft_imag, width * height);

    // Apply the high-pass filter by setting the low-frequency coefficients to zero
    int n = width * height;
    for (int i = 0; i < n/2; i++) {
        fft_real[i] = 0;
        fft_imag[i] = 0;
    }

    // Compute the IFFT of the filtered FFT
//    IFFT(fft_real, n);
//    IFFT(fft_imag, n);

    // Copy the result back into the image array
    for (int i = 0; i < width * height; i++) {
        image[i] = (int)(fft_real[i].real() / n + 0.5);
    }

    // Clean up
    delete[] fft_real;
    delete[] fft_imag;
}