#ifndef ALLOC
#define ALLOC

void makeAllocator(size_t maxSize);
void reset();
char* alloc(size_t size);
void freeAllocator();

#endif
