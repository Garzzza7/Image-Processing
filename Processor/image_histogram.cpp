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
    histogram.save("..\\..\\images\\histogramblue1.bmp");
}
void power_two_third_final_probability_density_function(CImg<unsigned char> &image,int a,int maximum,int minimmum){
    CImg<unsigned char> newImage = image;
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

    for (unsigned short x = 0; x < newImage.width(); x++){
        for (unsigned int y = 0; y < newImage.height(); y++){
            unsigned int sum = std::accumulate(values, values + image(x, y, a), 0);
            newImage(x, y, 0) = pow(pow(minimmum,0.3333333333333333) + (pow(maximum,0.3333333333333333)-pow(minimmum,0.3333333333333333))*((float) sum / (float) size),3);
            newImage(x, y, 1) = pow(pow(minimmum,0.3333333333333333) + (pow(maximum,0.3333333333333333)-pow(minimmum,0.3333333333333333))*((float) sum / (float) size),3);
            newImage(x, y, 2) = pow(pow(minimmum,0.3333333333333333) + (pow(maximum,0.3333333333333333)-pow(minimmum,0.3333333333333333))*((float) sum / (float) size),3);
        }
    }
    newImage.save("..\\..\\images\\twothree.bmp");
}
void kirsh_operator(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
     int kirsch[8][3][3] =
             {
                    {{  5,  5,  5 }, { -3,  0, -3 }, { -3, -3, -3 }}, /*rotation 1 */
                    {{  5,  5, -3 }, {  5,  0, -3 }, { -3, -3, -3 }}, /*rotation 2 */
                    {{  5, -3, -3 }, {  5,  0, -3 }, {  5, -3, -3 }}, /*rotation 3 */
                    {{ -3, -3, -3 }, {  5,  0, -3 }, {  5,  5, -3 }}, /*rotation 4 */
                    {{ -3, -3, -3 }, { -3,  0, -3 }, {  5,  5,  5 }}, /*rotation 5 */
                    {{ -3, -3, -3 }, { -3,  0,  5 }, { -3,  5,  5 }}, /*rotation 6 */
                    {{ -3, -3,  5 }, { -3,  0,  5 }, { -3, -3,  5 }}, /*rotation 7 */
                    {{ -3,  5,  5 }, { -3,  0,  5 }, { -3, -3, -3 }}  /*rotation 8 */

            };
    unsigned int y, x, lay;
    int max_sum;


    for (lay = 0; lay < 3; lay++) {
        for (y = 1; y < image.height() - 1; ++y) {
            for (x = 1; x < image.width() - 1; x++) {
                max_sum = 0;
                for (unsigned m = 0; m < 8; ++m) {
                    int sum;
                    sum = 0;

                    for (int k = -1; k < 2; k++)
                        for (int l = -1; l < 2; l++) {
                            sum = sum + kirsch[m][k + 1][l + 1]/**(lay*image.width()*image.height()+(y+k)*image.width()+(x+l))*/;
                        }
                    if (sum > max_sum)
                        max_sum = sum;
                }
                max_sum = max_sum/8 > 255 ? 255: max_sum/8;

                //dOUT[lay * size + y * width + x] = max_sum;
                buffer(x,y,0)=max_sum;
                buffer(x,y,1)=max_sum;
                buffer(x,y,2)=max_sum;
            }

        }
    }
    /*
    for (int x = 1; x < image.width()-1; x=x+1)
    {
        for (int y = 1; y < image.height()-1; y=y+1)
        {
            buffer(x,y,0)=max_sum;
            buffer(x,y,1)=max_sum;
            buffer(x,y,2)=max_sum;
            std::cout<<max_sum<<std::endl;
        }
    }
     */


    buffer.save("..\\..\\images\\kirsh.bmp");
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

