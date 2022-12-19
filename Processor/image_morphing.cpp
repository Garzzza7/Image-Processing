#include <iostream>
#include <queue>
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
   // buffer.save_bmp("..\\..\\images\\dilation.bmp");
    image=buffer;
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
    //buffer.save_bmp("..\\..\\images\\erosion.bmp");
    image=buffer;
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
      //  buffer.save_bmp("..\\..\\images\\opening.bmp");
    image=buffer;
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
    //buffer.save_bmp("..\\..\\images\\closing.bmp");
    image=buffer;
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
void HMT(CImg<unsigned char> &image,int mask_size){
    CImg<unsigned char> buffer=image;
    int arr[mask_size][mask_size];
    int counter=0;
    for(int i=0;i<mask_size;i++){
        for(int j=0;j<mask_size;j++){
            std::cout<<"Give "<<i+1<<" , "<<j+1<<" Number"<<std::endl;
            std::cout<<"0 - black, 255 - white, rest - ignore"<<std::endl;
            int n;
            std::cin>>n;
            if(n==0 || n==255){
                counter++;
            }
            arr[i][j]=n;
        }
    }
    for (int x = 1; x < image.width()-1; x++) {
        for (int y = 1; y < image.height()-1; y++) {
            for(int z=0;z<3;z++){
                int flag=0;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(image(x+i,y+j,z)==arr[i][j]){
                            flag++;
                        }
                    }
                }
                if(flag==counter){
                    buffer(x,y,z)=0;
                }else{
                    buffer(x,y,z)=255;
                }

            }
        }
    }
    image=buffer;
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
                }else{
                    buffer(x,y,z)=255;
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
                }else{
                    buffer(x,y,z)=255;
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
                }else{
                    buffer(x,y,z)=255;
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
                }else{
                    buffer(x,y,z)=255;
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
                }else{
                    buffer(x,y,z)=255;
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
                }else{
                    buffer(x,y,z)=255;
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
                }else{
                    buffer(x,y,z)=255;
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
                }else{
                    buffer(x,y,z)=255;
                }
            }
        }
    }
    /*888888888888888888888888888888888888888888888888888*/

    //buffer.save_bmp("..\\..\\images\\m6.bmp");
    image=buffer;

}
//const unsigned char white[] = { 255, 255, 255 };
CImg<unsigned char>  region_growing_alg(CImg<unsigned char> &image,int seed_x, int seed_y) {
    // Initialize the region to the seed point
    CImg<unsigned char> region(image.width(), image.height(), 1, 1, 0);
    region(seed_x, seed_y) = 1;

    // Iteratively merge neighboring pixels or regions
    while (true) {
        CImg<unsigned char> new_region(image.width(), image.height(), 1, 1, 0);
        cimg_forXY(region, x, y) {
                if (region(x, y) == 1) {
                    // Check the neighbors of the current pixel
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int dy = -1; dy <= 1; dy++) {
                            if (dx == 0 && dy == 0) continue;
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < image.width() && ny < image.height()) {
                                // If the neighbor belongs to the same object or region of interest, add it to the new region
                                if (image(nx, ny) == image(x, y)) {
                                    new_region(nx, ny) = 1;
                                }
                            }
                        }
                    }
                }
            }

        // If no new pixels were added to the region, return the current region
        if (new_region.sum() == 0) {
            return region;
        }

        // Add the new pixels to the region
        region |= new_region;
    }
}
void  region_growing(CImg<unsigned char> &image){
    int seed_x=0;
    int seed_y=0;
    std::cout<<"Specify the seed point x:"<<std::endl;
    std::cin>>seed_x;
    std::cout<<"Specify the seed point y:"<<std::endl;
    std::cin>>seed_y;

    CImg<unsigned char> region = region_growing_alg(image, seed_x, seed_y);

    region.save_bmp("..\\..\\images\\region.bmp");
    region=image;

}