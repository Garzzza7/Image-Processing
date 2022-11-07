#include <iostream>
#include "CImg.h"
#include "Task1.h"
using namespace cimg_library;
/*
void insertion_sort(int arr[], int n);
void brightness_modification(int constant);
void contrast_modification(int intensity);
void negative();
*/
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

void brightness_modification(CImg<unsigned char> &image,int constant) {
    if(constant >= 0){
        for (int x = 0; x < image.width(); x++){
            for (int y = 0; y < image.height(); y++){
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
    }else{
        for (int x = 0; x < image.width(); x++){
            for (int y = 0; y < image.height(); y++){
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
}

void contrast_modification(CImg<unsigned char> &image,int intensity){
   // CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
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
            float correction_factor = (259*(255+intensity))/(255*(259-intensity));
            float valR = correction_factor*(image(x, y, 0)-128)+128;
            float valG = correction_factor*(image(x, y, 1)-128)+128;
            float valB = correction_factor*(image(x, y, 2)-128)+128;

            if(valR <= 0){
                image(x, y, 0) = 0;
            }
            else if (valR >= 255) image(x, y,0) = 255;

            else image(x, y, 0) = valR;

            if(valG <= 0){
                image(x, y, 1) = 0;
            }
            else if (valG >= 255) image(x, y,1) = 255;

            else image(x, y,1) = valG;

            if(valB <= 0){
                image(x, y, 2) = 0;
            }
            else if (valB >= 255) image(x, y,2) = 255;

            else image(x, y,2) = valB;
        }
    }
    //image.save_bmp("..\\..\\images\\contrast_modification.bmp"); // save the modified image to a file

}

void negative(CImg<unsigned char> &image){
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++){
            float valR = image(x, y, 0);
            float valG = image(x, y, 1);
            float valB = image(x, y, 2);
            float negative1 = 255-valR;
            float negative2 = 255-valG;
            float negative3 = 255-valB;
            image(x, y, 0) = negative1;
            image(x, y, 1) = negative2;
            image(x, y, 2) = negative3;
        }
    }
}

