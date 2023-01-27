#include <iostream>
#include <algorithm>
#include "CImg.h"
#include "Task1.h"
#include "vector"
#include "popl.hpp"
#include <iterator>
#include <list>
using namespace cimg_library;
using namespace popl;
using namespace std;
class Complex {
    double real, img;
public:
    Complex() {
        real = 0; img = 0;
    }
    Complex(double r, double i) {
        real = r; img = i;
    }
    void setReal(double real){
        real = real;
    }
    void setImaginary(double imaginary){
        img = imaginary;
    }
    double getReal(){
        return real;
    }
    double getImaginary(){
        return img;
    }
    Complex add(Complex c1, Complex c2){
        Complex res;
         res.real = c1.real + c2.real;//addition for real part
         res.img = c1.img + c2.img;//addition for imaginary part
         return res;//the result after addition
    }
    Complex sub(Complex c1, Complex c2){
        Complex res;
         res.real = c1.real - c2.real;//subtraction for real part
         res.img = c1.img - c2.img;//subtraction for imaginary part
         return res;//the result after subtraction
    }
    Complex operator*(Complex& a)
    {
        Complex number;
        double RP = real * a.getReal() - img * a.getImaginary();
        double IP = real * a.getReal() + img * a.getImaginary();
        number.setReal(RP);
        number.setImaginary(IP);
        return number;
    }
    Complex operator+(Complex& a)
    {
        Complex number;
        double RP = real + a.getReal();
        double IP = img + a.getImaginary();
        number.setReal(RP);
        number.setImaginary(IP);
        return number;
    }
    Complex operator-(Complex& a)
    {
        Complex number;
        double RP = real - a.getReal();
        double IP = img - a.getImaginary();
        number.setReal(RP);
        number.setImaginary(IP);
        return number;
    }
};
double clamp(double value,double bottom,double top){
    if(value>top){
        return top;
    }else if(value<bottom){
        return bottom;
    }else return value;
}
CImg<double> ApplyFourierSpectrumVisualization(vector<vector<complex<double>>> complexNumbers)
{
    CImg<double>visualisedBitmap(complexNumbers[0].size(),complexNumbers.size(),1,1,0);
    for (int x = 0; x < complexNumbers[0].size(); x++)
    {
        for (int y = 0; y < complexNumbers.size(); y++)
        {
            int calculatedColor = (int) clamp(log(abs(abs(complexNumbers[y][x])))*13,0,255);
            visualisedBitmap(x,y)=calculatedColor;
        }
    }
    visualisedBitmap.rotate(90.0,1,0);
    visualisedBitmap.mirror('y');
    return visualisedBitmap;
}

vector<vector<complex<double>>> ApplyQuartersSwap(vector<vector<complex<double>>> complexNumbers){
    vector<vector<complex<double>>> complexNumbersResult;
    for (int x = 0; x < complexNumbers.size(); x++)
    {
        vector<complex<double>> columns;

        for (int y = 0; y < complexNumbers[0].size(); y++)
        {
            columns.push_back(complexNumbers[x][y]);
        }

        complexNumbersResult.push_back(columns);
    }
    for (int x = 0; x < complexNumbers.size() / 2; x++)
    {
        for (int y = 0; y < complexNumbers[0].size() / 2; y++)
        {
            complex<double> temp(complexNumbersResult[x][y].real(),complexNumbersResult[x][y].imag());
            complexNumbersResult[x][y] = complexNumbersResult[complexNumbers.size() / 2 + x][complexNumbers[0].size() / 2 + y];
            complexNumbersResult[complexNumbers.size() / 2 + x][complexNumbers[0].size() / 2 + y] = temp;

            complex<double> temp1(complexNumbersResult[complexNumbers.size() / 2 + x][y].real(), complexNumbersResult[complexNumbers.size() / 2 + x][y].imag());

            complexNumbersResult[complexNumbers.size() / 2 + x][y] = complexNumbersResult[x][complexNumbers[0].size() / 2 + y];
            complexNumbersResult[x][complexNumbers[0].size() / 2 + y] = temp1;
        }
    }

    return complexNumbersResult;
}
void DFT2Dxd(CImg<double> &image) {
    int width = image.width();
    int height = image.height();
    CImg<complex<double>> dft_image(width, height);
    for (int u = 0; u < width; u++) {
        for (int v = 0; v < height; v++) {
            complex<double> sum(0, 0);
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    double angle = -2 * M_PI * (u * x / (double)width + v * y / (double)height);
                    sum += (double)image(x, y) * polar(1.0, angle);
                }
            }
            dft_image(u, v) = sum;
        }
    }
    CImg<double> magnitude_image(width, height,1,1,0);
    /*
    cimg_forXY(dft_image, x, y) {
           // (int) clamp(log(abs(abs(complexNumbers[y][x])))*13,0,255);
            magnitude_image(x, y) = (int)clamp(log(abs(abs(dft_image(x, y))))*20+5,0,255);
        }
        */
    magnitude_image.save_bmp("..\\..\\images\\w3333333.bmp");
}
void dft2d(CImg<double> image) {
        int width = image.width(), height = image.height();
        double r = 0;
        double im = 0;
        std::vector<std::vector<std::complex<double>>> img(image.height(),std::vector<std::complex<double>>(image.width()));
        CImg<double> dft(width, height, 1, 1, 0);
        CImg<double> buffer(width, height, 1, 1, 0);
        for(int i=0;i<image.width();i++){
        for(int j=0;j<image.width();j++){
            for(int u=0;u<image.width();u++){
                for(int v=0;v<image.width();v++){
                    double angle=-2.0*M_PI*(u*i)/image.width() - 2.0*M_PI*(v*j)/image.width();
                    r += image(u, v) * cos(angle);
                    im += image(u, v) * sin(angle);
                }
            }
            buffer(i,j)=(int)clamp(log(sqrt(pow(r,2)+pow(im,2))),0,255);
        }
    }
    /*
    cimg_forXY(image, x, y) {
            double real = 0, imag = 0;
            cimg_forXY(image, u, v) {
                    double angle = -2 * M_PI * (x * u / width + y * v / height);
                    real += image(u, v) * cos(angle);
                    imag += image(u, v) * sin(angle);
                }
            dft(x, y) = sqrt(real * real + imag * imag);
        }
    dft.save_bmp("..\\..\\images\\dft2d3.bmp");
     */
    buffer.save_bmp("..\\..\\images\\qqqqqqqqqqqqqqqqqqqq.bmp");
}

