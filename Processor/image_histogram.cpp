#include <iostream>
#include <numeric>
#include "CImg.h"
#include "Task1.h"
#include "vector"
using namespace cimg_library;
void histogram(CImg<unsigned char> &image,int a) {
    CImg<unsigned char> histogram(image.width(), image.height()/2, 1, 3, 0);
    int values[256];
    int maximum = 0;
    for(int i=0;i<256;i++){
        values[i]=0;
    }
    for(int x=0;x<image.width();x++){
        for(int y=0;y<image.height();y++){
            values[image(x, y, a)]++;
        }
    }
    for(int i=0;i<256;i++){
        if(values[i] > maximum) {
            maximum = values[i];
        }
    }
    for(int i=0;i<256;i++){
        values[i]=255*values[i]/maximum;
    }
    for(int x=0;x<256;x++){
        for(int y=0;y<values[x];y++){
            histogram(2 * x, 255 - y, a)=255;
            histogram(2 * x + 1, 255 - y, a)=255;
        }
    }
    image=histogram;
   // histogram.save("..\\..\\images\\histogramblue1.bmp");
}
void power_two_third_final_probability_density_function(CImg<unsigned char> &image,int a,int maximum,int minimmum){
    CImg<unsigned char> buffer = image;
     int values[256];
    unsigned int size = image.width()*image.height();
    for(int i=0;i<256;i++){
        values[i]=0;
    }
    for (int x = 0; x < image.width(); x++){
        for (int y = 0; y < image.height(); y++){
            values[image(x, y, a)]++;
        }
    }
    for (unsigned short x = 0; x < buffer.width(); x++){
        for (unsigned int y = 0; y < buffer.height(); y++){
            unsigned int sum = std::accumulate(values, values + image(x, y, a), 0);
            buffer(x, y, 0) = pow(pow(minimmum,0.3333333333333333) + (pow(maximum,0.3333333333333333)-pow(minimmum,0.3333333333333333))*((float) sum / (float) size),3);
            buffer(x, y, 1) = pow(pow(minimmum,0.3333333333333333) + (pow(maximum,0.3333333333333333)-pow(minimmum,0.3333333333333333))*((float) sum / (float) size),3);
            buffer(x, y, 2) = pow(pow(minimmum,0.3333333333333333) + (pow(maximum,0.3333333333333333)-pow(minimmum,0.3333333333333333))*((float) sum / (float) size),3);
        }
    }
    image=buffer;
    //buffer.save("..\\..\\images\\twothree_grey.bmp");
}
void kirsh_operator(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
    for (int x = 2; x < image.width()-2; x++) {
        for (int y = 2; y < image.height()-2; y++) {
            for(int z=0;z<3;z++){
                std::vector<int>v;
                std::vector<int>max;
                for(int i = x;i<=x+2;i++){
                    for(int j = y;j<=y+2;j++){
                            v.push_back(image(i, j,z));
                    }
                }
                v.erase(v.begin()+4);
                for(int i=0;i<=7;i++){
                    max.push_back(abs(5*(v[0]+v[1]+v[2])-3*(v[3]+v[4]+v[5]+v[6]+v[7])));
                    v.push_back(v[0]);
                    v.erase(v.begin());
                }
                std::sort(max.begin(), max.end());
                buffer(x,y,z)=max[max.size()-1];
                v.clear();
                max.clear();
            }
        }
    }
    image=buffer;
    //buffer.save("..\\..\\images\\kirsh_greyv2.bmp");
}
void edge_sharpening(CImg<unsigned char> &image){
    int arr[3][3]={{0,-1,0},
                   {-1,5,-1},
                   {0,-1,0}};
    int result;
    CImg<unsigned char> buffer=image;
    for (int x=1;x<image.width()-1;x++){
        for (int y=1;y<image.height()-1;y++) {
            for (int z=0;z<=2;z++){
                /*
                int sum = -image(x-1, y-1,z)-image(x-1, y,z)-image(x-1, y+1,z)-
                          image(x, y-1,z)+9*image(x, y,z)-image(x, y+1,z)-
                          image(x-1, y-1,z)-image(x-1, y,z)-image(x+1,y+1,z);
                */

                int result = -image(x-1, y,z)-image(x, y-1,z)+5*image(x, y,z)-image(x, y+1,z)-image(x-1, y,z);
                buffer(x, y,z) = result;

                 /*
                for(int i=-1;i<2;i++){
                    for(int j=y;j<2;j++){
                         result=image(x+i,y+j,z);

                                }
                                                }
                                            */
            buffer(x, y,z) = result;

            }
        }
    }
    image=buffer;
    //buffer.save("..\\..\\images\\edge_shapreningv4.bmp");
}


/*
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
*/

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

