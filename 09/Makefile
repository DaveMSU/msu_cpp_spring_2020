CC=g++ -std=c++14


all: test

run: filesort.o
	$(CC) -o filesort filesort.cpp -lpthread
test: filesort.o checkfile.o
	$(CC) -o filesort filesort.cpp -lpthread; ./filesort "test.bin"; 
	$(CC) -o checkfile checkfile.cpp; ./checkfile

clean:
	-rm filesort filesort.o checkfile checkfile.o
