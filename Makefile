CC=g++
CFLAG = -c

all: compile

test: my_library.o test.o
	$(CC) -o hw my_library.o test.o
	@./hw

compile: my_library.o test.o
	$(CC) -o tmp_file my_library.o test.o
	@echo "All tests has been successfully compiled!"
	@rm -rf tmp_file

my_library.o:
	$(CC) $(CFLAG) my_library.cpp

test.o:
	$(CC) $(CFLAG) test.cpp

clean:
	@rm -rf .??*
	@rm -rf *.o
	@rm -rf hw
