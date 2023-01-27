//
// Created by aleks on 05/01/2023.
//
#include <complex>
#include <cmath>
#include <iostream>
#include <queue>
#include "CImg.h"
#include "Task1.h"
#include "vector"


using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
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
CImg<double> ApplyFourierSpectrumVisualization(vector<vector<complex<double>>> complexNumbers){
    CImg<double>visualisedBitmap(complexNumbers[0].size(),complexNumbers.size(),1,1,0);
    for (int x = 0; x < complexNumbers[0].size(); x++){
        for (int y = 0; y < complexNumbers.size(); y++){
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
    for (int x = 0; x < complexNumbers.size(); x++){
        vector<complex<double>> columns;
        for (int y = 0; y < complexNumbers[0].size(); y++){
            columns.push_back(complexNumbers[x][y]);
        }
        complexNumbersResult.push_back(columns);
    }
    for (int x = 0; x < complexNumbers.size() / 2; x++){
        for (int y = 0; y < complexNumbers[0].size() / 2; y++){
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















/*
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
*/
























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
    lol.save_bmp("..\\..\\images\\ApplyFft.bmp");
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
void mask_maker(int width, int height, double circleRadius, double angl, double rotationAngle){
    CImg<double> mask(width,height,1,1,0);
    for(int x=0;x<width;++x) {
        for (int y = 0; y < height; ++y) {
            mask(x, y) = 0;
        }
    }
    double to_rad= angl * M_PI / 180;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - width/2;
            int dy = y - height/2;
            double angle = std::tan(dy/dx);
            //cout<<angle<<endl;
            double distance = sqrt(pow((dx), 2) +pow((dy), 2));
            if (angle >= 0 && angle <= to_rad) {
                mask(x, y) = 255;
            }
        }
    }
    for (int x = 0; x < width; x++){
        for (int y = 0; y < height; y++){
            double distance = sqrt(pow((x - width / 2), 2) +pow((y - height / 2), 2));
            if (distance < circleRadius){
                mask(x,y)=0;
            }
        }
    }

    mask.rotate(rotationAngle,1,0);
    mask.save_bmp("..\\..\\images\\mask_maker_mask1.bmp");
   // return mask;
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

            if ((value >= minThreshold) && (value <= maxThreshold)){
                if (preservePhase){
                    double phase = atan2(frequencyDomain[x][y].imag(),frequencyDomain[x][y].real());
                    frequencyDomain[x][y] = complex<double>(0, phase);
                }
                else{
                    frequencyDomain[x][y] =complex<double>(0, 0);
                }
            }
        }
    }

    if (preservePhase){
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




////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
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

void FFT(CImg<unsigned char> &image) {

    CImg<unsigned char> buffer;
    const int ROWS = (int)image.width();
    std::vector<std::vector<std::complex<double>>> img;

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
    for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[i].size(); j++) {
            double magnitude = std::sqrt(img[i][j].real() * img[i][j].real() + img[i][j].imag() * img[i][j].imag());
            image(i,j) = (unsigned char)magnitude;
        }
    }
    buffer=image;
    buffer.save_bmp("..\\..\\images\\FFT.bmp");
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

void IFFT(CImg<unsigned char> &image) {

    const int ROWS = (int) image.width();
    std::vector<std::vector<std::complex<double>>> img;
    cimg_library::CImg<unsigned char> buffer;


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
    for (int i = 0; i < img.size(); i++) {
        for (int j = 0; j < img[i].size(); j++) {
            double magnitude = std::sqrt(img[i][j].real() * img[i][j].real() + img[i][j].imag() * img[i][j].imag());
            image(i, j) = (unsigned char) magnitude;
        }
    }
    buffer = image;
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