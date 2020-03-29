CC=g++
CFLAG = -c

all: compile

test: serializer.o test.o
	$(CC) -o hw serializer.o test.o
	@valgrind ./hw

compile: serializer.o test.o
	$(CC) -o tmp_file serializer.o test.o
	@echo "All tests has been successfully compiled!"
	@rm -rf tmp_file

serializer.o:
	$(CC) $(CFLAG) serializer.cpp

test.o:
	$(CC) $(CFLAG) test.cpp

clean:
	@rm -rf .??*
	@rm -rf *.o
	@rm -rf hw
