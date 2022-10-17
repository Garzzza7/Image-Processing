#include <iostream>
#include <algorithm>
#include "CImg.h"
using namespace cimg_library;
void insertion_sort(int arr[], int n);
void brightness_modification(int constant);
void contrast_modification(int intensity);
void negative();

void horizontal_flip();
void vertical_flip();
void diagonal_flip();
void shrink(float multiplier);
void enlarge(float multiplier);

void median_filter();
void geometric_mean_filter();

float mean_square_error();
float peak_mean_square_error();//why nan lol
float signal_to_noise_ratio();
float peak_signal_to_noise_ratio();
float maximum_difference();






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
    //brightness_modification(100);
    contrast_modification(100);
    horizontal_flip();
    vertical_flip();
    diagonal_flip();
    shrink(0.5);
    enlarge(2);
    std::cout<<mean_square_error()<<std::endl;
    std::cout<<peak_mean_square_error()<<std::endl;
    std::cout<<signal_to_noise_ratio()<<std::endl;
    std::cout<<peak_signal_to_noise_ratio()<<std::endl;
    std::cout<<maximum_difference()<<std::endl;
    median_filter();

    return 0;
}

void brightness_modification(int constant) {
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp"); // create the image from a file (must exist in the working dir)
    if(constant >= 0)
    {
        for (int x = 0; x < image.width(); x++)
        {
            for (int y = 0; y < image.height(); y++)
            {
                float valR = image(x, y, 0) + constant;
                float valG = image(x, y, 1) + constant;
                float valB = image(x, y, 2) + constant;

                if(valR <= 255) image(x, y,0) = valR;
                else image(x, y,0) = 255;

                if(valG <= 255) image(x, y,1) = valG;
                else image(x, y,1) = 255;

                if(valB <= 255) image(x, y,2) = valB;
                else image(x, y,2) = 255;
            }
        }
    }
    else
    {
        for (int x = 0; x < image.width(); x++)
        {
            for (int y = 0; y < image.height(); y++)
            {
                float valR = image(x, y, 0) + constant;
                float valG = image(x, y, 1) + constant;
                float valB = image(x, y, 2) + constant;

                if(valR >= 0) image(x, y,0) = valR;
                else image(x, y,0) = 0;

                if(valG >= 0) image(x, y,1) = valG;
                else image(x, y,1) = 0;

                if(valB >= 0) image(x, y,2) = valB;
                else image(x, y,2) = 0;
            }
        }
    }
    image.save_bmp("..\\..\\images\\out2.bmp"); // save the modified image to a file

}

void contrast_modification(int intensity){
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
    /*
    int max_intensity=255;
    int min_intensity=0;
     */
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            /*
            float valR = image(x, y, 0);
            if (max_intensity>valR) max_intensity= 255; else max_intensity=valR;
            if (min_intensity<valR) min_intensity= 0; else min_intensity=valR;
            float valG = image(x, y, 1);
            if (max_intensity>valG) max_intensity= 255; else max_intensity=valG;
            if (min_intensity<valG) min_intensity= 0; else min_intensity=valG;
            float valB = image(x, y, 2);
            if (max_intensity>valB) max_intensity= 255; else max_intensity=valB;
            if (min_intensity<valB) min_intensity= 0; else min_intensity=valB;
            image(x, y, 0)=255*((valR-min_intensity)/(max_intensity-min_intensity));
            image(x, y, 1)=255*((valG-min_intensity)/(max_intensity-min_intensity));
            image(x, y, 2)=255*((valB-min_intensity)/(max_intensity-min_intensity));
             */
            //https://ie.nitk.ac.in/blog/2020/01/19/algorithms-for-adjusting-brightness-and-contrast-of-an-image/
            float correction_factor = 259*(255+intensity)/255*(259-intensity);
            float valR = correction_factor*(image(x, y, 0)-128)+128;
            float valG = correction_factor*(image(x, y, 1)-128)+128;
            float valB = correction_factor*(image(x, y, 2)-128)+128;

            if(valR <= 0)
            {
                image(x, y, 0) = 0;
            }
            else if (valR >= 255) image(x, y,0) = 255;

            else image(x, y, 0) = valR;

            if(valG <= 0)
            {
                image(x, y, 1) = 0;
            }

            else if (valG >= 255) image(x, y,1) = 255;

            else image(x, y,1) = valG;

            if(valB <= 0)
            {
                image(x, y, 2) = 0;
            }
            else if (valB >= 255) image(x, y,2) = 255;

            else image(x, y,2) = valB;



        }
    }
    image.save_bmp("..\\..\\images\\out5.bmp"); // save the modified image to a file

}

