#include <iostream>
#include "CImg.h"
#include "Task1.h"

using namespace cimg_library;

float image_mean(CImg<unsigned char> &image, int channel){
    int range[256];
    float mean = 0;
    int size=(image.width() * image.height());
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }
    for(int i = 0; i < 256; i++){
        mean += range[i]*i;
    }
    mean /= size;
    return mean;
}
float image_variance(CImg<unsigned char> &image, int channel){
    int range[256];
    float mean = 0;
    double variance = 0;
    int size=(image.width() * image.height());
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }

    for(int i = 0; i < 256; i++){
        mean += range[i]*i;
    }
    mean /= size;

    for(int i = 0; i < 256; i++)
    {
        variance += pow(i - mean, 2)*range[i];
    }
    variance /= size;
    return variance;
}
float standard_devation(CImg<unsigned char> &image, int channel){
    int range[256];
    float mean = 0;
    double variance = 0;
    int size=(image.width() * image.height());
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }

    for(int i = 0; i < 256; i++){
        mean += range[i]*i;
    }
    mean /= size;

    for(int i = 0; i < 256; i++)
    {
        variance += pow(i - mean, 2)*range[i];
    }
    variance /= size;
    return pow(variance, 0.5);
}
float variation_coefficient_I(CImg<unsigned char> &image, int channel){
    int range[256];
    float mean = 0;
    double variance = 0;
    int size=(image.width() * image.height());
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }

    for(int i = 0; i < 256; i++){
        mean += range[i]*i;
    }
    mean /= size;

    for(int i = 0; i < 256; i++)
    {
        variance += pow(i - mean, 2)*range[i];
    }
    variance /= size;
    return pow(variance, 0.5)/mean;
}
float asymmetry_coefficient(CImg<unsigned char> &image, int channel){
    int range[256];
    float mean = 0;
    double variance = 0;
    float sum=0;
    int size=(image.width() * image.height());
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }

    for(int i = 0; i < 256; i++){
        mean += range[i]*i;
    }
    mean /= size;

    for(int i = 0; i < 256; i++)
    {
        variance += pow(i - mean, 2)*range[i];
    }
    variance /= size;

    for(int i = 0; i < 256; i++){
        sum+=pow(i-mean,3)*range[i];
    }
    sum/=size;
    sum/=pow(pow(variance, 0.5),3);
    return sum;
}
float flattening_coefficient(CImg<unsigned char> &image, int channel){
    int range[256];
    float mean = 0;
    double variance = 0;
    float sum=0;
    int size=(image.width() * image.height());
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }

    for(int i = 0; i < 256; i++){
        mean += range[i]*i;
    }
    mean /= size;

    for(int i = 0; i < 256; i++)
    {
        variance += pow(i - mean, 2)*range[i];
    }
    variance /= size;

    for(int i = 0; i < 256; i++){
        sum+=pow(i-mean,4)*range[i];
    }
    sum/=size;
    sum/=pow(pow(variance, 0.5),4);
    return sum-3;
}
float variation_coefficient_II(CImg<unsigned char> &image, int channel){
    int range[256];
    float size=(image.width() * image.height());
    float sum=0;
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }
    for(int i = 0; i < 256; i++){
        sum+=pow(range[i],2);
    }
    sum /= pow(size,2);
    return sum;
}
float information_source_entropy(CImg<unsigned char> &image, int channel){
    int range[256];
    float size=(image.width() * image.height());
    float sum=0;
    for (int i=0;i<256;i++){
        range[i] = 0;
    }
    for (unsigned int x = 0; x < image.width(); x++){
        for (unsigned int y = 0; y < image.height(); y++){
            range[image(x, y, channel)]++;
        }
    }
    for(int i=0;i<256;i++){
        if(range[i]!=0){
            sum += range[i] * log2(range[i]/size);
        }
    }
    sum /= size;
    return -sum;
}