a.out:	main.o AbstractClass.o BoardVector.o
	g++ main.o AbstractClass.o BoardVector.o -o a.out
main.o:	main.cpp
	g++ -c main.cpp

abstractclass.o: AbstractClass.cpp AbstractClass.h
	g++ -c AbstractClass.cpp

boardvector.o:BoardVector.cpp BoardVector.h
	g++ -c BoardVector.cpp

clean:
	rm *.o hw1