run : main.o vector.o shared.o matrix.o
	g++ -o run main.o vector.o matrix.o

main.o : main.cpp ../src/numeric/vector.h ../src/numeric/matrix.h ../src/shared.h
	g++ -c main.cpp

shared.o : ../src/shared.cpp ../src/shared.h
	g++ -c ../src/shared.cpp

vector.o : ../src/numeric/vector.cpp ../src/numeric/vector.h ../src/shared.h
	g++ -c ../src/numeric/vector.cpp

matrix.o : ../src/numeric/matrix.cpp ../src/numeric/matrix.h ../src/numeric/vector.h ../src/shared.h ../src/shared.cpp
	g++ -c ../src/numeric/matrix.cpp

clean :
	rm run main.o matrix.o vector.o shared.o 
	