void fft1d(std::vector<std::complex<double>> &arr, int n) {

    if (n == 1) return;

    std::vector<std::complex<double>> even(n/2);
    std::vector<std::complex<double>> odd(n/2);
    for (int i = 0; i < n/2; i++) {
        even[i] = arr[2*i];
        odd[i] = arr[2*i + 1];
    }
    fft1d(even, n/2);
    fft1d(odd, n/2);

    double theta = -2.0 * M_PI /(double)n;
    std::complex<double> v(1);
    std::complex<double> wn(cos(theta), sin(theta));
    for (int k = 0; k < n/2; k++) {
        arr[k] = even[k] + v * odd[k];
        arr[k + n/2] = even[k] - v * odd[k];
        v *= wn;
    }
}
void ifft1d(std::vector<std::complex<double>> &arr, int n) {
    if (n == 1) return;

    std::vector<std::complex<double>> even(n/2);
    std::vector<std::complex<double>> odd(n/2);
    for (int i = 0; i < n/2; i++) {
        even[i] = arr[2*i];
        odd[i] = arr[2*i + 1];
    }
    fft1d(even, n/2);
    fft1d(odd, n/2);

    double theta = 2.0 * M_PI /(double)n;
    std::complex<double> v(1);
    std::complex<double> wn(cos(theta), -sin(theta));
    for (int k = 0; k < n/2; k++) {
        arr[k] = even[k] + v * odd[k];
        arr[k + n/2] = even[k] - v * odd[k];
        v *= wn;
    }
}


void FFT2D(CImg<unsigned char> &image) {

    const int ROWS = (int)image.width();

    CImg<unsigned char> buffer(image.width(),image.height(),1,1,0);

    std::vector<std::vector<std::complex<double>>> img(image.height(),std::vector<std::complex<double>>(image.width()));
    //std::vector<std::vector<std::complex<double>>> column_buffer(image.height(), std::vector<std::complex<double>>(image.width()));
    //std::vector<std::vector<std::complex<double>>> output(image.height(),std::vector<std::complex<double>>(image.width()));


    cimg_forXY(image, x, y) {
            img[x][y] = std::complex<double>(image(x, y), 0);
        }

    for (int i = 0; i < ROWS; i++) {
        fft1d(img[i], ROWS);
    }

    std::vector<std::complex<double>> temp(ROWS);
    for (int j = 0; j < ROWS; j++) {
        for (int i = 0; i < ROWS; i++) {
            temp[i] = img[i][j];
        }
        fft1d(temp, ROWS);
        for (int i = 0; i < ROWS; i++) {
            img[i][j] = temp[i];
        }
    }
    /*
    for (int i = 0; i < image.height(); i++)
    {

        vector<complex<double>> v(image.height());
        for(int j = 0; j < image.height(); j++)
        {
            v[j] = img[j][i];
        }

        fft1d(v, image.height());

        for(int z = 0; z < image.height(); z++)
        {
            column_buffer[z][i] = v[z];
        }
    }

    for(int i = 0; i < image.width(); i++)
    {
        vector<complex<double>> v(image.height());
        for(int j = 0; j < image.width(); j++)
        {
            v[j] = column_buffer[i][j];
        }
        fft1d(v, image.width());
        for(int z = 0; z < image.width(); z++)
        {
            output[i][z] = v[z];
        }
    }
     */
        for(int i=0;i<image.width();i++){
            for(int j=0;j<image.height();j++){
                buffer(i,j)=log(sqrt(img[i][j].real()*img[i][j].real()+img[i][j].imag()*img[i][j].imag())*20+5);
            }
        }
    buffer.save_bmp("..\\..\\images\\FFTnew1.bmp");
   // return img;
}
















pair<vector<vector<complex<double>>> , CImg<double>> ApplyDft(CImg<double> &image){
    //vector<vector<complex<double>>> complexNumbers1;
   // vector<vector<complex<double>>> complexNumbers2;
    complex<double> complexNumbers1[image.height()][image.width()];
    complex<double> complexNumbers2[image.height()][image.width()];
    vector<vector<complex<double>>> output;
    for (int a = 0; a < image.height(); a++){
        for (int k = 0; k < image.width(); k++){
            complex<double> sum(0.0, 0.0);

            for (int n = 0; n < image.width(); n++){
                complex<double> W(cos(2 * M_PI * n * k / image.width()),(-1) * sin(2 * M_PI * n * k / image.width()));

                sum += image(n, a) * W;
            }

            complexNumbers1[a][k] = sum;
        }
    }
    for (int b = 0; b < image.width(); b++){
        for (int k = 0; k < image.height(); k++){
            complex<double> sum(0, 0);

            for (int n = 0; n < image.height(); n++){
                complex<double> W(cos(2 * M_PI * n * k / image.height()),
                        (-1) * sin(2 * M_PI * n * k / image.height()));

                sum += complexNumbers1[n][b] * W;
            }

            complexNumbers2[k][b] = sum;
        }
    }
    for (int row = 0; row < 300; row++){
        vector<complex<double>> rowList;

        for (int column = 0; column < 300; column++){
            rowList.push_back(complexNumbers2[row][column]);
        }
        output.push_back(rowList);
    }
    vector<vector<complex<double>>> a= ApplyQuartersSwap(output);
    CImg<double> w = ApplyFourierSpectrumVisualization(a);
    pair<vector<vector<complex<double>>> , CImg<double>> res(output,w);
    w.save_bmp("..\\..\\images\\DFTDFTDFDT.bmp");
    return res;

}

























vector<complex<double>> ApplyFft1D (vector<complex<double>> input){
    vector<complex<double>> outputResult;
    vector<complex<double>> oddComplexNumbers;
    vector<complex<double>> evenComplexNumbers;

    if (input.size() == 1){
        return input;
    }
    for (int i = 0; i < input.size() / 2; i++){
        oddComplexNumbers.push_back(input[2 * i + 1]);
        evenComplexNumbers.push_back(input[2 * i]);
    }
    oddComplexNumbers = ApplyFft1D(oddComplexNumbers);
    evenComplexNumbers = ApplyFft1D(evenComplexNumbers);
    for (int i = 0; i < input.size(); i++){
        outputResult.push_back(-100);
    }
    for (int i = 0; i < input.size() / 2; i++){
        complex<double> number(cos(2*M_PI*i/input.size()),(-1)* sin(2*M_PI*i/input.size()));
        outputResult[i] = evenComplexNumbers[i] + number * oddComplexNumbers[i];
        outputResult[i + input.size() / 2] = evenComplexNumbers[i] - number * oddComplexNumbers[i];
    }
    return outputResult;
}
CImg<double> vertical_flip(CImg<double> &image){
    CImg<double> buffer = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            buffer(x, y) = image(x, image.height()-y);
        }
    }
    //image = buffer;
    return buffer;
}
vector<vector<complex<double>>> ApplyFft(CImg<double> image){
    vector<vector<complex<double>>> complexNumbers1;
    vector<vector<complex<double>>> complexNumbers2;

    for(int a=0;a<image.height();a++){
        vector<complex<double>> rows;
        for(int x=0;x<image.width();x++){
            rows.push_back(image(x,a));
        }
        complexNumbers2.push_back(ApplyFft1D(rows));
    }
    for(int a=0;a<image.width();a++){
        vector<complex<double>> columns;
        for(int x=0;x<image.height();x++){
            columns.push_back(complexNumbers2[x][a]);
        }
        complexNumbers1.push_back(ApplyFft1D(columns));
    }
    vector<vector<complex<double>>> swappedQuarters= ApplyQuartersSwap(complexNumbers1);
    CImg<double> lol= ApplyFourierSpectrumVisualization(swappedQuarters);
    //lol.save_bmp("..\\..\\images\\mozetotakdziala.bmp");
    return complexNumbers1;
}

