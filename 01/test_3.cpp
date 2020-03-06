#include <iostream>

void makeAllocator(size_t maxSize);
void reset();
char* alloc(size_t size);

int main(){

	makeAllocator(1);
	std::cout << "makeAllocator(1)" << std::endl;

	char* p1 = (char*)alloc(0);
	std::cout << "alloc(0)" << std::endl;
	std::cout << "p1 = " << (int*)p1 << std::endl;

	p1 = (char*)alloc(1);
	std::cout << "alloc(1)" << std::endl;
	std::cout << "p1 = " << (int*)p1 << std::endl;

	reset();
	std::cout << "reset()" << std::endl;

        return 0;
} 
