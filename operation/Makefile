OPT_CIMG = -lpthread -Dcimg_use_vt100 -I../../CImg -Wall -W -lm -ansi -pedantic -fno-tree-pre
OPT_XWINDOWS = -I/usr/X11R6/include -Dcimg_use_xshm -Dcimg_use_xrandr -L/usr/X11R6/lib -lX11 -lXext -lXrandr
CC = gcc
CPP = g++ -O0

all: operation operation.X

OPT = -Dcimg_display=0 $(OPT_CIMG) -Dcimg_debug=2
operation: CImg.operation.cpp Makefile
	$(CPP) CImg.$@.cpp -o CImg.$@ $(OPT) && ./CImg.$@ -h

OPTX = $(OPT_XWINDOWS) $(OPT_CIMG) -Dcimg_debug=2
operation.X: CImg.operation.cpp Makefile
	$(CPP) CImg.operation.cpp -o CImg.$@ $(OPTX) && ./CImg.$@ -h

doc: operation.Doxygen Makefile CImg.operation.cpp
	./doxIt.sh

clean:
	rm -rf doc/*
	rm -f *.o
	rm -rf .libs
	rm -f CImg.operation










