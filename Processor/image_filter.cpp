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
        std::vector<int> pixels;
        for (int i=x-Sxy;i<x+Sxy;i++){
            for (int j=y-Sxy;j<y+Sxy;j++){
                pixels.push_back(image1(i, j, z));
            }
        }
        std::sort(pixels.begin(),pixels.end());
        int zmed;
        int zxy = image1(x,y,z);
        int zmin = pixels.front();
        int zmax = pixels.back();


        if(pixels.size()%2 == 0){
            zmed = (pixels[pixels.size()/2-1]+pixels[pixels.size()/2])/2;
        }
        else{
            zmed=pixels[pixels.size()/2];
        }
        median = stage_A(zxy,zmed,zmin,zmax,Sxy,Smax);
        Sxy++;
    }
    return median;
}
void adaptive_median_filter(CImg<unsigned char> &image){

   // CImg<unsigned char> image1(name1);
    //CImg<unsigned char> image2(image1.width(),image1.height(),1,3,0);
   // CImg<unsigned char> image2/*(image1.width(),image1.height(),1,3,0)*/=image1;
   // CImg<unsigned char> image2(name2);
    CImg<unsigned char> buffer = image;
    for (int x = 1; x < image.width(); x++) {
        for (int y = 1; y < image.height(); y++) {
            /*
            image2(x,y,0)= median(image1,x,y,0);
            image2(x,y,1)= median(image1,x,y,1);
            image2(x,y,2)= median(image1,x,y,2);
             */
            for(int z=0;z<3;z++){
                buffer(x,y,z)= median(image,x,y,z);
            }

        }
    }

    image=buffer;
   // image.save_bmp(name2);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void arithmetic_mean_filter(CImg<unsigned char> &image,int constant) {
   // CImg<unsigned char> image1(name1);
    //CImg<unsigned char> image2(image1.width(),image1.height(),1,3,0);
   // CImg<unsigned char> image2=image1;
    CImg<unsigned char> buffer = image;
    int modifier=(2*constant+1)*(2*constant+1);
    for (int x = constant; x < image.width()-constant; x++) {
        for (int y = constant; y < image.height()-constant; y++) {
            for(int z=0;z<3;z++){
                double result=0;
                for(int i = x-constant;i<=x+constant;i++){
                    for(int j = y-constant;j<=y+constant;j++){
                            result+=((image(i, j,z))/(pow(2*constant+1,2)));
                            //result+=((image(a, b,o))/(modifier));
                    }
                }
                buffer(x,y,z)=int(result);
            }
        }
    }
    image=buffer;
}
/*
 void arithmetic_mean_filter(CImg<unsigned char> &image) {
   // CImg<unsigned char> image1(name1);
    //CImg<unsigned char> image2(image1.width(),image1.height(),1,3,0);
   // CImg<unsigned char> image2=image1;
    CImg<unsigned char> buffer = image;

    for (int x = 1; x < image.width(); x++) {
        for (int y = 1; y < image.height(); y++) {
            buffer(x,y,0)= (image(x-1,y-1,0)+image(x,y-1,0)+image(x+1,y-1,0)+image(x-1,y,0)+image(x,y,0)+image(x+1,y,0)+image(x-1,y+1,0)+image(x,y+1,0)+image(x+1,y+1,0))/9;
            buffer(x,y,1)= (image(x-1,y-1,1)+image(x,y-1,1)+image(x+1,y-1,1)+image(x-1,y,1)+image(x,y,1)+image(x+1,y,1)+image(x-1,y+1,1)+image(x,y+1,1)+image(x+1,y+1,1))/9;
            buffer(x,y,2)= (image(x-1,y-1,2)+image(x,y-1,2)+image(x+1,y-1,2)+image(x-1,y,2)+image(x,y,2)+image(x+1,y,2)+image(x-1,y+1,2)+image(x,y+1,2)+image(x+1,y+1,2))/9;
            //std::cout<<(image1(x-1,y-1,0)+image1(x,y-1,0)+image1(x+1,y-1,0)+image1(x-1,y,0)+image1(x,y,0)+image1(x+1,y,0)+image1(x-1,y+1,0)+image1(x,y+1,0)+image1(x+1,y+1,0))/9<<std::endl;
        }
    }
    image=buffer;
   // image1.save_bmp(name2);
}
 */