///////////////////////////////////////////////////////////////
vector<complex<double>> ApplyInverseFft1D (vector<complex<double>> input){
    vector<complex<double>> outputResult;
    vector<complex<double>> oddComplexNumbers;
    vector<complex<double>> evenComplexNumbers;

    if (input.size() == 1){
        return input;
    }
    for (int i = 0; i < input.size() / 2; i++){
        oddComplexNumbers.push_back(input[2 * i + 1]);
        evenComplexNumbers.push_back(input[2 * i]);
    }
    oddComplexNumbers = ApplyInverseFft1D(oddComplexNumbers);
    evenComplexNumbers = ApplyInverseFft1D(evenComplexNumbers);
    for (int i = 0; i < input.size(); i++){
        outputResult.push_back(-100);
    }
    for (int i = 0; i < input.size() / 2; i++){
        complex<double> number(cos(2*(double)M_PI*(double)i/(double)input.size()),sin(2*(double)M_PI*(double)i/(double)input.size()));
        outputResult[i] = evenComplexNumbers[i] + number * oddComplexNumbers[i];
        outputResult[i + input.size() / 2] = evenComplexNumbers[i] - number * oddComplexNumbers[i];
    }
    return outputResult;

}
CImg<double> ApplyInverseFft(CImg<double> image) {
    vector<vector<complex<double>>> fourierTransformComplexNumbers= ApplyFft(image);
    CImg<double> buffer(image.width(), image.height(),1,1,0);
    vector<vector<complex<double>>> complexNumbers;

    for (int x = 0; x < buffer.height(); x++) {
        complexNumbers.push_back(vector<complex<double>>());
    }

    for (int y = 0; y < buffer.height(); y++) {
        vector<complex<double>> rows;

        for (int x = 0; x < buffer.width(); x++) {
            rows.push_back(fourierTransformComplexNumbers[y][x]);
        }

        rows = ApplyInverseFft1D(rows);

        for (int x = 0; x < buffer.width(); x++) {
            complexNumbers[y].push_back(rows[x] / (double)buffer.width());
        }
    }

    for (int x = 0; x < buffer.width(); x++) {
        vector<complex<double>> columns;

        for (int y = 0; y < buffer.width(); y++) {
            columns.push_back(complexNumbers[y][x]);
        }

        columns = ApplyInverseFft1D(columns);

        for (int y = 0; y < buffer.height(); y++) {
            int color = (int)clamp(abs(abs(columns[y]) / buffer.width()),0,255);
            buffer(x, y) = color;
        }
    }

    buffer.mirror('y');
    buffer.rotate(90);
   // buffer.save_bmp("..\\..\\images\\INVERSOOOO.bmp");
    return buffer;
}
CImg<double> ApplyInverseFft(vector<vector<complex<double>>> fourierTransformComplexNumbers) {
    //vector<vector<complex<double>>> fourierTransformComplexNumbers= ApplyFft(image);
    CImg<double> buffer(fourierTransformComplexNumbers[0].size(), fourierTransformComplexNumbers.size(),1,1,0);
    vector<vector<complex<double>>> complexNumbers;

    for (int x = 0; x < buffer.height(); x++) {
        complexNumbers.push_back(vector<complex<double>>());
    }

    for (int y = 0; y < buffer.height(); y++) {
        vector<complex<double>> rows;

        for (int x = 0; x < buffer.width(); x++) {
            rows.push_back(fourierTransformComplexNumbers[y][x]);
        }

        rows = ApplyInverseFft1D(rows);

        for (int x = 0; x < buffer.width(); x++) {
            complexNumbers[y].push_back(rows[x] / (double)buffer.width());
        }
    }

    for (int x = 0; x < buffer.width(); x++) {
        vector<complex<double>> columns;

        for (int y = 0; y < buffer.width(); y++) {
            columns.push_back(complexNumbers[y][x]);
        }

        columns = ApplyInverseFft1D(columns);

        for (int y = 0; y < buffer.height(); y++) {
            int color = (int)clamp(abs(abs(columns[y]) / buffer.width()),0,255);
            buffer(x, y) = color;
        }
    }

    buffer.mirror('y');
    buffer.rotate(90);
   // buffer.save_bmp("..\\..\\images\\lowpassfilter.bmp");
    return buffer;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

CImg<double> ApplyLowPassFilter(CImg<double> image, int threshold, bool preservePhase){

    vector<vector<complex<double>>> complexNumbers = ApplyFft(image);
    int width = complexNumbers.size();
    int height = complexNumbers[0].size();

    complexNumbers = ApplyQuartersSwap(complexNumbers);

    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            double distance = sqrt(pow((x - width / 2), 2)+pow((y - height / 2), 2));

            if (distance > threshold){
                if (preservePhase){
                    double phase = atan2(complexNumbers[x][y].imag(),complexNumbers[x][y].real());
                    complexNumbers[x][y] = complex<double>(0, phase);
                }
                else{
                    complexNumbers[x][y] = complex<double>(0, 0);
                }
            }
        }
    }

    if (preservePhase)
    {
        ApplyInverseFft(ApplyFourierSpectrumVisualization(complexNumbers)).save_bmp("..\\..\\images\\lowpassfilter_mask.bmp");
        return ApplyInverseFft(ApplyFourierSpectrumVisualization(complexNumbers));
    }
    ApplyInverseFft(complexNumbers).save_bmp("..\\..\\images\\lowpassfilter_image.bmp");
    return ApplyInverseFft(complexNumbers);
}







CImg<double> ApplyHighPassFilter(CImg<double> image, int threshold, bool preservePhase){
    vector<vector<complex<double>>> frequencyDomain = ApplyFft(image);
    int width = frequencyDomain.size();
    int height = frequencyDomain[0].size();
    complex<double> dc = frequencyDomain[width / 2][height / 2];
    frequencyDomain = ApplyQuartersSwap(frequencyDomain);
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            double distance = sqrt(pow((x - width / 2), 2) +pow((y - height / 2), 2));
            if (distance < threshold){
                if (preservePhase){
                    double phase = atan2(frequencyDomain[x][y].imag(),frequencyDomain[x][y].real());
                    frequencyDomain[x][y] = complex<double>(0, phase);
                }
                else{
                    frequencyDomain[x][y] = complex<double>(0, 0);
                }
            }
        }
    }
    frequencyDomain[width / 2][height / 2] = dc;
    if (preservePhase)
    {   ApplyInverseFft(ApplyFourierSpectrumVisualization(frequencyDomain)).save_bmp("..\\..\\images\\highpassfilter_mask.bmp");
        return ApplyInverseFft(ApplyFourierSpectrumVisualization(frequencyDomain));
    }
    ApplyInverseFft(frequencyDomain).save_bmp("..\\..\\images\\highpassfilter_image.bmp");
    return ApplyInverseFft(frequencyDomain);
}



