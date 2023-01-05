//
// Created by aleks on 05/01/2023.
//
#include <complex>
#include <cmath>

using namespace std;

// Perform in-place FFT on the given complex array using the Cooley-Tukey algorithm
void FFT(complex<double> *a, int n) {
    // Base case: if n == 1, return
    if (n == 1) return;

    // Split the array into even and odd halves
    complex<double> *a_even = new complex<double>[n/2];
    complex<double> *a_odd = new complex<double>[n/2];
    for (int i = 0; i < n/2; i++) {
        a_even[i] = a[2*i];
        a_odd[i] = a[2*i + 1];
    }

    // Recursively compute the FFT of the even and odd halves
    FFT(a_even, n/2);
    FFT(a_odd, n/2);

    // Combine the results using the Cooley-Tukey algorithm
    for (int k = 0; k < n/2; k++) {
        complex<double> t = polar(1.0, -2 * M_PI * k / n) * a_odd[k];
        a[k] = a_even[k] + t;
        a[k + n/2] = a_even[k] - t;
    }

    // Clean up
    delete[] a_even;
    delete[] a_odd;
}

// Perform in-place IFFT on the given complex array using the Cooley-Tukey algorithm
void IFFT(complex<double> *a, int n) {
    // Base case: if n == 1, return
    if (n == 1) return;

    // Split the array into even and odd halves
    complex<double> *a_even = new complex<double>[n/2];
    complex<double> *a_odd = new complex<double>[n/2];
    for (int i = 0; i < n/2; i++) {
        a_even[i] = a[2*i];
        a_odd[i] = a[2*i + 1];
    }

    // Recursively compute the IFFT of the even and odd halves
    IFFT(a_even, n/2);
    IFFT(a_odd, n/2);

    // Combine the results using the Cooley-Tukey algorithm
    for (int k = 0; k < n/2; k++) {
        complex<double> t = polar(1.0, 2 * M_PI * k / n) * a_odd[k];
        a[k] = a_even[k] + t;
        a[k + n/2] = a_even[k] - t;
    }

    // Clean up
    delete[] a_even;
    delete[] a_odd;
}
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
    FFT(fft_real, width * height);
    FFT(fft_imag, width * height);

    // Apply the low-pass filter by setting the high-frequency coefficients to zero
    int n = width * height;
    for (int i = n/2; i < n; i++) {
        fft_real[i] = 0;
        fft_imag[i] = 0;
    }

    // Compute the IFFT of the filtered FFT
    IFFT(fft_real, n);
    IFFT(fft_imag, n);

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
    FFT(fft_real, width * height);
    FFT(fft_imag, width * height);

    // Apply the high-pass filter by setting the low-frequency coefficients to zero
    int n = width * height;
    for (int i = 0; i < n/2; i++) {
        fft_real[i] = 0;
        fft_imag[i] = 0;
    }

    // Compute the IFFT of the filtered FFT
    IFFT(fft_real, n);
    IFFT(fft_imag, n);

    // Copy the result back into the image array
    for (int i = 0; i < width * height; i++) {
        image[i] = (int)(fft_real[i].real() / n + 0.5);
    }

    // Clean up
    delete[] fft_real;
    delete[] fft_imag;
}