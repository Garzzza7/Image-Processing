#include <iostream>
#include "CImg.h"
#include "Task1.h"
using namespace cimg_library;
/*
float mean_square_error();
float peak_mean_square_error();//why nan lol
float signal_to_noise_ratio();
float peak_signal_to_noise_ratio();
float maximum_difference();
*/
float mean_square_error(CImg<unsigned char> &image1,CImg<unsigned char> &image2){
    //CImg<unsigned char> image1("..\\..\\images\\lena1.bmp");
    //CImg<unsigned char> image2("..\\..\\images\\lenac_with_no_noise.bmp");
    float result=0;
    float dimensions = image1.width()*image1.height();
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            result = result +(image1(x,y)-image2(x,y))*(image1(x,y)-image2(x,y));
        }
    }
    return result/dimensions;

}
float peak_mean_square_error(CImg<unsigned char> &image1,CImg<unsigned char> &image2){
    //CImg<unsigned char> image1("..\\..\\images\\lena1.bmp");
    //CImg<unsigned char> image2("..\\..\\images\\lenac_with_no_noise.bmp");
    float max;
    float result=0;
    float dimensions = image1.width()*image1.height();
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            if (image1(x,y)>max){
                max=image1(x,y);
            }
            result +=(image1(x,y)-image2(x,y));
        }
    }
    return result*result/(dimensions * max*max);
}
float signal_to_noise_ratio(CImg<unsigned char> &image1,CImg<unsigned char> &image2){
    //CImg<unsigned char> image1("..\\..\\images\\lena1.bmp");
    //CImg<unsigned char> image2("..\\..\\images\\lenac_with_no_noise.bmp");
    float result1=0;
    float result2=0;
    float resultRed=0;
    float resultGreen=0;
    float resultBlue=0;

    float resultRed2=0;
    float resultGreen2=0;
    float resultBlue2=0;
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
           // result1+=(image1(x,y,0)+image1(x,y,1)+image1(x,y,2))/3;

            resultRed+=pow(image1(x,y,0),2);
            resultGreen+=pow(image1(x,y,1),2);
            resultBlue+=pow(image1(x,y,2),2);

        }
    }
    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            //result2+=(image1(x,y)-image2(x,y));
            resultRed2+=pow((image1(x,y,0)-image2(x,y,0)),2);
            resultGreen2+=pow((image1(x,y,1)-image2(x,y,1)),2);
            resultBlue2+= pow((image1(x,y,2)-image2(x,y,2)),2);
        }
    }
    std::cout<<10*log10((resultRed)/(resultRed2))<<" _ "<<10*log10((resultGreen)/(resultGreen2))<<" _ "<<10*log10((resultBlue)/(resultBlue2))<<"  "<<std::endl;
   // return 10*log10((result1*result1)/(result2*result2));
   return (10*log10((resultRed)/(resultRed2))+10*log10((resultGreen)/(resultGreen2))+10*log10((resultBlue)/(resultBlue2)))/3;
    //return 10*log10((result1*result1)/(result2*result2));
}
float peak_signal_to_noise_ratio(CImg<unsigned char> &image1,CImg<unsigned char> &image2){
    //CImg<unsigned char> image1("..\\..\\images\\lena1.bmp");
    //CImg<unsigned char> image2("..\\..\\images\\lenac_with_no_noise.bmp");
    float max;
    float result1=0;
    float result2=0;
    float resultRed2=0;
    float resultGreen2=0;
    float resultBlue2=0;

    float maxRed_value=0;
    float maxGreen_value=0;
    float maxBlue_value=0;

    float maxRed=0;
    float maxGreen=0;
    float maxBlue=0;

    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            if(image1(x,y,0)>maxRed_value){
                maxRed_value=image1(x,y,0);
            }
            if(image1(x,y,1)>maxGreen_value){
                maxGreen_value=image1(x,y,1);
            }
            if(image1(x,y,2)>maxBlue_value){
                maxBlue_value=image1(x,y,2);
            }


        }
    }

    for (int x = 0; x < image1.width(); x++) {
        for (int y = 0; y < image1.height(); y++) {
            maxRed+=pow(maxRed_value,2);
            maxGreen+=pow(maxGreen_value,2);
            maxBlue+=pow(maxBlue_value,2);

        }
    }
    for (int x = 0; x < image2.width(); x++) {
        for (int y = 0; y < image2.height(); y++) {
            //result1+=(image1(x,y)-image2(x,y));
           // result1+=((image1(x,y,0)-image2(x,y,0))+(image1(x,y,1)-image2(x,y,1))+(image1(x,y,2)-image2(x,y,2)))/3;
            resultRed2+=pow((image1(x,y,0)-image2(x,y,0)),2);
            resultGreen2+=pow((image1(x,y,1)-image2(x,y,1)),2);
            resultBlue2+=pow((image1(x,y,2)-image2(x,y,2)),2);
        }
    }
    //float max2=(image1.height()*image1.width()*255)*(image1.height()*image1.width()*255);
    float max2=max*max;
    //return 10*log10(result2*result2/result1);
    //return 10*log10((result2*result2)/(result1*result1));
    //return 10*log10(max2/(result1*result1));

    std::cout<<10*log10((maxRed)/(resultRed2))<<" _ "<<10*log10((maxGreen)/(resultGreen2))<<" _ "<<10*log10((maxBlue)/(resultBlue2))<<"  "<<std::endl;
    return (10*log10((maxRed)/(resultRed2))+10*log10((maxGreen)/(resultGreen2))+10*log10((maxBlue)/(resultBlue2)))/3;

    //  return result2;
}
float maximum_difference(CImg<unsigned char> &image1,CImg<unsigned char> &image2){
  //  CImg<unsigned char> image1("..\\..\\images\\lena1.bmp");
   // CImg<unsigned char> image2("..\\..\\images\\lenac_with_no_noise.bmp");
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

