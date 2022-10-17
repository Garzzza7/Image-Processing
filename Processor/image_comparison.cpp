#include <iostream>
#include "CImg.h"
#include "Task1.h"
using namespace cimg_library;
/*
float mean_square_error();
float peak_mean_square_error();//why nan lol
float signal_to_noise_ratio();
float peak_signal_to_noise_ratio();
float maximum_difference();
*/
float mean_square_error(){
    CImg<unsigned char> image1("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> image2("..\\..\\images\\lenac.bmp");
    float result=0;
    float dimensions = image1.width()*image1.height();
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            result = result +(image1(x,y)-image2(x,y))*(image1(x,y)-image2(x,y));
        }
    }
    return result/dimensions;

}
float peak_mean_square_error(){
    CImg<unsigned char> image1("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> image2("..\\..\\images\\lenac.bmp");
    float max;
    float max2= max*max;
    float result=0;
    float dimensions = image1.width()*image1.height();
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            if (image1(x,y)>max){
                max=image1(x,y);
            }
            result = result +(image1(x,y)-image2(x,y))*(image1(x,y)-image2(x,y));
        }
    }
    return result/(dimensions * max2);
}
float signal_to_noise_ratio(){
    CImg<unsigned char> image1("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> image2("..\\..\\images\\lenac.bmp");
    float result1=0;
    float result2=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            result1=result1+(image1(x,y)*image1(x,y)); // yep i dont trust
        }
    }
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            result1=result1+((image1(x,y)+image1(x,y))-(image2(x,y)+image2(x,y))*(image1(x,y)+image1(x,y))-(image2(x,y)+image2(x,y))); // yep i dont trust
        }
    }
    return 10*log10(result1/result2);
}
float peak_signal_to_noise_ratio(){
    CImg<unsigned char> image1("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> image2("..\\..\\images\\lenac.bmp");
    float max;
    float max2=max*max;
    float result1=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            if (image1(x,y)>max){
                max=image1(x,y);
            }

        }
    }
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            result1=result1+((image1(x,y)+image1(x,y))-(image2(x,y)+image2(x,y))*(image1(x,y)+image1(x,y))-(image2(x,y)+image2(x,y))); // yep i dont trust
        }
    }

    return 10*log10(max2/result1);
}
float maximum_difference(){
    CImg<unsigned char> image1("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> image2("..\\..\\images\\lenac.bmp");
    float result=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            if(std::abs(image1(x,y)-image2(x,y))>result){
                result=std::abs(image1(x,y)-image2(x,y));
            }


        }
    }
    return result;

}

