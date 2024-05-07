# Makefile: A standard Makefile for main.c using MinGW-w64

V           = 3.2.4
WX          = ${HOME}/wx/wxMSW-${V}_gcc1220_x64_Dev
WXsrc       = ${HOME}/wx/wxWidgets-${V}

WARNINGS    = -Wall
GDBFLAGS    = -g
CXX         = x86_64-w64-mingw32-g++
LDLIBS      = -L$(WX)/lib/gcc1220_x64_dll -lwxmsw32u_core_gcc1220_x64 -lwxbase32u_gcc1220_x64
CPPFLAGS    = -I${WXsrc}/include -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL  -I$(WX)/lib/gcc1220_x64_dll/mswu -D__WXMSW__ -D_UNICODE $(WARNINGS) $(GDBFLAGS)

all  : main
main: main.o
	$(CXX) -o main main.o $(LDLIBS)

main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp

clean:
	/bin/rm -rf main main.o

