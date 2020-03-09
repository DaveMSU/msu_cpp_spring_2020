// Версия до корректировочного письма от Владислава.
#include <iostream>

char* main_ptr;
char* cur_ptr;
char* end_ptr;

void makeAllocator(size_t maxSize){

	main_ptr = nullptr;
	if( maxSize > 0 )
		main_ptr = (char*)malloc(maxSize);
	cur_ptr = main_ptr;
	end_ptr = main_ptr + maxSize *  sizeof(char*);
}


void reset(){

	cur_ptr = main_ptr;
}


char* alloc(size_t size){

	std::cout << "Braa" << std::endl;
	cur_ptr += size*sizeof(char);

	if( cur_ptr > end_ptr )
		return nullptr;

	return cur_ptr - size*sizeof(char*);
}


int main(){

//Simple test:)

	makeAllocator(1024);
	char* p1 = (char*)alloc(100);
	char* p2 = (char*)alloc(200);
	reset();
	
	return 0;
}
