a.out: GTUSet.o GTUVector.o main.o  
	g++  GTUSet.o GTUVector.o main.o -o a.out 

main.o:main.cpp
	g++ -c main.cpp


GTUVector.o: GTUVector.h GTUVector.cpp 
	g++ -c GTUVector.cpp

clean:
	rm *.o a.out