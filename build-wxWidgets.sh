#!/bin/sh

set -xe

V=3.2.4

unzip ~/wx/wxWidgets-${V}.zip  -d wxWidgets-${V}
# FIX:
#   $ cp /usr/x86_64-w64-mingw32/include/uxtheme.h{,.SAVED}
#   $ diff /usr/x86_64-w64-mingw32/include/uxtheme.h{,.SAVED}
#   196c196
#   <     WTA_NONCLIENT = 1
#   ---
#   >     WTA_NONCLIENT = 1
#   356c356
#   < THEMEAPI GetThemeSysFont(HTHEME hTheme,int iFontId,LOGFONTW *plf);
#   ---
#   > THEMEAPI GetThemeSysFont(HTHEME hTheme,int iFontId,LOGFONT *plf);
#   ^

cd wxWidgets-${V} &&
mkdir build_w64   &&
cd build_w64      &&
    ../configure \
    --prefix=/usr/x86_64-w64-mingw32/ \
    --host=x86_64-w64-mingw32 \
    --build=x86_64-linux \
    --disable-unicode \
    --enable-monolithic \
    --disable-shared \
    CFLAGS=-m64 CXXFLAGS=-m64 LDFLAGS=-m64 &&
    make -j4

exit 0
