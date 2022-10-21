#include <iostream>
#include <algorithm>
#include "CImg.h"
/*
#include "image_adjustments.cpp"
#include "image_flip.cpp"
#include "image_filter.cpp"
#include "image_comparison.cpp"
 */
#include "Task1.h"
using namespace cimg_library;
/*
void horizontal_flip();
void vertical_flip();
void diagonal_flip();
void shrink(float multiplier);
void enlarge(float multiplier);
void median_filter();
void geometric_mean_filter();
void insertion_sort(int arr[], int n);
void brightness_modification(int constant);
void contrast_modification(int intensity);
void negative();
float mean_square_error();
float peak_mean_square_error();//why nan lol
float signal_to_noise_ratio();
float peak_signal_to_noise_ratio();
float maximum_difference();
*/


/*
int main() {
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp"); // create the image from a file (must exist in the working dir)
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height() / 2; y++) { // only upper half of the image gets processed
            float valR = image(x, y, 0); // Read red value at coordinates (x, y)
            float valG = image(x, y, 1); // Read green value at coordinates (x, y)
            float valB = image(x, y, 2); // Read blue value at coordinates (x, y)
            float avg = (valR + valG + valB) / 3; // Compute average pixel value (grey)
            image(x, y, 0) = avg;
            image(x, y, 1) = avg;
            image(x, y, 2) = avg;
        }
    }
    image.save_bmp("..\\..\\images\\out.bmp"); // save the modified image to a file
    return 0;
}
*/
int main() {
    //negative();
    /*
    brightness_modification(100);
    negative();
    contrast_modification(200);
    horizontal_flip();
    vertical_flip();
    diagonal_flip();
    shrink(0.5);
    enlarge(2);
     */
    arithmetic_mean_filter();
    std::cout<<mean_square_error()<<std::endl;
    std::cout<<peak_mean_square_error()<<std::endl;
    std::cout<<signal_to_noise_ratio()<<std::endl;
    std::cout<<peak_signal_to_noise_ratio()<<std::endl;
    std::cout<<maximum_difference()<<std::endl;



    return 0;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void median_filter(){

    CImg<unsigned char> image1("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> image2;
    float list[image1.width()][image1.height()];
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            list[x][y]=image1(x,y);
        }
    }
    for (int i = 0; i < image1.width(); i++)
        std::sort(list[i], list[i] + image1.height());
    for (int i = 0; i < image1.width(); i++)
    {
        for (int j = 0; j < image1.height(); j++)
            std::cout << (list[i][j]) << " ";
        std::cout <<  std::endl;
    }
    int result = int(ceil((image1.width()*image2.height())/2));

    CImg<unsigned char> image1("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> image2(image1.width(),image1.height(),1,3,0);
    //CImg<unsigned char> image2;
    int window[image1.width()*image1.height()];
    int size= sizeof(window)/sizeof(window[0]);
    int edgex = image1.width()/2;
    int edgey = image1.width()/2;
    for(int x=edgex;x<=image1.width()-edgex;x++ ){
        for(int y=edgey;y<=image1.height()-edgey;y++ ){
            int i=0;
            for(int fx=0;fx<=image1.width();fx++ ){
                for(int fy=0;fy<=image1.height();fy++ ){
                    window[i]=image1(x+fx-edgex,y+fy-edgey);
                    //std::cout<<window[i]<<std::endl;
                    i++;
                }
                insertion_sort(window,size);

               // image2(x,y,0)=100;
               // image2(x,y,1)=120;
               // image2(x,y,2)=window[image1.width()*image1.height()/2];
                //image2(x,y,1)=window[image1.width()*image1.height()/2];
                //image2(x,y,2)=window[image1.width()*image1.height()/2];
               // image2.save_bmp("..\\..\\images\\qweqweqwe.bmp");
                std::cout<<image1.spectrum()<<std::endl;
            }

        }

    }
   // std::cout<<image<<std::endl;
}




void geometric_mean_filter(){
//https://www.quora.com/How-can-we-implement-a-geometric-mean-filter-in-MATLAB
}
*/