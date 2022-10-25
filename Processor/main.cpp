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
int main(int argc, char **argv) {
    //negative();
    /*
    brightness_modification(100);
    negative();
    contrast_modification(200);
    horizontal_flip();
    vertical_flip();
    diagonal_flip();
    shrink(0.5);
    enlarge(2);
     */
    /*
    arithmetic_mean_filter();
    std::cout<<mean_square_error()<<std::endl;
    std::cout<<peak_mean_square_error()<<std::endl;
    std::cout<<signal_to_noise_ratio()<<std::endl;
    std::cout<<peak_signal_to_noise_ratio()<<std::endl;
    std::cout<<maximum_difference()<<std::endl;
     */
   // adaptive_median_filter();




    //https://github.com/badaix/popl
    const char* name1="..\\..\\images\\lena1.bmp";
    const char* name2="..\\..\\images\\test.bmp";
    const char* name3="..\\..\\images\\test1.bmp";
    adaptive_median_filter(name1,name2);
    arithmetic_mean_filter(name1,name3);
  //  CImg<unsigned char> image(name1);

    /*

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


*/

    return 0;
}



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