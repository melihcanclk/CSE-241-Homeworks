a.out:	main.o AbstractClass.o BoardVector.o BoardArray2D.o BoardArray1D.o
	g++ main.o AbstractClass.o BoardVector.o BoardArray1D.o BoardArray2D.o -o a.out
main.o:	main.cpp
	g++ -c main.cpp

BoardArray2D.o: BoardArray2D.cpp BoardArray2D.h
	g++ -c BoardArray2D.cpp

BoardArray1D.o: BoardArray1D.cpp BoardArray1D.h
	g++ -c BoardArray1D.cpp

AbstractClass.o: AbstractClass.cpp AbstractClass.h
	g++ -c AbstractClass.cpp

BoardVector.o:BoardVector.cpp BoardVector.h
	g++ -c BoardVector.cpp

clean:
	rm *.o hw1