CImg<double> ApplyBandPassFilter(CImg<double> image, int minThreshold, int maxThreshold, bool preservePhase){
    vector<vector<complex<double>>> frequencyDomain = ApplyFft(image);
    int width = frequencyDomain.size();
    int height = frequencyDomain[0].size();
    complex<double> dc = frequencyDomain[width / 2][height / 2];
    frequencyDomain = ApplyQuartersSwap(frequencyDomain);
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            double value = sqrt(pow(x - width / 2.0, 2) +pow(y - height / 2.0, 2));
            if ((value > maxThreshold) || (value < minThreshold)){
                if (preservePhase){
                    double phase = atan2(frequencyDomain[x][y].imag(),frequencyDomain[x][y].real());
                    frequencyDomain[x][y] = complex<double>(0, phase);
                }
                else{
                    frequencyDomain[x][y] = complex<double>(0, 0);
                }
            }
        }
    }
    frequencyDomain[width / 2][height / 2] = dc;
    if (preservePhase){
        ApplyInverseFft(ApplyFourierSpectrumVisualization(frequencyDomain)).save_bmp("..\\..\\images\\bandpassfilter_mask.bmp");
        return ApplyInverseFft(ApplyFourierSpectrumVisualization(frequencyDomain));
    }
    ApplyInverseFft(frequencyDomain).save_bmp("..\\..\\images\\bandpassfilter_image.bmp");
    return ApplyInverseFft(frequencyDomain);
}
CImg<double> ApplyBandCutFilter(CImg<double> image, int minThreshold, int maxThreshold, bool preservePhase){
    vector<vector<complex<double>>> frequencyDomain = ApplyFft(image);
    int width = frequencyDomain.size();
    int height = frequencyDomain[0].size();

    frequencyDomain = ApplyQuartersSwap(frequencyDomain);
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            double value = sqrt(pow(x - width / 2.0, 2) +pow(y - height / 2.0, 2));
            if ((value >= minThreshold) && (value <= maxThreshold))
            {
                if (preservePhase)
                {
                    double phase = atan2(frequencyDomain[x][y].imag(),frequencyDomain[x][y].real());
                    frequencyDomain[x][y] = complex<double>(0, phase);
                }
                else
                {
                    frequencyDomain[x][y] =complex<double>(0, 0);
                }
            }
        }
    }

    if (preservePhase)
    {
        ApplyInverseFft(ApplyFourierSpectrumVisualization(frequencyDomain)).save_bmp("..\\..\\images\\bandcutfilter_mask.bmp");
        return ApplyInverseFft(ApplyFourierSpectrumVisualization(frequencyDomain));
    }
    ApplyInverseFft(frequencyDomain).save_bmp("..\\..\\images\\bandcutfilter_image.bmp");
    return ApplyInverseFft(frequencyDomain);
}

CImg<double> ApplyHighPassEdgeDetectionFilter(CImg<double> image, CImg<double> mask, int threshold, bool preservePhase){
    vector<vector<complex<double>>> frequencyDomain = ApplyFft(image);
    int width = frequencyDomain.size();
    int height = frequencyDomain[0].size();
    complex<double> dc = frequencyDomain[width / 2][height / 2];
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            if (mask(x, y) == 0){
                if (preservePhase){
                    double phase = atan2(frequencyDomain[x][y].imag(),frequencyDomain[x][y].real());
                    frequencyDomain[x][y] = complex<double>(0, phase);
                }
                else{
                    frequencyDomain[x][y] =  complex<double>(0, 0);
                }
            }
            else if (sqrt(pow(x - width / 2.0, 2) +pow(y - height / 2.0, 2)) < threshold){
                if (preservePhase){
                    double phase = atan2(frequencyDomain[x][y].imag(),frequencyDomain[x][y].real());
                    frequencyDomain[x][y] = complex<double>(0, phase);
                }
                else{
                    frequencyDomain[x][y] = complex<double>(0, 0);
                }
            }
        }
    }
        frequencyDomain[width / 2][height / 2] = dc;
    if (preservePhase){
        CImg result = ApplyInverseFft(ApplyFourierSpectrumVisualization(frequencyDomain));
        result.rotate(90,1,0);
        result.save_bmp("..\\..\\images\\HighPassEdgeDetectionFilter_mask.bmp");
        return result;
    }
    ApplyInverseFft(frequencyDomain).save_bmp("..\\..\\images\\HighPassEdgeDetectionFilter_image.bmp");
    return ApplyInverseFft(frequencyDomain);
}
complex<double> ApplyPhaseMask(CImg<double> image, complex<double> number, double x, double y, double k, double l){
   // complex<double> j(0, 1);
    complex<double> result(cos(((-1) * (x * k * 2 * M_PI) / image.width()) + (-1) * (y * l * 2 * M_PI / image.height()) + (k + l) * M_PI),sin(((-1) * (x * k * 2 * M_PI) / image.width()) + (-1) * (y * l * 2 * M_PI / image.height()) + (k + l) * M_PI));
    //complex<double> result = exp(j * (((-1) * (x * k * 2 * M_PI) / image.width()) + (-1) * (y * l * 2 * M_PI / image.height()) + (k + l) * M_PI));
    return number * result;
}
CImg<double> ApplyPhaseModifying(CImg<double> lol, double k, double l){
    vector<vector<complex<double>>>  frequencyDomain = ApplyFft(lol);
   //vector<vector<complex<double>>> arr;
   int width = frequencyDomain.size();
   int height = frequencyDomain[0].size();
   //complex<double> arr[width][height];
   frequencyDomain = ApplyQuartersSwap(frequencyDomain);
   for (int x = 0; x < width; x++){
       for (int y = 0; y < height; y++){
           frequencyDomain[x][y] = ApplyPhaseMask(lol, frequencyDomain[x][y], x, y, k, l);
       }
   }
    ApplyInverseFft(frequencyDomain).save_bmp("..\\..\\images\\PhaseModifying.bmp");
    return ApplyInverseFft(frequencyDomain);
    return lol;
}
void mask_maker(double width, double height, double circleRadius, double angl, double rotationAngle){
    CImg<double> bmp(512,512,1,1,0);
    for(int x=0;x<width;++x) {
        for (int y = 0; y < height; ++y) {
            bmp(x, y) = 0;
        }
    }
    bool flag=false;
    if(rotationAngle>180){
        rotationAngle-=180;
        flag=true;
    }
    double to_rad= angl * M_PI / 180;
    double to_rad_rot= rotationAngle * M_PI / 180;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - width/2;
            int dy = y - height/2;
            double angle = atan2(dy, dx);
            //cout<<angle<<endl;
            double distance = sqrt(pow((dx), 2) +pow((dy), 2));
            if (angle >= 0+to_rad_rot && angle <= to_rad+to_rad_rot) {
                bmp(x, y) = 255;
            }
        }
    }


       for (int x = 0; x < width; x++){
           for (int y = 0; y < height; y++){
               double distance = sqrt(pow((x - width / 2), 2) +pow((y - height / 2), 2));
               if (distance < circleRadius){
                   bmp(x,y)=0;
               }
           }
       }
       if(flag){
           bmp.mirror('x');
       }

    //bmp.rotate(rotationAngle,1,0);
    bmp.save_bmp("..\\..\\images\\test_mask11.bmp");
}





