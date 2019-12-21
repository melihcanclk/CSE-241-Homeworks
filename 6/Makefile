a.out: GTUVector.o main.o  
	g++ GTUVector.o main.o -o a.out 

main.o:main.cpp
	g++ -c main.cpp


GTUVector.o: GTUVector.h GTUVector.cpp 
	g++ -c GTUVector.cpp

clean:
	rm *.o GTUSet main a.out