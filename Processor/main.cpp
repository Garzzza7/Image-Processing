#include <iostream>
#include <algorithm>
#include "CImg.h"
#include "Task1.h"
#include "vector"
#include "popl.hpp"
using namespace cimg_library;
using namespace popl;
using namespace std;
int main(int argc,char **argv) {

/*
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
    auto edge_sharpening_option = op.add<Value<int>>("", "sedgesharp", "Edge sharpening");
    auto optimized_edge_sharpening_option = op.add<Switch>("", "optsedgesharp", "Optimized edge sharpening");

    auto dilation_option = op.add<Switch>("", "dilation", "Dilation");
    auto erosion_option = op.add<Switch>("", "erosion", "Erosion");
    auto opening_option = op.add<Switch>("", "opening", "Opening");
    auto closing_option = op.add<Switch>("", "closing", "Closing");
    auto HMT_option = op.add<Value<int>>("", "hmt", "HMT transformation");
    auto m6_option = op.add<Switch>("", "m6", "M6 variant");
    auto region_growing_option = op.add<Switch>("", "rgrowing", "Region growing");
    auto FFT_option = op.add<Switch>("", "fft", "FFT");
    auto IFFT_option = op.add<Switch>("", "ifft", "IFFT");

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


            // const char *const image = argv[1];
            // const char *const image_for_testing = argv[2];



            try{

                if(image_shrink_command->is_set() || image_enlarge_command->is_set() || contrast_command->is_set() || brightness_command->is_set() || arithmetic_mean_filter_command->is_set() || image_mean_option->is_set() || image_variance_option->is_set() || standard_devation_option->is_set() || variation_coefficient_I_option->is_set() || asymmetry_coefficient_option->is_set() || flattening_coefficient_option->is_set() || variation_coefficient_II_option->is_set() || information_source_entropy_option->is_set() || histogram_option->is_set() || power_two_third_final_probability_density_function_option->is_set() || edge_sharpening_option->is_set()){
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
                edge_sharpening(Image,edge_sharpening_option->value());
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }
            if(optimized_edge_sharpening_option->is_set()){
                optimized_edge_sharpening(Image);
                // Image.save("..\\..\\images\\Results\\arithmetic_mean_filter_output.bmp");
                Image.save(result);
            }

            if(dilation_option->is_set()){
                dilation(Image);
                Image.save(result);
            }
            if(erosion_option->is_set()){
                erosion(Image);
                Image.save(result);
            }
            if(opening_option->is_set()){
                opening(Image);
                Image.save(result);
            }
            if(closing_option->is_set()){
                closing(Image);
                Image.save(result);
            }
            if(HMT_option->is_set()){
                HMT(Image,HMT_option->value());
                Image.save(result);
            }
            if(m6_option->is_set()){
                m6(Image);
                Image.save(result);
            }
            if(region_growing_option->is_set()){
                int i,  j, threshold;
                cin>>i>>j>>threshold;
                region_growing(Image,i,j,threshold);
                Image.save(result);
            }
             if(FFT_option->is_set()){
                FFT(Image);
                Image.save(result);
            }
             if(IFFT_option->is_set()){
                IFFT(Image);
                Image.save(result);
            }

        }catch (CImgIOException exception){
        }catch (CImgArgumentException a){
        }catch (...){

        }
    }
*/
/*
    CImg<unsigned char> image("..\\..\\images\\Binary_images_(1-bit)\\lenabw.bmp");

    CImg<unsigned char> image1("..\\..\\images\\Binary_images_(1-bit)\\lollol.bmp");

    //erosion(image);
    //dilation(image);
    //opening(image);
    //closing(image);
    //HMT(image);
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
    //HTM(image,SE5);
    CImg<unsigned char> image2("..\\..\\images\\m7.bmp");

    HMT(image,3);

    */
    CImg<bool> image("..\\..\\images\\Binary_images_(1-bit)\\amo.bmp");
    //slow_dicrete_DFT(image);
    //FFT(image);
    IFFT(image);
    return 0;

}
