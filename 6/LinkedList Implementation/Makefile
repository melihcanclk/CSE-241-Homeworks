a.out:  main.o  GTUNode.o
	g++ main.o GTUNode.o -o a.out 

main.o:main.cpp
	g++ -c main.cpp
	
GTUNode.o:GTUNode.cpp
	g++ -c GTUNode.cpp

clean:
	rm *.o GTUSet main a.out