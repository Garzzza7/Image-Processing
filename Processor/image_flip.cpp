#include <iostream>
#include "CImg.h"
using namespace cimg_library;

void horizontal_flip();
void vertical_flip();
void diagonal_flip();
void shrink(float multiplier);
void enlarge(float multiplier);


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