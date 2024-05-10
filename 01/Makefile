# Makefile: A standard Makefile for main.c

V           = 3.2
#ARCH        = i686
ARCH        = x86_64
CXX         = $(ARCH)-w64-mingw32-g++
CC          = $(ARCH)-w64-mingw32-gcc
WINDRES     = $(ARCH)-w64-mingw32-windres
STRIP       = $(ARCH)-w64-mingw32-strip

WX_CONFIG   = /usr/$(ARCH)-w64-mingw32/lib/wx/config/$(ARCH)-w64-mingw32-msw-ansi-static-$(V)

# if you dont want a static binary, remove this flag.
# NOTE: you will need each dependency DLL included with the executable.
LDFLAGS     = -static
CXXFLAGS    = -O3 -s

WARNINGS   := -Wall
GDBFLAGS   := -g
CXX        := `$(WX_CONFIG) --cxx`
LDLIBS     += `$(WX_CONFIG) --libs`
CPPFLAGS   += `$(WX_CONFIG) --cppflags`

all  : main
clean:
	/bin/rm -rf main main.o

compress:
	upx -9 main.exe

# END OF FILE

# wx-config [--prefix[=DIR]] [--exec-prefix[=DIR]] [--release] [--version-full]
#            [--list] [--selected-config] [--host=HOST] [--toolkit=TOOLKIT]
#            [--universal[=yes|no]] [--unicode[=yes|no]] [--static[=yes|no]]
#            [--debug[=yes|no]] [--version[=VERSION]] [--flavour=FLAVOUR]
#            [--basename] [--cc] [--cxx]
#            [--cppflags [base]] [--cxxflags [base]] [--cflags]
#            [--rescomp] [--linkdeps] [--ld] [--utility=UTIL]
#            [--libs [LIBS...]] [--optional-libs [LIBS...]]
