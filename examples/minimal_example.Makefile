#############################################################################
# Makefile for building: minimal_example
# Generated by qmake (2.01a) (Qt 4.7.1) on: Mon Jan 24 14:33:52 2011
# Project:  minimal_example.pro
# Template: app
# Command: /home/jsp/bin/qmake CONFIG+=debug INCLUDEPATH+=.. DEPENDPATH+=.. SOURCES+=../argv.cc LIBS+=-lfftw3 QMAKE_CXXFLAGS+=-fopenmp OBJECTS_DIR+=obj -o minimal_example.Makefile minimal_example.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -std=gnu++0x -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -std=gnu++0x -fopenmp -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I.. -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)   -lfftw3 -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/jsp/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = ../argv.cc \
		minimal_example.cc 
OBJECTS       = obj/argv.o \
		obj/minimal_example.o
DIST          = /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/debug.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf \
		minimal_example.pro
QMAKE_TARGET  = minimal_example
DESTDIR       = 
TARGET        = minimal_example

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: minimal_example.Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

minimal_example.Makefile: minimal_example.pro  /usr/lib64/qt4/mkspecs/linux-g++/qmake.conf /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/debug.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		/usr/lib64/qt4/mkspecs/features/include_source_dir.prf
	$(QMAKE) CONFIG+=debug INCLUDEPATH+=.. DEPENDPATH+=.. SOURCES+=../argv.cc LIBS+=-lfftw3 QMAKE_CXXFLAGS+=-fopenmp OBJECTS_DIR+=obj -o minimal_example.Makefile minimal_example.pro
/usr/lib64/qt4/mkspecs/common/g++-multilib.conf:
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/debug.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
/usr/lib64/qt4/mkspecs/features/include_source_dir.prf:
qmake:  FORCE
	@$(QMAKE) CONFIG+=debug INCLUDEPATH+=.. DEPENDPATH+=.. SOURCES+=../argv.cc LIBS+=-lfftw3 QMAKE_CXXFLAGS+=-fopenmp OBJECTS_DIR+=obj -o minimal_example.Makefile minimal_example.pro

dist: 
	@$(CHK_DIR_EXISTS) obj/minimal_example1.0.0 || $(MKDIR) obj/minimal_example1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) obj/minimal_example1.0.0/ && $(COPY_FILE) --parents ../argv.cc minimal_example.cc obj/minimal_example1.0.0/ && (cd `dirname obj/minimal_example1.0.0` && $(TAR) minimal_example1.0.0.tar minimal_example1.0.0 && $(COMPRESS) minimal_example1.0.0.tar) && $(MOVE) `dirname obj/minimal_example1.0.0`/minimal_example1.0.0.tar.gz . && $(DEL_FILE) -r obj/minimal_example1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) minimal_example.Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

obj/argv.o: ../argv.cc ../argv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/argv.o ../argv.cc

obj/minimal_example.o: minimal_example.cc ../argv.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/minimal_example.o minimal_example.cc

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

