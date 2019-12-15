a.out:main.o GTUContainer.o
	g++ main.o GTUContainer.o -o a.out 

main.o:main.cpp
	g++ -c main.cpp

GTUContainer.o: GTUContainer.h GTUContainer.cpp 
	g++ -c GTUContainer.cpp

clean:
	rm *.o a.out