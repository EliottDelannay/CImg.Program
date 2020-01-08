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
  //exit on help request '-h' command line option
  if(help) return 0;
  //create a image depending of what is chosen ie (baseline, simulation)
  const std::string signal=cimg_option("--signal","baseline","image signal either baseline, simulation or files");
  //Load an image
  int baseline = 32;
  int width = 20;
  
  int height= 150;
  int w1 = 12;
  int w2 = 15;

  CImg<float> image1;
  CImg<float> image2;
  CImg<float> imageR;
  //Signal display
  if(signal=="baseline")
  {
    image1.assign(width,1,1,1, baseline);
    image1.display_graph("image 1");
    image2.assign(width,1,1,1);
    //image2.fill(baseline);
    cimg_forX(image2,i) image2(i)=baseline;
    image2.display_graph("image 2");
  }
  else if (signal=="simulation")
  {
    image1.assign(width,1,1,1, baseline);
    cimg_for_inX(image1,w1,w2,i) image1(i)=height+baseline;
    image1.display_graph("image 1");
    image2.assign(width,1,1,1,baseline);
    image2.display_graph("image 2");
  }
  else
  {
    image1.load(file_i1);
    image1.display_graph("image 1");
    image2.load(file_i2);
    image2.display_graph("image 2");
  }

  //Operation on images
  if(operation=="maximum")
  {
    imageR=image2.max(image1);
    imageR.save(file_o);
    imageR.display_graph("maximum");
  }
  else if (operation=="division")
  {
    imageR=(image1/image2);
    imageR.save(file_o);
    imageR.display_graph("division");
  }
  else if (operation=="minimum")
  {
    imageR=image2.min(image1);
    imageR.save(file_o);
    imageR.display_graph("minimum");  
  }
  else
  {
    imageR=(image1-image2);
    imageR.save(file_o);
    imageR.display_graph("subtraction");
  }
  image1.print("image 1");
  image2.print("image 2");
  imageR.print("image result");
  return 0;
}

