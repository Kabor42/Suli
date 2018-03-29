#
# makefile az F8 feladat kiprobalasahoz.
# Nagy Dominik, M8CFQC reszere
# Datum: 2018-03-04 15:14:01
# Ez az allomany tetszes szerint modosithato, de nem celszeru
#

CXX = g++
CXXFLAGS = -Wall -pedantic
HFT = /home/a/tutors/szebi/hftest2
HEADS = f8.hpp

f8: f8_main.o 
	$(CXX) -Wall -pedantic -o f8 f8_main.o

f8_main.o: $(HEADS)

submit: f8
	$(HFT) -8