void generateMask(int width,int height,int circleRadius,int angle,int rotationAngle){
    CImg<double> bmp(width,height);
    for(int x=0;x<width;x++){
        for(int y=0;y<height;y++){
            bmp(x,y)=0;
        }
    }
    int halfDistanceBetweenPoints = (int)(tan( (M_PI / 180) * angle / 2) * width / 2);
    pair<int,int> left2(0,height / 2 - halfDistanceBetweenPoints);
    pair<int,int> right1(width, height / 2 + halfDistanceBetweenPoints );
    pair<int,int> left1(0, height / 2 + halfDistanceBetweenPoints );
    pair<int,int> right2(width, height / 2 - halfDistanceBetweenPoints);
    double tanAlfa = round((double)(height / 2) / (width / 2));
    double tanBeta = round((double)(width / 2) / (height / 2));
    int alfaAngle = 0, betaAngle = 0;
    for (int x = 0; x < 90; x++)
    {
        if (round(tan((M_PI / 180) * x)) == tanAlfa)
        {
            alfaAngle = x;
        }

        if (round(tan((M_PI / 180) * x)) == tanBeta)
        {
            betaAngle = x;
        }
    }
    float verticalDistanceToChangeAngleByOne = ((float)height / 2)/ alfaAngle;
    float horizontalDistanceToChangeAngleByOne = ((float)width /2) / betaAngle;
    float verticalDistanceLeft = height/2 - halfDistanceBetweenPoints;
    float verticalRotation = (verticalDistanceLeft / verticalDistanceToChangeAngleByOne);
    if (rotationAngle < verticalRotation)
    {
        right1.second = (int)(right1.second + rotationAngle * verticalDistanceToChangeAngleByOne);
    }
    else if (rotationAngle > verticalRotation)
    {
        right1.second = (int)(right1.second + verticalRotation * verticalDistanceToChangeAngleByOne);
        float remainingRotationAngle = (rotationAngle - verticalRotation);

        // First right point horizontal repositioning
        right1.first = (int)(right1.first - remainingRotationAngle * horizontalDistanceToChangeAngleByOne);

    }
    // Second right point vertical repositioning
    verticalDistanceLeft = height / 2 + halfDistanceBetweenPoints;
    verticalRotation = (verticalDistanceLeft / verticalDistanceToChangeAngleByOne);

    if (rotationAngle < verticalRotation)
    {
        right2.second = (int)(right2.second + rotationAngle * verticalDistanceToChangeAngleByOne);
    }
    else if (rotationAngle > verticalRotation)
    {
        right2.second = (int)(right2.second + verticalRotation * verticalDistanceToChangeAngleByOne);
        float remainingRotationAngle = (rotationAngle - verticalRotation);

        // Second right point horizontal repositioning
        right2.second = (int)(right2.second - remainingRotationAngle * horizontalDistanceToChangeAngleByOne);
    }
    // First left point vertical repositioning
    verticalDistanceLeft = height / 2  + halfDistanceBetweenPoints;
    verticalRotation = (verticalDistanceLeft / verticalDistanceToChangeAngleByOne);

    if (rotationAngle < verticalRotation)
    {
        left1.second = (int)(left1.second - rotationAngle * verticalDistanceToChangeAngleByOne);
    }
    else if (rotationAngle > verticalRotation)
    {
        left1.second = (int)(left1.second - verticalRotation * verticalDistanceToChangeAngleByOne);
        float remainingRotationAngle = rotationAngle - verticalRotation;

        // First left point horizontal repositioning
        left1.first= (int)(left1.first + remainingRotationAngle * horizontalDistanceToChangeAngleByOne);
    }
    // Second left point vertical repositioning
    verticalDistanceLeft = height / 2  - halfDistanceBetweenPoints;
    verticalRotation = (verticalDistanceLeft / verticalDistanceToChangeAngleByOne);

    if (rotationAngle < verticalRotation)
    {
        left2.second = (int)(left2.second - rotationAngle * verticalDistanceToChangeAngleByOne);
    }
    else if (rotationAngle > verticalRotation)
    {
        left2.second = (int)(left2.second - verticalRotation * verticalDistanceToChangeAngleByOne);
        float remainingRotationAngle = rotationAngle - verticalRotation;

        // Second left point horizontal repositioning
        left2.first = (int)(left2.first + remainingRotationAngle * horizontalDistanceToChangeAngleByOne);
    }
    pair<int,int> fourthPoint(-1,-1);
    vector<pair<int,int>> firstShape;
    vector<pair<int,int>> secondShape;
    if (right1.second == right2.first && right1.first!= right2.first)
    {
        // In that case create 4th point to fill the resulting space
        if (right1.second == height && right2.first == width)
        {
            fourthPoint = pair<int,int>(width, height);
            firstShape = vector<pair<int,int>>{pair<int,int>(width/2,height/2),right1,fourthPoint,right2};
        }
        else if (right1.first == 0 && right2.second == height)
        {
            fourthPoint = pair<int,int>(0, height);
            firstShape = vector<pair<int,int>>{ pair<int,int>(width / 2, height / 2), right1, fourthPoint, right2};
        }
        else
        {
            firstShape = vector<pair<int,int>>{ pair<int,int>(width / 2, height / 2), right1, right2};
        }
        if (left2.second == 0 && left1.first == 0)
        {

            fourthPoint = pair<int,int>(0, 0);
            secondShape = vector<pair<int,int>>{ pair<int,int>(width / 2, height / 2), left1, fourthPoint, left2};
        }
        else
        {
            secondShape = vector<pair<int,int>> { pair<int,int>(width / 2, height / 2), left2, left1 };
        }

    }
    else
    {
        firstShape = vector<pair<int,int>>{ pair<int,int>(width / 2, height / 2), right1, right2 };
        secondShape = vector<pair<int,int>> { pair<int,int>(width / 2, height / 2), left2, left1 };
    }
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {

        }
    }
    bmp.save_bmp("..\\..\\images\\test_mask.bmp");

}


