CC=g++
CFLAG = -c

all: compile

test: matrix.o test.o
	$(CC) -o hw matrix.o test.o
	@valgrind ./hw

compile: matrix.o test.o
	$(CC) -o tmp_file matrix.o test.o
	@echo "All tests has been successfully compiled!"
	@rm -rf tmp_file

my_library.o:
	$(CC) $(CFLAG) matrix.cpp

test.o:
	$(CC) $(CFLAG) test.cpp

clean:
	@rm -rf .??*
	@rm -rf *.o
	@rm -rf hw
