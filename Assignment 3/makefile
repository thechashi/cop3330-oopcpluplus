driver: time.o main.o
	g++ -o driver time.o main.o

time.o: time.cpp time.h
	g++ -c time.cpp

main.o: main.cpp time.h
	g++ -c main.cpp

clean:
	rm -f *.o driver
