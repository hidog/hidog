#######################################
#	測試ubuntu 撰寫 makefile       
#######################################

DEFINES = -DLINUX
INCPATH = -I../src/ -I../src/numeric/ -I.
CC	= gcc
CXX	= g++

run_objs = main.o shared.o vector.o matrix.o

run : $(run_objs)
	$(CXX) -o run $(run_objs)

main.o :  
	$(CXX) -c $(DEFINES) $(INCPATH) main.cpp

shared.o : ../src/shared.h
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/shared.cpp

vector.o : 
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/numeric/vector.cpp

matrix.o : 
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/numeric/matrix.cpp

.PHONY : clean
clean :
	rm run $(run_objs)
	