/*
vector<Complex> FFT1D(vector<Complex> input)
{
// Get the length of the input array
int n = input.size();

Complex I(0, 1);
// Check if the input has a length of 1
if (n == 1)
{
return input;
}

// Split the input into even and odd elements
Complex even[n / 2];
Complex odd[n / 2];

for (int i = 0; i < n; i++)
{
if (i % 2 == 0)
{
even[i / 2] = input[i];
}
else
{
odd[(i - 1) / 2] = input[i];
}
}
    vector<Complex> even1;
    vector<Complex> odd1;
    for (int i = 0; i < n/2; i++){
        even1.push_back(even[i]);
        odd1.push_back(odd[i]);
    }

// Compute the FFT of the even and odd elements
vector<Complex> evenFFT = FFT1D(even1);
vector<Complex> oddFFT = FFT1D(odd1);
double angle;
// Combine the FFT of the even and odd elements using the butterfly notation
Complex output[n];
    for (int i = 0; i < n / 2; i++){
        angle = -2.0 * (double)M_PI * (double)i / (double)n;

        double real = cos(angle);
        double imaginary = sin(angle);

        Complex W;
        W.setReal(real);
        W.setImaginary(imaginary);

        W = W * oddFFT[i];
        output[i]=evenFFT[i]+W;
        output[i + n / 2] =evenFFT[i]-W;
        /*
        Complex w = exp(-2 * I * M_PI * i / n);
        output[i] = evenFFT[i] + w * oddFFT[i];
        output[i + n / 2] = evenFFT[i] - w * oddFFT[i];
         */
  //  }
    /*
    vector<Complex> v;
    for(int i = 0; i < n; i++){
        v.push_back(output[i]);
    }

return v;
}
vector<vector<Complex>> FFT2D(CImg<unsigned char> &image){
int N = image.width();
int M = image.height();

Complex output[N][M];
Complex columnsFFT[N][M];
    vector<vector<Complex>> columnsFFT1;

Complex input[N][M];

//Convert the image to table of complex numbers
for (int i = 0; i < image.height(); i++)
{
for (int j = 0; j < image.width(); j++)
{
input[i][j] = (Complex &) image(j, i, 0);
}
}

//Perform FFT over the columns of the input
for (int i = 0; i < M; i++)
{
//Put all the values from i'th column in the tempColumn variable
Complex tempColumn[N];
    vector<Complex> tempColumn1;
for(int j = 0; j < N; j++)
{
    tempColumn1.push_back((Complex &) image(j, i, 0));
    //tempColumn[j] = (Complex &) image(i, j, 0);
}
//Calculate the FFT of i'th column
tempColumn1 = FFT1D(tempColumn1);
//Assign the column to columnsFFT, after calculating its FFT
for(int z = 0; z < N; z++)
{
columnsFFT[z][i] = tempColumn1[z];
}
}

//Perform FFT over the rows of the columnsFFT
for(int i = 0; i < N; i++)
{
//Put the values from i'th row in tempRow, so we can perform the FFT on its entirety
vector<Complex> tempRow;
for(int j = 0; j < M; j++)
{
tempRow.push_back(columnsFFT[i][j]);
}
//Calculate the FFT on tempRow
tempRow = FFT1D(tempRow);
//Assign the tempRow to the output
for(int z = 0; z < M; z++)
{
output[i][z] = tempRow[z];
}


}
    vector<vector<Complex>> result;
    for(int p = 0; p <N; p++)
    {  // vector<Complex> lol;
        for(int c = 0; c < M; c++)
        {
            result[p].push_back(output[p][c]);
        }
        // result[p].push_back(lol);
    }
return result;
}
void RepresentFFTAsImage(vector<vector<Complex>> fft)
{
    int width = fft[0].size();
    int height = fft[1].size();
CImg<unsigned char>buffer;
int pixel;
for (int i = 0; i < height; i++)
{
for (int j = 0; j < width; j++)
{
pixel = (int)sqrt(pow(fft[i][j].getReal(),2)+pow(fft[i][j].getImaginary(),2));
//pixel = Clamp((int)Math.Log(pixel, 1.07));
buffer(i,j,0)=pixel;
}
}

buffer.save_bmp("dC:\\Users\\piotr\\CLionProjects\\Image-Processing-final2\\images\\lol.bmp");
}
*/
int main(int argc,char **argv) {
/*
    OptionParser op("Allowed options");
    auto help_command = op.add<Switch>("", "help", "produce help message");
    auto brightness_command = op.add<Value<int>>("", "brightness", "brightness modification");
    auto contrast_command = op.add<Value<int>>("", "contrast", "contrast modification");
    auto negative_command = op.add<Switch>("", "negative", "turn image into negative");

    auto horizontal_flip_command = op.add<Switch>("", "hflip", "Horizontal flip");
    auto vertica_flip_command = op.add<Switch>("", "vflip", "Vertical fli");
    auto diagonal_flip_command = op.add<Switch>("", "dflip", "Diagonal flip");
    auto image_shrink_command = op.add<Value<float>>("", "shrink", "Image shrinking");
    auto image_enlarge_command = op.add<Value<float>>("", "enlarge", "Image enlargement");


    auto adaptive_median_filter_command=op.add<Switch>("", "adaptive", "Adaptive median filter");
    auto arithmetic_mean_filter_command=op.add<Value<int>>("", "amean", "Arithmetic mean filter");

    auto mean_square_error_option = op.add<Switch>("", "mse", "Mean square error");
    auto peak_mean_square_error_option = op.add<Switch>("", "pmse", "Peak mean square error");
    auto signal_to_noise_ratio_option = op.add<Switch>("", "snr", "Signal to noise ratio");
    auto peak_signal_to_noise_ratio_option = op.add<Switch>("", "psnr", "Peak signal to noise ratio");
    auto maximum_difference_option = op.add<Switch>("", "md", "Maximum difference");

    auto image_mean_option = op.add<Value<int>>("", "cmean", "Mean");
    auto image_variance_option = op.add<Value<int>>("", "cvariance", "Variance");
    auto standard_devation_option = op.add<Value<int>>("", "cstdev", "Standard deviation");
    auto variation_coefficient_I_option = op.add<Value<int>>("", "cvarcoi", "Variation coefficient I");
    auto asymmetry_coefficient_option = op.add<Value<int>>("", "casyco", "Asymmetry coefficient");
    auto flattening_coefficient_option = op.add<Value<int>>("", "cflaco", "Flattening coefficient");
    auto variation_coefficient_II_option = op.add<Value<int>>("", "cvarcoii", "Variation coefficient II");
    auto information_source_entropy_option = op.add<Value<int>>("", "centropy", "Information source entropy");

    auto histogram_option  = op.add<Value<int>>("", "histogram", "Histogram");
    auto power_two_third_final_probability_density_function_option = op.add<Value<int>>("", "hpower", "Power 2/3 final probability density function");
    auto kirsh_operator_option = op.add<Switch>("", "okirsf", "Kirsh operator");
    auto edge_sharpening_option = op.add<Value<int>>("", "sedgesharp", "Edge sharpening");
    auto optimized_edge_sharpening_option = op.add<Switch>("", "optsedgesharp", "Optimized edge sharpening");

    auto dilation_option = op.add<Switch>("", "dilation", "Dilation");
    auto erosion_option = op.add<Switch>("", "erosion", "Erosion");
    auto opening_option = op.add<Switch>("", "opening", "Opening");
    auto closing_option = op.add<Switch>("", "closing", "Closing");
    auto HMT_option = op.add<Value<int>>("", "hmt", "HMT transformation");
    auto m6_option = op.add<Switch>("", "m6", "M6 variant");
    auto region_growing_option = op.add<Switch>("", "rgrowing", "Region growing");
    auto FFT_option = op.add<Switch>("", "fft", "FFT");
    auto IFFT_option = op.add<Switch>("", "ifft", "IFFT");

    op.parse(argc, argv);
    // for (const auto& non_option_arg: op.non_option_args())cout << "This argument is not valid: " << non_option_arg <<" Make sure you pick an existing image"<< endl;

    // show unknown options (undefined ones, like "-u" or "--undefined")
    for (const auto& unknown_option: op.unknown_options())cout << "This operation is not valid: " << unknown_option <<" Try --help for a list of commands"<<endl;
    //Auto-generated help message
    if (help_command->is_set())cout << op << endl;
    else {
        try{

            CImg<unsigned char> Image;
            CImg<unsigned char> Image_for_testing;
            char* result;


            // const char *const image = argv[1];
            // const char *const image_for_testing = argv[2];



            try{

                if(image_shrink_command->is_set() || image_enlarge_command->is_set() || contrast_command->is_set() || brightness_command->is_set() || arithmetic_mean_filter_command->is_set() || image_mean_option->is_set() || image_variance_option->is_set() || standard_devation_option->is_set() || variation_coefficient_I_option->is_set() || asymmetry_coefficient_option->is_set() || flattening_coefficient_option->is_set() || variation_coefficient_II_option->is_set() || information_source_entropy_option->is_set() || histogram_option->is_set() || power_two_third_final_probability_density_function_option->is_set() || edge_sharpening_option->is_set()){
                    Image = CImg(argv[3]);
                    result=argv[4];
                }else{
                    Image = CImg(argv[2]);
                    result=argv[3];
                }


                // if(Image==NULL){}
                // Image = CImg(image);
            }
            catch (CImgIOException exception){
                //cout<<"Cannot find the first image!!! System error: "<<exception._message<<endl;
            }
            catch (CImgArgumentException a){

            }
            if(mean_square_error_option->is_set() || peak_mean_square_error_option->is_set() || signal_to_noise_ratio_option->is_set() || peak_signal_to_noise_ratio_option->is_set() || maximum_difference_option->is_set()){
                try{
                    Image_for_testing = CImg(argv[3]);
                    // Image_for_testing = CImg(image_for_testing);
                }
                catch (CImgIOException exception){
                    // cout<<"Cannot find the testing image!!! System error: "<<exception._message<<endl;
                }
                catch (CImgArgumentException a){

                }
            }
            if(brightness_command->is_set()){
                brightness_modification(Image,brightness_command->value());
                // Image.save("..\\..\\images\\Results\\brightness_modification_output.bmp");
                Image.save(result);
            }
            if(contrast_command->is_set()){
                contrast_modification(Image,contrast_command->value());
                //Image.save("..\\..\\images\\Results\\contrast_modification_output.bmp");
                Image.save(result);
            }
            if(negative_command->is_set()){
                negative(Image);
                //Image.save("..\\..\\images\\Results\\negative_output.bmp");
                Image.save(result);
            }
            if(horizontal_flip_command->is_set()){
                horizontal_flip(Image);
                //Image.save("..\\..\\images\\Results\\horizontal_flip_output.bmp");
                Image.save(result);
            }
            if(vertica_flip_command->is_set()){
                vertical_flip(Image);
                //Image.save("..\\..\\images\\Results\\vertical_flip_output.bmp");
                Image.save(result);
            }
            if(diagonal_flip_command->is_set()){
                diagonal_flip(Image);
                //Image.save("..\\..\\images\\Results\\diagonal_flip_output.bmp");
                Image.save(result);
            }
            if(image_shrink_command->is_set()){
                if(image_shrink_command->value()<=0){
                    std::cout<<"The parameter cannot be smaller or equal 0."<<std::endl;
                }else if(image_shrink_command->value()>=1){
                    std::cout<<"The parameter cannot be bigger or equal 1."<<std::endl;
                }else{
                    shrink(Image,image_shrink_command->value());
                    // Image.save("..\\..\\images\\Results\\shrink_output.bmp");
                    Image.save(result);
                }
            }
            if(image_enlarge_command->is_set()){
                if(image_enlarge_command->value()<=1){
                    std::cout<<"The parameter should be bigger or equal 1."<<std::endl;
                }else{
                    enlarge(Image,image_enlarge_command->value());
                    // Image.save("..\\..\\images\\Results\\enlarge_output.bmp");
                    Image.save(result);
                }
            }

            if(adaptive_median_filter_command->is_set()){
                adaptive_median_filter(Image);
                // Image.save("..\\..\\images\\Results\\adaptive_median_filter_output.bmp");
                //Image.save("..\\..\\images\\Results\\adaptive_median_filter_output.bmp");
                Image.save(result);
            }
            if(arithmetic_mean_filter_command->is_set()){
                arithmetic_mean_filter(Image,arithmetic_mean_filter_command->value());
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }

            if(mean_square_error_option->is_set()){
                cout<<"Mean square error: "<<mean_square_error(Image,Image_for_testing)<<endl;
            }
            if(peak_mean_square_error_option->is_set()){
                cout<<"Peak mean square error: "<<peak_mean_square_error(Image,Image_for_testing)<<endl;
            }
            if(signal_to_noise_ratio_option->is_set()){
                cout<<"Signal to noise ratio: "<<signal_to_noise_ratio(Image,Image_for_testing)<<endl;
            }
            if(peak_signal_to_noise_ratio_option->is_set()){
                cout<<"Peak signal to noise ratio: "<<peak_signal_to_noise_ratio(Image,Image_for_testing)<<endl;
            }
            if(maximum_difference_option->is_set()){
                cout<<"Maximum difference: "<<maximum_difference(Image,Image_for_testing)<<endl;
            }

            if(image_mean_option->is_set()){
                cout<<"Mean: "<<image_mean(Image,image_mean_option->value())<<endl;
            }
            if(image_variance_option->is_set()){
                cout<<"Variance: "<<image_variance(Image,image_variance_option->value())<<endl;
            }
            if(standard_devation_option->is_set()){
                cout<<"Standard deviation: "<<standard_devation(Image,standard_devation_option->value())<<endl;
            }
            if(variation_coefficient_I_option->is_set()){
                cout<<"Variation coefficient I: "<<variation_coefficient_I(Image,variation_coefficient_I_option->value())<<endl;
            }
            if(asymmetry_coefficient_option->is_set()){
                cout<<"Asymmetry coefficient: "<< asymmetry_coefficient(Image,asymmetry_coefficient_option->value())<<endl;
            }
            if(flattening_coefficient_option->is_set()){
                cout<<"Flattening coefficient: "<<flattening_coefficient(Image,flattening_coefficient_option->value())<<endl;
            }
            if(variation_coefficient_II_option->is_set()){
                cout<<"Variation coefficient II: "<<variation_coefficient_II(Image,variation_coefficient_II_option->value())<<endl;
            }
            if(information_source_entropy_option->is_set()){
                cout<<"Information source entropy: "<<information_source_entropy(Image,information_source_entropy_option->value())<<endl;
            }
            if(histogram_option->is_set()){
                histogram(Image,histogram_option->value());
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(power_two_third_final_probability_density_function_option->is_set()){
                int maximum,minimmum;
                cout<<"Give maximum: "<<endl;
                cin>>maximum;
                cout<<"Give minimum: "<<endl;
                cin>>minimmum;
                power_two_third_final_probability_density_function(Image,power_two_third_final_probability_density_function_option->value(),maximum,minimmum);
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(kirsh_operator_option->is_set()){
                kirsh_operator(Image);
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(edge_sharpening_option->is_set()){
                edge_sharpening(Image,edge_sharpening_option->value());
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(optimized_edge_sharpening_option->is_set()){
                optimized_edge_sharpening(Image);
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }

            if(dilation_option->is_set()){
                dilation(Image);
                Image.save(result);
            }
            if(erosion_option->is_set()){
                erosion(Image);
                Image.save(result);
            }
            if(opening_option->is_set()){
                opening(Image);
                Image.save(result);
            }
            if(closing_option->is_set()){
                closing(Image);
                Image.save(result);
            }
            if(HMT_option->is_set()){
                HMT(Image,HMT_option->value());
                Image.save(result);
            }
            if(m6_option->is_set()){
                m6(Image);
                Image.save(result);
            }
            if(region_growing_option->is_set()){
                int i,  j, threshold;
                cin>>i>>j>>threshold;
                region_growing(Image,i,j,threshold);
                Image.save(result);
            }
             if(FFT_option->is_set()){
                FFT(Image);
                Image.save(result);
            }
             if(IFFT_option->is_set()){
                IFFT(Image);
                Image.save(result);
            }

        }catch (CImgIOException exception){
        }catch (CImgArgumentException a){
        }catch (...){

        }
    }
*/
/*
    CImg<unsigned char> image("..\\..\\images\\Binary_images_(1-bit)\\lenabw.bmp");

    CImg<unsigned char> image1("..\\..\\images\\Binary_images_(1-bit)\\lollol.bmp");

    //erosion(image);
    //dilation(image);
    //opening(image);
    //closing(image);
    //HMT(image);
    int SE1[3][3]={{255,255,255},
                   {1,0,1},
                   {0,0,0}};
    int SE2[3][3]={{1,255,255},
                   {0,0,255},
                   {0,0,1}};
    int SE3[3][3]={{0,1,255},
                   {0,0,255},
                   {0,1,255}};
    int SE4[3][3]={{0,0,1},
                   {0,0,255},
                   {1,255,255}};
    int SE5[3][3]={{0,0,0},
                   {1,0,1},
                   {255,255,255}};
    int SE6[3][3]={{1,0,0},
                   {255,0,0},
                   {255,255,1}};
    int SE7[3][3]={{255,1,0},
                   {255,0,0},
                   {255,1,0}};
    int SE8[3][3]={{255,255,1},
                   {255,0,0},
                   {1,0,0}};

    int SE9[3][3]={{0,1,1},
                   {0,255,1},
                   {0,1,1}};
    int SE10[3][3]={{0,0,0},
                    {1,255,1},
                    {1,1,1}};
    int SE11[3][3]={{1,1,0},
                    {1,255,0},
                    {1,1,0}};
    int SE12[3][3]={{1,1,1},
                    {1,255,1},
                    {0,0,0}};
    //HTM(image,SE5);
    CImg<unsigned char> image2("..\\..\\images\\m7.bmp");

    HMT(image,3);

    */
   // CImg<unsigned char> image("..\\..\\images\\Binary_images_(1-bit)\\lena128.bmp");
        CImg<double> image1("..\\..\\images\\lena128.bmp");
        CImg<double> image21("..\\..\\images\\x1c.bmp");
        CImg<double> image5("..\\..\\images\\Gray_scale_images_(8-bits)\\camera.bmp");

        CImg<double> image3("..\\..\\images\\Gray_scale_images_(8-bits)\\lena.bmp");
        CImg<double> test_image("..\\..\\images\\masks\\F5test3.bmp");
        CImg<double> test_mask("..\\..\\images\\masks\\F5mask1.bmp");
        CImg<double> test_mask1("..\\..\\images\\test_mask1.bmp");


        //slow_dicrete_DFT(image);
    //FFT(image);
   // IFFT(image);
   // FFT2D(image);
   //FFT2D(image2);
        //dft2d(image);
       // dft2d(image);
        //FFT2D(image1);
       // ApplyFft(image3);
        //ApplyInverseFft(image21);
       // ApplyInverseFft(image21);

       // DFT2Dxd(image1);
       // dft2d(image1);
       // ApplyInverseFft(image3);
        //ApplyHighPassEdgeDetectionFilter(test_image,test_mask1,200,true);
        //ApplyHighPassEdgeDetectionFilter(test_image,test_mask1,200, false);
       // mask_maker(512,512,100,100,135);
        mask_maker(512,512,100,60,200);
/*
        ApplyLowPassFilter(image3,20,true);
        ApplyLowPassFilter(image3,20,false);
        ApplyHighPassFilter(image3,200,true);
        ApplyHighPassFilter(image3,200,false);

        ApplyBandCutFilter(image3,20,30, true);
        ApplyBandCutFilter(image3,20,30, false);



        ApplyPhaseModifying(image1,50.0,50.0);

        ApplyBandPassFilter(image3,20,30, true);
        ApplyBandPassFilter(image3,20,30, false);
        */
     //  RepresentIFFTAsImage(ApplyFft(image21).first);
      // std::cout<<ApplyFft(image21).first[0][0]<<std::endl;
        //ApplyDft(image1);
    return 0;

}
