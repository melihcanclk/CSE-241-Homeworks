a.out: GTUSet.o GTUVector.o  GTUIterator.o main.o  
	g++ main.o GTUVector.o GTUIterator.o GTUSet.o -o a.out 

main.o:main.cpp
	g++ -c main.cpp

GTUSet.o:GTUSet.cpp
	g++ -std=c++11 -c  GTUSet.cpp

GTUIterator.o:GTUIterator.cpp
	g++ -std=c++11 -c  GTUIterator.cpp

GTUVector.o:GTUVector.cpp
	g++ -std=c++11 -c  GTUVector.cpp

clear:
	rm *.o a.out GTUSet main GTUVector