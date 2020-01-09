//STL
#include <string>
// Include CImg library file and use its main namespace
#include "CImg.h"
using namespace cimg_library;

#include <iostream>
//debug macro
#if cimg_verbosity>=3
#define PR(value) std::cerr<<#value<<"="<<value<<std::endl<<std::flush;
#else
#define PR(value) ;
#endif

int main(int argc,char **argv)
{
  //Display program usage, when invoked from the command line with option '-h'.
  cimg_usage("operation between 2 images: either maximum, minimum, division or subtraction.");
  //Read image filename from the command line
  const char* file_i1=cimg_option("-i1","image1.PNG","Input  image 1");
  const char* file_i2=cimg_option("-i2","image2.PNG","Input  image 2");
  const std::string operation=cimg_option("--operation","maximum","image operation either maximum, minimum, division or subtraction");
  const char* file_o =cimg_option("-o" ,"imageS.PNG","Output image: either maximum R=max(1,2),minimum R=min(1,2),division R=1/2 or substraction R=1-2");
  //help
  const bool help=cimg_option("-h",false,"display this help.");
  
  //create a image depending of what is chosen ie (baseline, simulation)
  const std::string signal=cimg_option("--source","files","image signal either baseline, simulation or files");
  //Variables chosen by the user
   int width=cimg_option("-w",20,"width of the signal");
   int baseline=cimg_option("-bl",32,"numbers of the constant");
   int height=cimg_option("-he",100,"height of the signal");
   int startsignal=cimg_option("-ss",10,"width number of the beginning signal");
   int endsignal=cimg_option("-es",15,"width number of the end signal");

  //exit on help request '-h' command line option
  if(help) return 0;

  //constructors of images
  CImg<float> image1;
  CImg<float> image2;
  CImg<float> imageR;

  //Signal display
  if(signal=="baseline")
  {
    image1.assign(width,1,1,1, baseline);
    #if (cimg_display!=0)
       image1.display_graph("image 1");
    #endif    
    image2.assign(width,1,1,1);
    //image2.fill(baseline);
    cimg_forX(image2,i) image2(i)=baseline;
    #if cimg_display!=0   
       image2.display_graph("image 2");
    #endif
  }
  else if (signal=="simulation")
  {
    image1.assign(width,1,1,1, baseline);
    cimg_for_inX(image1,startsignal,endsignal,i) image1(i)=height+baseline;
    #if cimg_display!=0
       image1.display_graph("image 1");
    #endif
       image2.assign(width,1,1,1,baseline);
    #if cimg_display!=0
       image2.display_graph("image 2");
    #endif
  }
  else
  {
    //Load an image
    image1.load(file_i1);
    #if (cimg_display!=0)
       image1.display_graph("image 1");
    #endif
    image2.load(file_i2);
    #if (cimg_display!=0)
       image2.display_graph("image 2");
    #endif
    width = image1._width;
  }

  //Operation on images
  if(operation=="maximum")
  {
    imageR=image2.max(image1);
    imageR.save(file_o);
    #if cimg_display!=0
       imageR.display_graph("maximum");
    #endif
  }
  else if (operation=="division")
  {
    imageR.assign(width);
    cimg_forX(imageR,i) imageR(i)=(image1(i)/image2(i));
    imageR.save(file_o);
    #if cimg_display!=0
       imageR.display_graph("division");
    #endif
  }
  else if (operation=="minimum")
  {
    imageR=image2.min(image1);
    imageR.save(file_o);
    #if cimg_display!=0
       imageR.display_graph("minimum");  
    #endif
  }
  else
  {
    imageR=(image1-image2);
    imageR.save(file_o);
    #if cimg_display!=0
       imageR.display_graph("subtraction");
    #endif
  }
  image1.print("image 1");
  image2.print("image 2");
  imageR.print("image result");
  return 0;
}

