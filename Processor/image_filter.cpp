#include <iostream>
#include "CImg.h"
#include "Task1.h"
using namespace cimg_library;

/*
 * here will be implementation
 void adaptive_median_filter();   //  (--adaptive)
 void arithmetic_mean_filter();   //  (--amean).
*/
void adaptive_median_filter(){

}
void arithmetic_mean_filter() {
    CImg<unsigned char> image1("..\\..\\images\\lenac_with_noise.bmp");
    CImg<unsigned char> image2(image1.width(),image1.height(),1,3,0);
    for (int x = 1; x < image1.width(); x++) {
        for (int y = 1; y < image1.height(); y++) {
            image2(x,y,0)= (image1(x-1,y-1,0)+image1(x,y-1,0)+image1(x+1,y-1,0)+image1(x-1,y,0)+image1(x,y,0)+image1(x+1,y,0)+image1(x-1,y+1,0)+image1(x,y+1,0)+image1(x+1,y+1,0))/9;
            image2(x,y,1)= (image1(x-1,y-1,1)+image1(x,y-1,1)+image1(x+1,y-1,1)+image1(x-1,y,1)+image1(x,y,1)+image1(x+1,y,1)+image1(x-1,y+1,1)+image1(x,y+1,1)+image1(x+1,y+1,1))/9;
            image2(x,y,2)= (image1(x-1,y-1,2)+image1(x,y-1,2)+image1(x+1,y-1,2)+image1(x-1,y,2)+image1(x,y,2)+image1(x+1,y,2)+image1(x-1,y+1,2)+image1(x,y+1,2)+image1(x+1,y+1,2))/9;
            //std::cout<<(image1(x-1,y-1,0)+image1(x,y-1,0)+image1(x+1,y-1,0)+image1(x-1,y,0)+image1(x,y,0)+image1(x+1,y,0)+image1(x-1,y+1,0)+image1(x,y+1,0)+image1(x+1,y+1,0))/9<<std::endl;
        }
    }
    image1=image2;
    image1.save_bmp("..\\..\\images\\lenac_with_no_noise.bmp");
}
