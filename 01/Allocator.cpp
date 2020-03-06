#include <iostream> 

char* main_ptr;
char* cur_ptr;
char* end_ptr;

void makeAllocator(size_t maxSize){

        main_ptr = nullptr;
        if( maxSize > 0 )
                main_ptr = (char*)malloc(maxSize);
        cur_ptr = main_ptr;
        end_ptr = main_ptr + maxSize;
}


void reset(){

        cur_ptr = main_ptr;
}


char* alloc(size_t size){

        cur_ptr += size;

        if( cur_ptr > end_ptr )// if size == maxSize it's still okey.
                return nullptr;

        return cur_ptr - size;
}
