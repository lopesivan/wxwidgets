# Makefile: A standard Makefile for main.c

WARNINGS    = -Wall
GDBFLAGS    = -g
CXX         = `wx-config --cxx`
LDLIBS      = `wx-config --libs`
CPPFLAGS    = `wx-config --cppflags` $(WARNINGS) $(GDBFLAGS)

all  : main
clean:
	/bin/rm -rf main main.o
# END OF FILE

