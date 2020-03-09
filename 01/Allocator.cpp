#include <iostream> 

static char* main_ptr;
static char* cur_ptr;
static char* end_ptr;

void makeAllocator(size_t maxSize){

        main_ptr = nullptr;
	main_ptr = (char*)malloc(maxSize);
	if( main_ptr == nullptr ){
		std::cout << "ERROR!\nmalloc returned NULL!" << std::endl;
		throw std::bad_alloc();
	}
        cur_ptr = main_ptr;
        end_ptr = main_ptr + maxSize;
}


void reset(){

        cur_ptr = main_ptr;
}


char* alloc(size_t size){

        cur_ptr += size;
        if( cur_ptr > end_ptr ){// if size == maxSize it's still okey.
	
		cur_ptr -= size;
                return nullptr;
	}
        return cur_ptr - size;
}

void freeAllocator(){
	
	free(main_ptr);
}
