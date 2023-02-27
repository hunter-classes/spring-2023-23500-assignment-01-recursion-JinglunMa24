main: knights.o
	g++ -o main knights.o

knights.o:
	g++ -c knights.cpp


clean:
	rm -f knights.o