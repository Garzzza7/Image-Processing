#include <iostream>
#include <algorithm>
#include "CImg.h"
#include "Task1.h"
/*
#include "image_adjustments.cpp"
#include "image_flip.cpp"
#include "image_filter.cpp"
#include "image_comparison.cpp"

#include "image_characteristics.cpp"
#include "image_histogram.cpp"
*/

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
    auto help_command = op.add<Switch>("", "help", "produce help message");
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

    auto image_mean_option = op.add<Value<int>>("", "cmean", "Mean");
    auto image_variance_option = op.add<Value<int>>("", "cvariance", "Variance");
    auto standard_devation_option = op.add<Value<int>>("", "cstdev", "Standard deviation");
    auto variation_coefficient_I_option = op.add<Value<int>>("", "cvarcoi", "Variation coefficient I");
    auto asymmetry_coefficient_option = op.add<Value<int>>("", "casyco", "Asymmetry coefficient");
    auto flattening_coefficient_option = op.add<Value<int>>("", "cflaco", "Flattening coefficient");
    auto variation_coefficient_II_option = op.add<Value<int>>("", "cvarcoii", "Variation coefficient II");
    auto information_source_entropy_option = op.add<Value<int>>("", "centropy", "Information source entropy");

    auto histogram_option  = op.add<Value<int>>("", "histogram", "Histogram");
    auto power_two_third_final_probability_density_function_option = op.add<Value<int>>("", "hpower", "Power 2/3 final probability density function");
    auto kirsh_operator_option = op.add<Switch>("", "okirsf", "Kirsh operator");
    auto edge_sharpening_option = op.add<Switch>("", "sedgesharp", "Edge sharpening");

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

                if(image_shrink_command->is_set() || image_enlarge_command->is_set() || contrast_command->is_set() || brightness_command->is_set() || arithmetic_mean_filter_command->is_set() || image_mean_option->is_set() || image_variance_option->is_set() || standard_devation_option->is_set() || variation_coefficient_I_option->is_set() || asymmetry_coefficient_option->is_set() || flattening_coefficient_option->is_set() || variation_coefficient_II_option->is_set() || information_source_entropy_option->is_set() || histogram_option->is_set() || power_two_third_final_probability_density_function_option->is_set() ){
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

            if(image_mean_option->is_set()){
                cout<<"Mean: "<<image_mean(Image,image_mean_option->value())<<endl;
            }
            if(image_variance_option->is_set()){
                cout<<"Variance: "<<image_variance(Image,image_variance_option->value())<<endl;
            }
            if(standard_devation_option->is_set()){
                cout<<"Standard deviation: "<<standard_devation(Image,standard_devation_option->value())<<endl;
            }
            if(variation_coefficient_I_option->is_set()){
                cout<<"Variation coefficient I: "<<variation_coefficient_I(Image,variation_coefficient_I_option->value())<<endl;
            }
            if(asymmetry_coefficient_option->is_set()){
                cout<<"Asymmetry coefficient: "<< asymmetry_coefficient(Image,asymmetry_coefficient_option->value())<<endl;
            }
            if(flattening_coefficient_option->is_set()){
                cout<<"Flattening coefficient: "<<flattening_coefficient(Image,flattening_coefficient_option->value())<<endl;
            }
            if(variation_coefficient_II_option->is_set()){
                cout<<"Variation coefficient II: "<<variation_coefficient_II(Image,variation_coefficient_II_option->value())<<endl;
            }
            if(information_source_entropy_option->is_set()){
                cout<<"Information source entropy: "<<information_source_entropy(Image,information_source_entropy_option->value())<<endl;
            }

            /*
                 auto histogram_option  = op.add<Value<int>>("", "histogram", "Histogram");
    auto power_two_third_final_probability_density_function_option = op.add<Value<int>>("", "hpower", "Power 2/3 final probability density function");
    auto kirsh_operator_option = op.add<Switch>("", "okirsf", "Kirsh operator");
    auto edge_sharpening_option = op.add<Switch>("", "sedgesharp", "Edge sharpening");
             */
            if(histogram_option->is_set()){
                histogram(Image,histogram_option->value());
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(power_two_third_final_probability_density_function_option->is_set()){
                int maximum,minimmum;
                cout<<"Give maximum: "<<endl;
                cin>>maximum;
                cout<<"Give minimum: "<<endl;
                cin>>minimmum;
                power_two_third_final_probability_density_function(Image,power_two_third_final_probability_density_function_option->value(),maximum,minimmum);
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(kirsh_operator_option->is_set()){
                kirsh_operator(Image);
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(edge_sharpening_option->is_set()){
                edge_sharpening(Image);
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }



            /*
    auto image_mean_option = op.add<Value<int>>("", "cmean", "Mean");
    auto image_variance_option = op.add<Value<int>>("", "cvariance", "Variance");
    auto standard_devation_option = op.add<Value<int>>("", "cstdev", "Standard deviation");
    auto variation_coefficient_I_option = op.add<Value<int>>("", "cvarcoi", "Variation coefficient I");
    auto asymmetry_coefficient_option = op.add<Value<int>>("", "casyco", "Asymmetry coefficient");
    auto flattening_coefficient_option = op.add<Value<int>>("", "cflaco", "Flattening coefficient");
    auto variation_coefficient_II_option = op.add<Value<int>>("", "cvarcoii", "Variation coefficient II");
    auto information_source_entropy_option = op.add<Value<int>>("", "centropy", "Information source entropy");
             */

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
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */

    /*
    CImg<unsigned char> image("..\\..\\images\\Color_images_(24-bits)\\lenac.bmp");
    CImg<unsigned char> image1("..\\..\\images\\Gray_scale_images_(8-bits)\\lena.bmp");
    //histogram(image,2);
    power_two_third_final_probability_density_function(image,0,200,10);
    kirsh_operator(image1);
    */
            /*
    CImg<unsigned char> image("..\\..\\images\\\\Color_images_(24-bits)-with_noise\\Impulse_noise\\lenac_impulse3.bmp");
    CImg<unsigned char> image1("..\\..\\images\\Gray_scale_images_(8-bits)\\lena.bmp");
    CImg<unsigned char> image2("..\\..\\images\\Color_images_(24-bits)\\lenac.bmp");
    CImg<unsigned char> image3("..\\..\\images\\Gray_scale_images (8-bits)_with_noise\\Impulse_noise\\lena_impulse3.bmp");

    // min_filter(image1,1);
    //min_filter_test(image1);
    // kirsh_operator(image1);
    //edge_sharpening(image1);
    power_two_third_final_probability_density_function(image3,0,200,10);

    std::cout<<"mean "<<image_mean(image2,0)<<" | "<<image_mean(image2,1)<<" | "<<image_mean(image2,2)<<" | "<<std::endl;
    std::cout<<"variance "<<image_variance(image2,0)<<" | "<<image_variance(image2,1)<<" | "<<image_variance(image2,2)<<" | "<<std::endl;
    std::cout<<"standard_devation "<<standard_devation(image2,0)<<" | "<<standard_devation(image2,1)<<" | "<<standard_devation(image2,2)<<" | "<<std::endl;
    std::cout<<"variation_coefficient_I "<<variation_coefficient_I(image2,0)<<" | "<<variation_coefficient_I(image2,1)<<" | "<<variation_coefficient_I(image2,2)<<" | "<<std::endl;
    std::cout<<"asymmetry_coefficient "<<asymmetry_coefficient(image2,0)<<" | "<<asymmetry_coefficient(image2,1)<<" | "<<asymmetry_coefficient(image2,2)<<" | "<<std::endl;
    std::cout<<"flattening_coefficient "<<flattening_coefficient(image2,0)<<" | "<<flattening_coefficient(image2,1)<<" | "<<flattening_coefficient(image2,2)<<" | "<<std::endl;
    std::cout<<"variation_coefficient_II "<<variation_coefficient_II(image2,0)<<" | "<<variation_coefficient_II(image2,1)<<" | "<<variation_coefficient_II(image2,2)<<" | "<<std::endl;
    std::cout<<"information_source_entropy "<<information_source_entropy(image2,0)<<" | "<<information_source_entropy(image2,1)<<" | "<<information_source_entropy(image2,2)<<" | "<<std::endl;
             */
    return 0;
}

