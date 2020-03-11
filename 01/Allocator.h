#ifndef ALLOC
#define ALLOC

extern char* main_ptr;
extern char* cur_ptr;
extern char* end_ptr;

void makeAllocator(size_t maxSize);
void reset();
char* alloc(size_t size);
void freeAllocator();

#endif
