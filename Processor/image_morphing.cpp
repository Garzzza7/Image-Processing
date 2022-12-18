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
                   // buffer(x+1,y,z)=255;
                    //buffer(x-1,y,z)=255;
                   // buffer(x,y+1,z)=255;
                   // buffer(x,y-1,z)=255;
                }else{
                    buffer(x,y,z)=255;
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
int SE1[3][3]={{255,255,255},
               {1,0,1},
               {0,0,0}};
int SE2[3][3]={{1,255,255},
               {0,0,255},
               {0,0,1}};
int SE3[3][3]={{0,1,255},
               {0,0,255},
               {0,1,255}};
int SE4[3][3]={{0,0,1},
               {0,0,255},
               {1,255,255}};
int SE5[3][3]={{0,0,0},
               {1,0,1},
               {255,255,255}};
int SE6[3][3]={{1,0,0},
               {255,0,0},
               {255,255,1}};
int SE7[3][3]={{255,1,0},
               {255,0,0},
               {255,1,0}};
int SE8[3][3]={{255,255,1},
               {255,0,0},
               {1,0,0}};


int SE9[3][3]={{0,1,1},
               {0,255,1},
               {0,1,1}};
int SE10[3][3]={{0,0,0},
               {1,255,1},
               {1,1,1}};
int SE11[3][3]={{1,1,0},
               {1,255,0},
               {1,1,0}};
int SE12[3][3]={{1,1,1},
               {1,255,1},
               {0,0,0}};
CImg<unsigned char> HTM(CImg<unsigned char> &image,int mask[3][3]){
    CImg<unsigned char> buffer1 = image;
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int z=0;z<3;z++){
                int flag=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(image(x+i,y+j,z)==mask[i][j]){
                            flag++;
                        }
                    }
                }
                if(flag==7){
                    buffer1(x,y,z)=0;
                }else{
                    buffer1(x,y,z)=255;
                }

            }
        }
    }
    //buffer1.save_bmp("..\\..\\images\\test9.bmp");
    return buffer1;
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
    CImg<unsigned char> buffer = image;
    CImg<unsigned char> lol (image.width(),image.width(),1,3,0);;
    CImg<unsigned char> result1 = HTM(buffer,SE1);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }

    /*888888888888888888888888888888888888888888888888888*/
    result1 = HTM(buffer,SE2);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/
    result1 = HTM(buffer,SE3);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/
    result1 = HTM(buffer,SE4);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/
    result1 = HTM(buffer,SE5);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/
    result1 = HTM(buffer,SE6);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/
    result1 = HTM(buffer,SE7);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/
    result1 = HTM(buffer,SE8);
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height() - 1; y++) {
            for (int z = 0; z < 3; z++) {
                if(buffer(x,y,z)==0 || result1(x,y,z)==0){
                    buffer(x,y,z)=0;
                    //std::cout<<"chuj"<<std::endl;
                }else{
                    buffer(x,y,z)=255;
                    //std::cout<<"dziekan"<<std::endl;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/

    buffer.save_bmp("..\\..\\images\\m8.bmp");

}
void region_growing(CImg<unsigned char> &image){

}

