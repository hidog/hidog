#######################################
#	測試ubuntu 撰寫 makefile       
#######################################

DEFINES 	= -DLINUX
INCPATH 	= -I../src/ \
		  -I../src/numeric/ \
                  -I../src/math/ \
		  -I~/code/gtest/include/ \
                  -I. 
LIBS		= -L~/gtest/gtest_bin/libgtest.a
CFLAGS		=
CXXFLAGS	= 
CC		= gcc
CXX		= g++
LINK		= g++

####### Output directory
#OBJECTS_DIR   = ./
####### Files

SOURCES		=	../src/shared.cpp \
			../src/numeric/vector.cpp \
			../src/numeric/matrix.cpp \
			../src/math/fraction.cpp \
			../src/math/polynomial.cpp \
			../src/math/complex.cpp \

HEADS		=	../src/shared.h \
			../src/numeric/vector.h \
			../src/numeric/matrix.h \
			../src/math/fraction.h \
			../src/math/polynomial.h \
			../src/math/complex.h \

OBJECTS		=	main.o \
			shared.o \
			vector.o \
			matrix.o \
			fraction.o \
			polynomial.o \
			complex.o \

TARGET		=	run

# compile rule

$(TARGET) :  $(OBJECTS)  
	$(LINK) -o $(TARGET) $(OBJECTS)


main.o : main.cpp $(SOURCES) $(HEADS)
	$(CXX) -c $(DEFINES) $(INCPATH) main.cpp

shared.o : $(SOURCES) $(HEADS)
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/shared.cpp

vector.o : $(SOURCES) $(HEADS)
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/numeric/vector.cpp

matrix.o : $(SOURCES) $(HEADS)
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/numeric/matrix.cpp

fraction.o : $(SOURCES) $(HEADS)
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/math/fraction.cpp

polynomial.o : $(SOURCES) $(HEADS)
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/math/polynomial.cpp
	
complex.o : $(SOURCES) $(HEADS)
	$(CXX) -c $(DEFINES) $(INCPATH) ../src/math/complex.cpp

# clean rule
.PHONY : clean
clean :
	rm $(TARGET) $(OBJECTS)
	


