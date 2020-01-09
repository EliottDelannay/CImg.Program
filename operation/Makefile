OPT_XWINDOWS = -I/usr/X11R6/include -Dcimg_use_xshm -Dcimg_use_xrandr -L/usr/X11R6/lib -lX11 -lXext -lXrandr
#OPT = -Dcimg_display=0 -Dcimg_debug=2 -Dcimg_use_vt100
OPT = $(OPT_XWINDOWS) -lpthread -Dcimg_debug=2 -Dcimg_use_vt100 -I../../CImg -Wall -W -lm -ansi -pedantic -fno-tree-pre
CC = gcc
CPP = g++ -O0

all: operation

operation: CImg.operation.cpp Makefile
	$(CPP) CImg.$@.cpp -o CImg.$@ $(OPT)

doc: operation.Doxygen Makefile CImg.operation.cpp
	./doxIt.sh

clean:
	rm -rf doc/*
	rm -f *.o
	rm -rf .libs
	rm -f CImg.operation

