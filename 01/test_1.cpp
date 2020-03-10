#include <iostream>
#include "Allocator.h"

int main(){

	makeAllocator(1024);
	std::cout << "makeAllocator(1024)" << std::endl;

        char* p1 = (char*)alloc(128);
	std::cout << "alloc(128)" << std::endl;
	std::cout << "p1 = " << (int*)p1 << std::endl; // can't see (char*)

        char* p2 = (char*)alloc(256);
	std::cout << "alloc(256)" << std::endl;
	std::cout << "p2 = " << (int*)p2 << std::endl;

	p1 = (char*)alloc(640); // Have to return normal adress, not nullptr.	
	std::cout << "alloc(128+512)" << std::endl;
	std::cout << "p1 = " << (int*)p1 << std::endl;
	std::cout << "p1 == nullptr: " << (p1 == nullptr) << std::endl;

	p1 = (char*)alloc(1); // Have to return nullptr.	
	std::cout << "alloc(1)" << std::endl;
	std::cout << "p1 = " << (int*)p1 << std::endl;
	std::cout << "p1 == nullptr: " << (p1 == nullptr) << std::endl;

        reset();
	std::cout << "reset()" << std::endl;
	std::cout << "p1 = " << (int*)p1 << std::endl;

	p1 = (char*)alloc(128);
	std::cout << "alloc(128)" << std::endl;
	std::cout << "p1 = " << (int*)p1 << std::endl;

	freeAllocator();

        return 0;
} 
