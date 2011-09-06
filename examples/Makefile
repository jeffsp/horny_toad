# Horny Toad Examples Makefile
# jsp Fri Feb  6 17:13:07 CST 2009

CCFILES=$(shell ls -1 *.cc)
TARGETS=$(basename $(CCFILES))
INCLUDEPATH=.. ../../jack_rabbit
DEPENDPATH=.. ../../jack_rabbit
EXTRA_SOURCES=../argv.cc
LIBS=-lfftw3

include ../../Makefile.examples

run: all
	-./minimal_example --help
	./touch_example --help
	./bicubic_example > tmp.pgm
	display -resize 300% -filter point tmp.pgm
	rm -f tmp.pgm
