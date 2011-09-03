# Horny Toad Tests Makefile
# jsp Fri Feb  6 17:03:41 CST 2009

CCFILES=$(shell ls -1 *.cc)
TARGETS=$(basename $(CCFILES))
INCLUDEPATH=.. ../../jack_rabbit
DEPENDPATH=.. ../../jack_rabbit
EXTRA_SOURCES=../argv.cc
LIBS=-lfftw3

include ../../Makefile.tests

run: check
