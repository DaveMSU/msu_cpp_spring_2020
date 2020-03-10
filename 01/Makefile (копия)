#If in feture we will want to use gcc
CC=g++
CFLAG = -c

all: compile

test: compile test_1 test_2 test_3 test_4

compile:Allocator.o test_1.o test_2.o test_3.o test_4.o
	$(CC) -o tmp_file Allocator.o test_1.o
	$(CC) -o tmp_file Allocator.o test_2.o
	$(CC) -o tmp_file Allocator.o test_3.o
	$(CC) -o tmp_file Allocator.o test_4.o
	@echo "All tests have been successfully compiled!"

test_1: Allocator.o test_1.o
	@$(CC) -o home_work Allocator.o test_1.o
	@echo "------------\ntest_1:\n"
	@./home_work

test_2:	Allocator.o test_2.o
	@$(CC) -o home_work Allocator.o test_2.o
	@echo "------------\ntest_2:\n"
	@./home_work

test_3:	Allocator.o test_3.o
	@$(CC) -o home_work Allocator.o test_3.o
	@echo "------------\ntest_3:\n"
	@./home_work

test_4:	Allocator.o test_4.o
	@$(CC) -o home_work Allocator.o test_4.o
	@echo "------------\ntest_4:\n"
	@./home_work

Allocator.o:
	$(CC) $(CFLAG) Allocator.cpp
test_1.o:
	$(CC) $(CFLAG) test_1.cpp
test_2.o:
	$(CC) $(CFLAG) test_2.cpp
test_3.o:
	$(CC) $(CFLAG) test_3.cpp
test_4.o:
	$(CC) $(CFLAG) test_4.cpp

clean:
	@rm -rf *.o
	@rm -rf tmp_file
	@rm -rf .??*

