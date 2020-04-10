CC = g++
CFLAG = -c

all: compile

test: clean test.o format.o
	$(CC) -o hw test.o format.o
	valgrind ./hw

compile: clean format.o test.o
	$(CC) -o tmp_file test.o format.o
	./tmp_file
	@echo "All tests has been successfully compiled!"
	@rm -rf tmp_file

format.o:
	$(CC) $(CFLAG) format.cpp

test.o: 
	$(CC) $(CFLAG) test.cpp

clean:
	@echo "Cleaned previous calls!"
	@rm -rf .??*
	@rm -rf *.o
	@rm -rf hw
