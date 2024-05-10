include ./config.mk

# -------------------------------------------------------------------------
# Do not modify the rest of this file!
# -------------------------------------------------------------------------

### Variables: ###

CPPDEPS = -MT$@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD -MP
WX_RELEASE_NODOT = 32
COMPILER_PREFIX = gcc
OBJS = \
	$(COMPILER_PREFIX)_$(PORTNAME)$(WXUNIVNAME)$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WXDLLFLAG)$(CFG)
LIBDIRNAME = ./lib/$(COMPILER_PREFIX)_$(CFG)
SETUPHDIR = \
	$(LIBDIRNAME)\$(PORTNAME)$(WXUNIVNAME)$(WXUNICODEFLAG)$(WXDEBUGFLAG)
MINIMAL_CXXFLAGS = $(__DEBUGINFO) $(__OPTIMIZEFLAG_2) $(__THREADSFLAG_4) \
	-D__WX$(TOOLKIT)__ $(__WXUNIV_DEFINE_p) $(__DEBUG_DEFINE_p) \
	$(__NDEBUG_DEFINE_p) $(__EXCEPTIONS_DEFINE_p) $(__RTTI_DEFINE_p) \
	$(__THREAD_DEFINE_p) $(__UNICODE_DEFINE_p) -I$(SETUPHDIR) -I./include \
	$(__CAIRO_INCLUDEDIR_p) -W -Wall -I. $(__DLLFLAG_p) -I./samples -DNOPCH \
	$(__RTTIFLAG_5) $(__EXCEPTIONSFLAG_6) $(CPPFLAGS) $(CXXFLAGS)
MINIMAL_OBJECTS =  \
	$(OBJS)/minimal_minimal.o

### Conditionally set variables: ###

ifeq ($(USE_GUI),0)
PORTNAME = base
endif
ifeq ($(USE_GUI),1)
PORTNAME = $(TOOLKIT_VERSION)
endif
ifeq ($(BUILD),debug)
WXDEBUGFLAG = d
endif
ifeq ($(UNICODE),1)
WXUNICODEFLAG = u
endif
ifeq ($(WXUNIV),1)
WXUNIVNAME = univ
endif
ifeq ($(SHARED),1)
WXDLLFLAG = dll
endif
ifeq ($(MONOLITHIC),0)
EXTRALIBS_FOR_BASE =
endif
ifeq ($(MONOLITHIC),1)
EXTRALIBS_FOR_BASE =
endif
ifeq ($(BUILD),debug)
__OPTIMIZEFLAG_2 = -O0
endif
ifeq ($(BUILD),release)
__OPTIMIZEFLAG_2 = -O2
endif
ifeq ($(USE_THREADS),0)
__THREADSFLAG_3 =
endif
ifeq ($(USE_THREADS),1)
__THREADSFLAG_3 = -pthread
endif
ifeq ($(USE_THREADS),0)
__THREADSFLAG_4 =
endif
ifeq ($(USE_THREADS),1)
__THREADSFLAG_4 = -D_THREAD_SAFE -pthread
endif
ifeq ($(USE_RTTI),0)
__RTTIFLAG_5 = -fno-rtti
endif
ifeq ($(USE_RTTI),1)
__RTTIFLAG_5 =
endif
ifeq ($(USE_EXCEPTIONS),0)
__EXCEPTIONSFLAG_6 = -fno-exceptions
endif
ifeq ($(USE_EXCEPTIONS),1)
__EXCEPTIONSFLAG_6 =
endif
ifeq ($(WXUNIV),1)
__WXUNIV_DEFINE_p = -D__WXUNIVERSAL__
endif
ifeq ($(DEBUG_FLAG),0)
__DEBUG_DEFINE_p = -DwxDEBUG_LEVEL=0
endif
ifeq ($(BUILD),release)
__NDEBUG_DEFINE_p = -DNDEBUG
endif
ifeq ($(USE_EXCEPTIONS),0)
__EXCEPTIONS_DEFINE_p = -DwxNO_EXCEPTIONS
endif
ifeq ($(USE_RTTI),0)
__RTTI_DEFINE_p = -DwxNO_RTTI
endif
ifeq ($(USE_THREADS),0)
__THREAD_DEFINE_p = -DwxNO_THREADS
endif
ifeq ($(UNICODE),0)
__UNICODE_DEFINE_p = -DwxUSE_UNICODE=0
endif
ifeq ($(UNICODE),1)
__UNICODE_DEFINE_p = -D_UNICODE
endif
ifeq ($(USE_CAIRO),1)
__CAIRO_INCLUDEDIR_p = -I$(CAIRO_ROOT)/include/cairo
endif
ifeq ($(SHARED),1)
__DLLFLAG_p = -DWXUSINGDLL
endif
ifeq ($(MONOLITHIC),1)
__WXLIB_MONO_p = \
	-lwx$(PORTNAME)$(WXUNIVNAME)$(WX_RELEASE_NODOT)$(WXUNICODEFLAG)$(WXDEBUGFLAG)$(WX_LIB_FLAVOUR)
endif
ifeq ($(MONOLITHIC),1)
ifeq ($(USE_STC),1)
__LIB_SCINTILLA_IF_MONO_p = -lwxscintilla$(WXDEBUGFLAG)
endif
endif
ifeq ($(USE_GUI),1)
__LIB_TIFF_p = -lwxtiff$(WXDEBUGFLAG)
endif
ifeq ($(USE_GUI),1)
__LIB_JPEG_p = -lwxjpeg$(WXDEBUGFLAG)
endif
ifeq ($(USE_GUI),1)
__LIB_PNG_p = -lwxpng$(WXDEBUGFLAG)
endif
ifeq ($(BUILD),debug)
ifeq ($(DEBUG_INFO),default)
__DEBUGINFO = -g
endif
endif
ifeq ($(BUILD),release)
ifeq ($(DEBUG_INFO),default)
__DEBUGINFO =
endif
endif
ifeq ($(DEBUG_INFO),0)
__DEBUGINFO =
endif
ifeq ($(DEBUG_INFO),1)
__DEBUGINFO = -g
endif


all: $(OBJS)
$(OBJS):
	@mkdir -p $(OBJS)

### Targets: ###

all: $(OBJS)/minimal

install:

uninstall:

clean:
	rm -f $(OBJS)/*.o
	rm -f $(OBJS)/*.d
	rm -f $(OBJS)/minimal

$(OBJS)/minimal: $(MINIMAL_OBJECTS)
	$(CXX) -o $@ $(MINIMAL_OBJECTS)  $(__DEBUGINFO) $(__THREADSFLAG_3) -L$(LIBDIRNAME)   $(LDFLAGS)  $(__WXLIB_MONO_p) $(__LIB_SCINTILLA_IF_MONO_p) $(__LIB_TIFF_p) $(__LIB_JPEG_p) $(__LIB_PNG_p)   -lwxzlib$(WXDEBUGFLAG) -lwxregex$(WXUNICODEFLAG)$(WXDEBUGFLAG) -lwxexpat$(WXDEBUGFLAG) $(EXTRALIBS_FOR_BASE)

$(OBJS)/minimal_minimal.o: ./minimal.cpp
	$(CXX) -c -o $@ $(MINIMAL_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all install uninstall clean


# Dependencies tracking:
-include $(OBJS)/*.d
