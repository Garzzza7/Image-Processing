#include <iostream>
#include "CImg.h"
#include "Task1.h"
#include "vector"
using namespace cimg_library;

void histogram(CImg<unsigned char> &image,int a) {
    CImg<unsigned char> result(512, 512, 1, 3, 0);
    //https://www.math.uci.edu/icamp/courses/math77c/demos/hist_eq.pdf
    //http://opencv-tutorials-hub.blogspot.com/2015/07/what-is-histogram-equalization-frequency-table-importance-advantages-methods-exposure-to-light-image-opencv-how-to-draw-histogram-code-c-algorithm.html
    float hist[256];
    for(int i=0;i<256;i++) {
        hist[i]=0;
    }
    for (int x = 0; x < image.width(); x+=1) {
        for (int y = 0; y < image.height(); y++) {
            hist[(int)image(x, y,a)]+=(float)1/(image.width()*image.height());
        }
    }
    switch(a){
        case 0:
            for(int i=0;i<350;i+=1) {
                for(int j=490;j>0;j--) {
                    if(hist[i]*25000>j)
                    {
                        result(2*i, 500-j,a) = 255;
                        result(2*i+1, 500-j,a) = 255;
                    }
                }
            }
            break;
        case 1:
            for(int i=0;i<350;i+=1) {
                for(int j=490;j>0;j--) {
                    if(hist[i]*25000>j)
                    {
                        result(2*i, 500-j,a) = 255;
                        result(2*i+1, 500-j,a) = 255;
                    }
                }
            }
            break;
        case 2:
            for(int i=0;i<350;i+=1) {
                for(int j=490;j>0;j--) {
                    if(hist[i]*25000>j)
                    {
                        result(2*i, 500-j,a) = 255;
                        result(2*i+1, 500-j,a) = 255;
                    }
                }
            }
            break;
        default: ;
    }

    result.save("..\\..\\images\\histogramred.bmp");


}

/*
void histogram(CImg<unsigned char> &image,int a) {
    CImg<unsigned char> buffer = image;
    CImg<unsigned char> histogram(700, 500, 1, 3, 0);
    std::vector<int> v;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            v.push_back(image(x, y, a));
        }
    }
    std::sort(v.begin(), v.end());

    int number = 1;

    for (int x = 0; x < histogram.width(); x++) {
        for (int y = histogram.width() - 1; y >= std::count(v.begin(), v.end(), number); y--) {
            if (std::find(v.begin(), v.end(), number) != v.end()) {
                histogram(x, y, a) = 255;
            } else {
                //histogram(x, y, a) = 0;
            }
            number++;
        }


        histogram.save("..\\..\\images\\histogram.bmp");

}

*/

