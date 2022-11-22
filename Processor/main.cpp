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
#include "vector"
#include "popl.hpp"
using namespace cimg_library;
using namespace popl;
using namespace std;

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
int main(int argc,char **argv) {


    OptionParser op("Allowed options");
    auto help_command     = op.add<Switch>("", "help", "produce help message");
    auto brightness_command = op.add<Value<int>>("", "brightness", "brightness modification");
    auto contrast_command = op.add<Value<int>>("", "contrast", "contrast modification");
    auto negative_command = op.add<Switch>("", "negative", "turn image into negative");

    auto horizontal_flip_command = op.add<Switch>("", "hflip", "Horizontal flip");
    auto vertica_flip_command = op.add<Switch>("", "vflip", "Vertical fli");
    auto diagonal_flip_command = op.add<Switch>("", "dflip", "Diagonal flip");
    auto image_shrink_command = op.add<Value<float>>("", "shrink", "Image shrinking");
    auto image_enlarge_command = op.add<Value<float>>("", "enlarge", "Image enlargement");


    auto adaptive_median_filter_command=op.add<Switch>("", "adaptive", "Adaptive median filter");
    auto arithmetic_mean_filter_command=op.add<Value<int>>("", "amean", "Arithmetic mean filter");

    auto mean_square_error_option = op.add<Switch>("", "mse", "Mean square error");
    auto peak_mean_square_error_option = op.add<Switch>("", "pmse", "Peak mean square error");
    auto signal_to_noise_ratio_option = op.add<Switch>("", "snr", "Signal to noise ratio");
    auto peak_signal_to_noise_ratio_option = op.add<Switch>("", "psnr", "Peak signal to noise ratio");
    auto maximum_difference_option = op.add<Switch>("", "md", "Maximum difference");

    auto image_variance_option = op.add<Switch>("", "cvariance", "Image variance");
    auto image_mean_option = op.add<Switch>("", "cmean", "Image mean");

    op.parse(argc, argv);
    // for (const auto& non_option_arg: op.non_option_args())cout << "This argument is not valid: " << non_option_arg <<" Make sure you pick an existing image"<< endl;

    // show unknown options (undefined ones, like "-u" or "--undefined")
    for (const auto& unknown_option: op.unknown_options())cout << "This operation is not valid: " << unknown_option <<" Try --help for a list of commands"<<endl;
    //Auto-generated help message
    if (help_command->is_set())cout << op << endl;
    else {
        try{

            CImg<unsigned char> Image;
            CImg<unsigned char> Image_for_testing;
            char* result;

            /*
            const char *const image = argv[1];
            const char *const image_for_testing = argv[2];
             */

            try{

                if(image_shrink_command->is_set() || image_enlarge_command->is_set() || contrast_command->is_set() || brightness_command->is_set() || arithmetic_mean_filter_command->is_set()){
                    Image = CImg(argv[3]);
                    result=argv[4];
                }else{
                    Image = CImg(argv[2]);
                    result=argv[3];
                }


                // if(Image==NULL){}
                // Image = CImg(image);
            }
            catch (CImgIOException exception){
                //cout<<"Cannot find the first image!!! System error: "<<exception._message<<endl;
            }
            catch (CImgArgumentException a){

            }
            if(mean_square_error_option->is_set() || peak_mean_square_error_option->is_set() || signal_to_noise_ratio_option->is_set() || peak_signal_to_noise_ratio_option->is_set() || maximum_difference_option->is_set()){
                try{
                    Image_for_testing = CImg(argv[3]);
                    // Image_for_testing = CImg(image_for_testing);
                }
                catch (CImgIOException exception){
                   // cout<<"Cannot find the testing image!!! System error: "<<exception._message<<endl;
                }
                catch (CImgArgumentException a){

                }
            }
            if(brightness_command->is_set()){
                brightness_modification(Image,brightness_command->value());
                // Image.save("..\\..\\images\\Results\\brightness_modification_output.bmp");
                Image.save(result);
            }
            if(contrast_command->is_set()){
                contrast_modification(Image,contrast_command->value());
                //Image.save("..\\..\\images\\Results\\contrast_modification_output.bmp");
                Image.save(result);
            }
            if(negative_command->is_set()){
                negative(Image);
                //Image.save("..\\..\\images\\Results\\negative_output.bmp");
                Image.save(result);
            }
            if(horizontal_flip_command->is_set()){
                horizontal_flip(Image);
                //Image.save("..\\..\\images\\Results\\horizontal_flip_output.bmp");
                Image.save(result);
            }
            if(vertica_flip_command->is_set()){
                vertical_flip(Image);
                //Image.save("..\\..\\images\\Results\\vertical_flip_output.bmp");
                Image.save(result);
            }
            if(diagonal_flip_command->is_set()){
                diagonal_flip(Image);
                //Image.save("..\\..\\images\\Results\\diagonal_flip_output.bmp");
                Image.save(result);
            }
            if(image_shrink_command->is_set()){
                if(image_shrink_command->value()<=0){
                    std::cout<<"The parameter cannot be smaller or equal 0."<<std::endl;
                }else if(image_shrink_command->value()>=1){
                    std::cout<<"The parameter cannot be bigger or equal 1."<<std::endl;
                }else{
                    shrink(Image,image_shrink_command->value());
                   // Image.save("..\\..\\images\\Results\\shrink_output.bmp");
                    Image.save(result);
                }
            }
            if(image_enlarge_command->is_set()){
                if(image_enlarge_command->value()<=1){
                    std::cout<<"The parameter should be bigger or equal 1."<<std::endl;
                }else{
                    enlarge(Image,image_enlarge_command->value());
                   // Image.save("..\\..\\images\\Results\\enlarge_output.bmp");
                    Image.save(result);
                }
            }

            if(adaptive_median_filter_command->is_set()){
                adaptive_median_filter(Image);
               // Image.save("..\\..\\images\\Results\\adaptive_median_filter_output.bmp");
                //Image.save("..\\..\\images\\Results\\adaptive_median_filter_output.bmp");
                Image.save(result);
            }
            if(arithmetic_mean_filter_command->is_set()){
                arithmetic_mean_filter(Image,arithmetic_mean_filter_command->value());
               // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }

            if(mean_square_error_option->is_set()){
                cout<<"Mean square error: "<<mean_square_error(Image,Image_for_testing)<<endl;
            }
            if(peak_mean_square_error_option->is_set()){
                cout<<"Peak mean square error: "<<peak_mean_square_error(Image,Image_for_testing)<<endl;
            }
            if(signal_to_noise_ratio_option->is_set()){
                cout<<"Signal to noise ratio: "<<signal_to_noise_ratio(Image,Image_for_testing)<<endl;
            }
            if(peak_signal_to_noise_ratio_option->is_set()){
                cout<<"Peak signal to noise ratio: "<<peak_signal_to_noise_ratio(Image,Image_for_testing)<<endl;
            }
            if(maximum_difference_option->is_set()){
                cout<<"Maximum difference: "<<maximum_difference(Image,Image_for_testing)<<endl;
            }
            if(image_variance_option->is_set()){
                cout<<"Variance: "<<Image.variance()<<endl;
            }
            if(image_mean_option->is_set()){
                cout<<"Mean: "<<Image.mean()<<endl;
            }
        }catch (CImgIOException exception){
        }catch (CImgArgumentException a){
        }catch (...){

        }
    }


    // show all non option arguments (those without "-o" or "--option")
    //for (const auto& non_option_arg: op.non_option_args())cout << "non_option_args: " << non_option_arg << endl;

    // show unknown options (undefined ones, like "-u" or "--undefined")
    //for (const auto& unknown_option: op.unknown_options())cout << "unknown_options: " << unknown_option << endl;



    /*
    CImg<unsigned char> image("..\\..\\images\\Color_images_(24-bits)\\lenac.bmp");
    CImg<unsigned char> image1("..\\..\\images\\Gray_scale_images_(8-bits)\\lena.bmp");
    //histogram(image,2);
    power_two_third_final_probability_density_function(image,0,200,10);
    kirsh_operator(image1);
    */
    return 0;
}

/*
int main(int argc, char *argv) {
    //https://github.com/badaix/popl
    const char* name1="..\\..\\images\\lena1.bmp";
    const char* name2="..\\..\\images\\test.bmp";
    const char* name3="..\\..\\images\\test1.bmp";
    adaptive_median_filter(name1,name2);
    arithmetic_mean_filter(name1,name3);
  //  CImg<unsigned char> image(name1);



    float f;
    int m, i;
    bool v;



    OptionParser op("Allowed options");
    auto help_option     = op.add<Switch>("h", "help", "produce help message");
    auto verbose_option  = op.add<Switch>("v", "verbose", "be verbose", &v);
    auto hidden_option   = op.add<Switch, Attribute::hidden>("x", "", "hidden option");
    auto double_option   = op.add<Value<double>>("d", "double", "test for double values", 3.14159265359);
    //auto brightness_option   = op.add<Value<double>>("d", "double", "test for double values", 3.14159265359);
    auto float_option    = op.add<Value<float>>("f", "float", "test for float values", 2.71828182845f, &f);
    op.add<Value<int>>("i", "int", "test for int value w/o option", 23, &i);
    auto string_option   = op.add<Value<string>>("s", "string", "test for string values");
    auto implicit_int_option = op.add<Implicit<int>>("m", "implicit", "implicit test", 42);
    auto advanced_option = op.add<Switch, Attribute::advanced>("", "advanced", "advanced option");
    auto expert_option   = op.add<Switch, Attribute::expert>("", "expert", "expert option");
    auto inactive_option = op.add<Switch>("", "inactive", "inactive option");
    inactive_option->set_attribute(Attribute::inactive);
    implicit_int_option->assign_to(&m);
    op.parse(argc, argv);

    // print auto-generated help message
    if (help_option->count() == 1)
        cout << op << "\n";
    else if (help_option->count() == 2)
        cout << op.help(Attribute::advanced) << "\n";
    else if (help_option->count() > 2)
        cout << op.help(Attribute::expert) << "\n";

    // show all non option arguments (those without "-o" or "--option")
    for (const auto& non_option_arg: op.non_option_args())
        cout << "non_option_args: " << non_option_arg << "\n";

    // show unknown options (undefined ones, like "-u" or "--undefined")
    for (const auto& unknown_option: op.unknown_options())
        cout << "unknown_options: " << unknown_option << "\n";

    // print all the configured values
    cout << "verbose_option  - is_set: " << verbose_option->is_set() << ", count: " << verbose_option->count() << ", reference: " << v << "\n";
    cout << "hidden_option   - is_set: " << hidden_option->is_set() << ", count: " << hidden_option->count() << "\n";
    cout << "double_option   - is_set: " << double_option->is_set() << ", count: " << double_option->count() << ", value: " << double_option->value() << "\n";
    cout << "string_option   - is_set: " << string_option->is_set() << ", count: " << string_option->count() << "\n";
    if (string_option->is_set())
    {
        for (size_t n=0; n<string_option->count(); ++n)
            cout << "string_option #" << n << " - value: " << string_option->value(n) << "\n";
    }
    cout << "float_option    - is_set: " << float_option->is_set() << ", value: " << float_option->value() << ", reference: " << f << "\n";
    cout << "int w/o option  - reference: " << i << "\n";
    auto int_option = op.get_option<Value<int>>('i');
    cout << "int_option      - is_set: " << int_option->is_set() << ", value: " << int_option->value() << ", reference: " << i << "\n";
    cout << "imp_int_option  - is_set: " << implicit_int_option->is_set() << ", value: " << implicit_int_option->value() << ", reference: " << m << "\n";
    cout << "advanced_option - is_set: " << advanced_option->is_set() << ", count: " << advanced_option->count() << "\n";
    cout << "expert_option   - is_set: " << expert_option->is_set() << ", count: " << expert_option->count() << "\n";




    return 0;
}
*/



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