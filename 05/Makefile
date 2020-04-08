CC = g++
CFLAG = -c

all: compile

test: test.o BigInt.o
	$(CC) -o hw test.o BigInt.o
	@valgrind ./hw

compile: test.o BigInt.o
	$(CC) -o tmp_file BigInt.o test.o
	@echo "All tests has been successfully compiled!"
	@rm -rf tmp_file

test.o: 
	$(CC) $(CFLAG) test.cpp

BigInt.o:
	$(CC) $(CFLAG) BigInt.cpp

clean:
	@rm -rf .??*
	@rm -rf *.o
	@rm -rf hw

