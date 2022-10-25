#include <iostream>
#include "CImg.h"
#include "Task1.h"
#include <vector>
using namespace cimg_library;

/*
 * here will be implementation
 void adaptive_median_filter();   //  (--adaptive)
 void arithmetic_mean_filter();   //  (--amean).
*/

int stage_B(int zxy, int zmed, int zmin, int zmax){
    int B1=zxy-zmin;
    int B2=zxy-zmax;
    if(B1>0 && B2<0){
        return zxy;
    }
    else{
        return zmed;
    }
}


int stage_A(int zxy, int zmed, int zmin, int zmax, int Sxy, int Smax){
    int A1 = zmed - zmin;
    int A2 = zmed - zmax;
    if(A1 > 0 && A2 < 0){
        return stage_B(zxy, zmed, zmin, zmax);
    }
    else{
        if(Sxy < Smax){
            return 123456;
        }
        else {
            return zxy;
        }
    }
}
int median(CImg<unsigned char> &image1,int x,int y,int z){
    //CImg<unsigned char> image1("..\\..\\images\\lenac_with_noise.bmp");
    int Sxy = 1;

    int Smax = image1.width() - x;
    if(image1.height()-y < Smax){
        Smax = image1.height() - y;
    }
    if(x < Smax){
        Smax = x;
    }
    if(y < Smax){
        Smax = y;
    }

    int median = 123456;
    while(median == 123456){
        //int pixels[]=new int[(x+Sxy)*(y+Sxy)];
        std::vector<int> pixels;
        for (int i = x - Sxy; i < x+Sxy;i++){
            for (int j = y - Sxy; j < y+Sxy;j++){
                pixels.push_back(image1(i, j, z));
            }
        }
        std::sort(pixels.begin(),pixels.end());
        int zmin = pixels.front();
        int zmax = pixels.back();
        int zxy = image1(x,y,z);
        int zmed;
        if(pixels.size()%2 == 0){
            /*
             * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF* CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF* CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFV
             * V
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * V* CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFVV
             * V
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             * * CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF* CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF* CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFV* CO TU SIE ODWALA WTFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
             *
             *
             *
             *
             *
             *
             *
             *
             */
            //zmed=(((pixels[pixels.size()/2-1])/2)+pixels[pixels.size()/2]);
            zmed = (pixels[pixels.size()/2-1]+pixels[pixels.size()/2])/2;
           // zmed =  (pixels[pixels.size() / 2 - 1]/2 + pixels[pixels.size() / 2]);
        }
        else{
            zmed=pixels[pixels.size()/2];
        }
        median = stage_A(zxy,zmed,zmin,zmax,Sxy,Smax);
        //std::cout<<median<<std::endl;
        Sxy++;
    }


    return median;
}
void adaptive_median_filter(const char*name1,const char*name2){

    CImg<unsigned char> image1(name1);
    //CImg<unsigned char> image2(image1.width(),image1.height(),1,3,0);
    CImg<unsigned char> image2/*(image1.width(),image1.height(),1,3,0)*/=image1;
   // CImg<unsigned char> image2(name2);
    for (int x = 1; x < image1.width(); x++) {
        for (int y = 1; y < image1.height(); y++) {
            /*
            image2(x,y,0)= median(image1,x,y,0);
            image2(x,y,1)= median(image1,x,y,1);
            image2(x,y,2)= median(image1,x,y,2);
             */
            for(int z=0;z<3;z++){
                image2(x,y,z)= median(image1,x,y,z);
            }

        }
    }

    image1=image2;
    image1.save_bmp(name2);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void arithmetic_mean_filter(const char*name1,const char*name2) {
    CImg<unsigned char> image1(name1);
    //CImg<unsigned char> image2(image1.width(),image1.height(),1,3,0);
    CImg<unsigned char> image2=image1;
    for (int x = 1; x < image1.width(); x++) {
        for (int y = 1; y < image1.height(); y++) {
            image2(x,y,0)= (image1(x-1,y-1,0)+image1(x,y-1,0)+image1(x+1,y-1,0)+image1(x-1,y,0)+image1(x,y,0)+image1(x+1,y,0)+image1(x-1,y+1,0)+image1(x,y+1,0)+image1(x+1,y+1,0))/9;
            image2(x,y,1)= (image1(x-1,y-1,1)+image1(x,y-1,1)+image1(x+1,y-1,1)+image1(x-1,y,1)+image1(x,y,1)+image1(x+1,y,1)+image1(x-1,y+1,1)+image1(x,y+1,1)+image1(x+1,y+1,1))/9;
            image2(x,y,2)= (image1(x-1,y-1,2)+image1(x,y-1,2)+image1(x+1,y-1,2)+image1(x-1,y,2)+image1(x,y,2)+image1(x+1,y,2)+image1(x-1,y+1,2)+image1(x,y+1,2)+image1(x+1,y+1,2))/9;
            //std::cout<<(image1(x-1,y-1,0)+image1(x,y-1,0)+image1(x+1,y-1,0)+image1(x-1,y,0)+image1(x,y,0)+image1(x+1,y,0)+image1(x-1,y+1,0)+image1(x,y+1,0)+image1(x+1,y+1,0))/9<<std::endl;
        }
    }
    image1=image2;
    image1.save_bmp(name2);
}
