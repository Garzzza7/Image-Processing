#include <iostream>
#include "CImg.h"
#include "Task1.h"
using namespace cimg_library;

/*
void horizontal_flip();
void vertical_flip();
void diagonal_flip();
void shrink(float multiplier);
void enlarge(float multiplier);
*/

void horizontal_flip(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            buffer(x, y, 0) = image(image.width()-x, y, 0);
            buffer(x, y, 1) = image(image.width()-x, y, 1);
            buffer(x, y, 2) = image(image.width()-x, y, 2);
        }
    }
    image = buffer;
    //image.save_bmp("..\\..\\images\\horizontal_flip.bmp");

}

void vertical_flip(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            buffer(x, y, 0) = image(x, image.height()-y, 0);
            buffer(x, y, 1) = image(x, image.height()-y, 1);
            buffer(x, y, 2) = image(x, image.height()-y, 2);
        }
    }
    image = buffer;
    //image.save_bmp("..\\..\\images\\vertical_flip.bmp");

}

void diagonal_flip(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            buffer(x, y, 0) = image(image.width()-x, image.height()-y, 0);
            buffer(x, y, 1) = image(image.width()-x, image.height()-y, 1);
            buffer(x, y, 2) = image(image.width()-x, image.height()-y, 2);
        }
    }
    image = buffer;
   // image.save_bmp("..\\..\\images\\diagonal_flip.bmp");

}

void shrink(CImg<unsigned char> &image,float multiplier){
    if (multiplier<=0){

    }else if(multiplier>=1){

    }else{
        //CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
        CImg<unsigned char> buffer (image.width()*multiplier,image.width()*multiplier,1,3,0);
        for (int x = 0; x < buffer.width(); x++) {
            for (int y = 0; y < buffer.height(); y++) {
                buffer(x, y, 0) = image(x/multiplier, y/multiplier, 0);
                buffer(x, y, 1) = image(x/multiplier, y/multiplier, 1);
                buffer(x, y, 2) = image(x/multiplier, y/multiplier, 2);
            }
        }
        image = buffer;
      //  image.save_bmp("..\\..\\images\\shrink.bmp");
    }


}

void enlarge(CImg<unsigned char> &image,float multiplier){
    if (multiplier<=1){

    }else{
       // CImg<unsigned char> image("..\\..\\images\\lenac.bmp");
        CImg<unsigned char> buffer (image.width()*multiplier,image.width()*multiplier,1,3,0);
        for (int x = 0; x < buffer.width(); x++) {
            for (int y = 0; y < buffer.height(); y++) {
                buffer(x, y, 0) = image(x/multiplier, y/multiplier, 0);
                buffer(x, y, 1) = image(x/multiplier, y/multiplier, 1);
                buffer(x, y, 2) = image(x/multiplier, y/multiplier, 2);
            }
        }
        image = buffer;
       // image.save_bmp("..\\..\\images\\enlarge.bmp");
    }


}