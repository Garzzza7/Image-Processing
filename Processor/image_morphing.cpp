#include <iostream>
#include "CImg.h"
#include "Task1.h"
using namespace cimg_library;
void dilation(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int z=0;z<3;z++){
                if(image(x,y,z)==0){
                    buffer(x+1,y,z)=0;
                    buffer(x-1,y,z)=0;
                    buffer(x,y+1,z)=0;
                    buffer(x,y-1,z)=0;
                    /*
                    buffer(x-1,y-1,z)=0;
                    buffer(x+1,y-1,z)=0;
                    buffer(x-1,y+1,z)=0;
                    buffer(x+1,y+1,z)=0;
                     */
                }
            }

        }
    }
    buffer.save_bmp("..\\..\\images\\dilation.bmp");
}
void erosion(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int z=0;z<3;z++){
                if(image(x,y,z)==0 &&
                image(x+1,y,z)==0 &&
                image(x-1,y,z)==0 &&
                image(x,y+1,z)==0 &&
                image(x,y-1,z)==0){
                    buffer(x,y,z)=0;
                    buffer(x+1,y,z)=255;
                    buffer(x-1,y,z)=255;
                    buffer(x,y+1,z)=255;
                    buffer(x,y-1,z)=255;
                }else{
                   // buffer(x,y,z)=0;
                }
            }

        }
    }
    buffer.save_bmp("..\\..\\images\\erosion.bmp");
}
void opening(CImg<unsigned char> &image){
        CImg<unsigned char> buffer = image;
        for (int x = 1; x < image.width()-1; x++) {
            for (int y = 1; y < image.height()-1; y++) {
                for(int z=0;z<3;z++){
                    if(image(x,y,z)==0 && (image(x+1,y,z)==0 && image(x-1,y,z)==0 && image(x,y+1,z)==0 && image(x,y-1,z)==0)){
                        buffer(x,y,z)=0;
                        buffer(x+1,y,z)=0;
                        buffer(x-1,y,z)=0;
                        buffer(x,y+1,z)=0;
                        buffer(x,y-1,z)=0;
                    }
                    else{
                        buffer(x,y,z)=255;
                    }
                }

            }
        }
        buffer.save_bmp("..\\..\\images\\opening.bmp");
}
void closing(CImg<unsigned char> &image){
    CImg<unsigned char> buffer = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int z=0;z<3;z++){
               if((image(x,y,z)==255&&(image(x-1,y,z)==255&&image(x,y-1,z)==0&&image(x+1,y,z)==0)&&image(x+1,y,z)==0)){
                    buffer(x,y,z)=0;
                   buffer(x-1,y,z)=0;
               }else if((image(x,y,z)==255&&(image(x-1,y,z)==0&&image(x,y-1,z)==255&&image(x+1,y,z)==0)&&image(x+1,y,z)==0)){
                   buffer(x,y,z)=0;
                   buffer(x-1,y,z)=0;
               }else if((image(x,y,z)==255&&(image(x-1,y,z)==0&&image(x,y-1,z)==255&&image(x+1,y,z)==0)&&image(x+1,y,z)==0)){
                   buffer(x,y,z)=0;
                   buffer(x,y-1,z)=0;
               }else if((image(x,y,z)==255&&(image(x-1,y,z)==0&&image(x,y-1,z)==0&&image(x+1,y,z)==255)&&image(x+1,y,z)==0)){
                   buffer(x,y,z)=0;
                   buffer(x+1,y,z)=0;
                }else{

               }
            }

        }
    }
    buffer.save_bmp("..\\..\\images\\closing.bmp");
}
void HMT(CImg<unsigned char> &image){
    CImg<unsigned char> buffer1 = image;
    CImg<unsigned char> buffer2 = image;
    CImg<unsigned char> buffer3 = image;
    CImg<unsigned char> buffer4 = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int z=0;z<3;z++){
                //north
                if(//image(x,y,z)==0 &&
                image(x-1,y-1,z)==0 &&
                image(x,y-1,z)==0 &&
                image(x+1,y-1,z)==0 &&
                image(x-1,y,z)!=255 &&
                image(x-1,y+1,z)!=255 &&
                image(x,y+1,z)!=255 &&
                image(x+1,y+1,z)!=255 &&
                image(x+1,y,z)!=255) {
                    buffer2(x,y,z)=0;
                }
                else{
                    buffer2(x,y,z)=255;
                }
                //west
                if(//image(x,y,z)==0 &&
                   image(x-1,y-1,z)==0 &&
                   image(x,y-1,z)==255 &&
                   image(x+1,y-1,z)==255 &&
                   image(x-1,y,z)!=0 &&
                   image(x-1,y+1,z)!=0 &&
                   image(x,y+1,z)!=255 &&
                   image(x+1,y+1,z)!=255 &&
                   image(x+1,y,z)!=255) {
                    buffer1(x,y,z)=0;
                }
                else{
                    buffer1(x,y,z)=255;
                }
                //east
                if(//image(x,y,z)==0 &&
                   image(x-1,y-1,z)==255 &&
                   image(x,y-1,z)==255 &&
                   image(x+1,y-1,z)==0 &&
                   image(x-1,y,z)!=255 &&
                   image(x-1,y+1,z)!=255 &&
                   image(x,y+1,z)!=255 &&
                   image(x+1,y+1,z)!=0 &&
                   image(x+1,y,z)!=0) {
                    buffer3(x,y,z)=0;
                }
                else{
                    buffer3(x,y,z)=255;
                }
                //south
                if(//image(x,y,z)==0 &&
                   image(x-1,y-1,z)==255 &&
                   image(x,y-1,z)==255 &&
                   image(x+1,y-1,z)==255 &&
                   image(x-1,y,z)!=255 &&
                   image(x-1,y+1,z)!=0 &&
                   image(x,y+1,z)!=0 &&
                   image(x+1,y+1,z)!=0 &&
                   image(x+1,y,z)!=255) {
                    buffer4(x,y,z)=0;
                }
                else{
                    buffer4(x,y,z)=255;
                }
            }
        }
    }
    buffer1.save_bmp("..\\..\\images\\HMT_west.bmp");
    buffer2.save_bmp("..\\..\\images\\HMT_north.bmp");
    buffer3.save_bmp("..\\..\\images\\HMT_east.bmp");
    buffer4.save_bmp("..\\..\\images\\HMT_south.bmp");
}
void m6(CImg<unsigned char> &image){

}
void region_growing(CImg<unsigned char> &image){

}