void negative(){
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp"); // create the image from a file (must exist in the working dir)
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) { // only upper half of the image gets processed
            float valR = image(x, y, 0); // Read red value at coordinates (x, y)
            float valG = image(x, y, 1); // Read green value at coordinates (x, y)
            float valB = image(x, y, 2); // Read blue value at coordinates (x, y)
            float negative1 = 255-valR;
            float negative2 = 255-valG;
            float negative3 = 255-valB;
            image(x, y, 0) = negative1;
            image(x, y, 1) = negative2;
            image(x, y, 2) = negative3;
        }
    }
    image.save_bmp("..\\..\\images\\out1.bmp"); // save the modified image to a file
}

void horizontal_flip(){
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> buffer = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            buffer(x, y, 0) = image(image.width()-x, y, 0);
            buffer(x, y, 1) = image(image.width()-x, y, 1);
            buffer(x, y, 2) = image(image.width()-x, y, 2);
        }
    }
    image = buffer;
    image.save_bmp("..\\..\\images\\out6.bmp");

}

void vertical_flip(){
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> buffer = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            buffer(x, y, 0) = image(x, image.height()-y, 0);
            buffer(x, y, 1) = image(x, image.height()-y, 1);
            buffer(x, y, 2) = image(x, image.height()-y, 2);
        }
    }
    image = buffer;
    image.save_bmp("..\\..\\images\\out7.bmp");

}

void diagonal_flip(){
    CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
    CImg<unsigned char> buffer = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            buffer(x, y, 0) = image(image.width()-x, image.height()-y, 0);
            buffer(x, y, 1) = image(image.width()-x, image.height()-y, 1);
            buffer(x, y, 2) = image(image.width()-x, image.height()-y, 2);
        }
    }
    image = buffer;
    image.save_bmp("..\\..\\images\\out8.bmp");

}

void shrink(float multiplier){
    if (multiplier<=0){

    }else if(multiplier>=1){

    }else{
        CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
        CImg<unsigned char> buffer (image.width()*multiplier,image.width()*multiplier,1,3,0);
        for (int x = 0; x < buffer.width(); x++) {
            for (int y = 0; y < buffer.height(); y++) {
                buffer(x, y, 0) = image(x/multiplier, y/multiplier, 0);
                buffer(x, y, 1) = image(x/multiplier, y/multiplier, 1);
                buffer(x, y, 2) = image(x/multiplier, y/multiplier, 2);
            }
        }
        image = buffer;
        image.save_bmp("..\\..\\images\\out9.bmp");
    }


}

void enlarge(float multiplier){
    if (multiplier<=0){

    }else if(multiplier<=1){

    }else{
        CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
        CImg<unsigned char> buffer (image.width()*multiplier,image.width()*multiplier,1,3,0);
        for (int x = 0; x < buffer.width(); x++) {
            for (int y = 0; y < buffer.height(); y++) {
                buffer(x, y, 0) = image(x/multiplier, y/multiplier, 0);
                buffer(x, y, 1) = image(x/multiplier, y/multiplier, 1);
                buffer(x, y, 2) = image(x/multiplier, y/multiplier, 2);
            }
        }
        image = buffer;
        image.save_bmp("..\\..\\images\\out10.bmp");
    }


}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void median_filter(){
    /*
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
*/
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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