# Linux makefile for FreeImage

# This file can be generated by ./gensrclist.sh
include Makefile.srcs

# General configuration variables:
DESTDIR ?= /
INCDIR ?= $(DESTDIR)/usr/include
INSTALLDIR ?= $(DESTDIR)/usr/lib

# Converts cr/lf to just lf
DOS2UNIX = dos2unix

LIBRARIES = -lstdc++

MODULES = $(SRCS:.c=.o)
MODULES := $(MODULES:.cpp=.o)
CFLAGS ?= -O3 -fPIC -fexceptions -fvisibility=hidden
# OpenJPEG
CFLAGS += -DOPJ_STATIC
# LibRaw
CFLAGS += -DNO_LCMS
#CFLAGS += -DNO_LCMS -Wno-narrowing
# LibJXR
CFLAGS += -DDISABLE_PERF_MEASUREMENT -D__ANSI__
CFLAGS += $(INCLUDE)
CXXFLAGS ?= -O3 -fPIC -fexceptions -fvisibility=hidden -Wno-ctor-dtor-privacy
# LibJXR
CXXFLAGS += -D__ANSI__
CXXFLAGS += $(INCLUDE)

ifeq ($(shell sh -c 'uname -m 2>/dev/null || echo not'),x86_64)
	CFLAGS += -fPIC
	CXXFLAGS += -fPIC
endif

TARGET  = freeimage
STATICLIB = lib$(TARGET).a
SHAREDLIB = lib$(TARGET)-$(VER_MAJOR).$(VER_MINOR).so
LIBNAME	= lib$(TARGET).so
VERLIBNAME = $(LIBNAME).$(VER_MAJOR)
HEADER = Source/FreeImage.h



default: all

all: dist

dist: FreeImage
	mkdir -p Dist
	cp *.a Dist/
	cp *.so Dist/
	cp Source/FreeImage.h Dist/

dos2unix:
	@$(DOS2UNIX) $(SRCS) $(INCLS)

FreeImage: $(STATICLIB) $(SHAREDLIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(STATICLIB): $(MODULES)
	$(AR) r $@ $(MODULES)

$(SHAREDLIB): $(MODULES)
	$(CC) -s -shared -Wl,-soname,$(VERLIBNAME) $(LDFLAGS) -o $@ $(MODULES) $(LIBRARIES)

install:
	install -d $(INCDIR) $(INSTALLDIR)
	install -m 644 -o root -g root $(HEADER) $(INCDIR)
	install -m 644 -o root -g root $(STATICLIB) $(INSTALLDIR)
	install -m 755 -o root -g root $(SHAREDLIB) $(INSTALLDIR)
	ln -sf $(SHAREDLIB) $(INSTALLDIR)/$(VERLIBNAME)
	ln -sf $(VERLIBNAME) $(INSTALLDIR)/$(LIBNAME)	
#	ldconfig

clean:
	rm -f core Dist/*.* u2dtmp* $(MODULES) $(STATICLIB) $(SHAREDLIB) $(LIBNAME)
