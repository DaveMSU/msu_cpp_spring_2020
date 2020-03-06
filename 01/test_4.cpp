#include <iostream>
#define char_s sizeof(char)

void makeAllocator(size_t maxSize);
void reset();
char* alloc(size_t size);

using namespace std;

int main(){

	makeAllocator(10 * char_s);// Want to use 10 cells of memory for char.
	cout << "makeAllocator(10*char)" << endl;

	char* p = (char*)alloc(10 * char_s);
	cout << "alloc(10)" << endl;

	for( int i = 0; i < 5; ++i )
		*(p + i) = i+1;
	
	for( int i = 0; i < 7; ++i ){

		cout << "line " << i;
		cout << ":  adress = " << (int*)(p + i) << " - " << (int)*(p + i) << endl;
	}

	reset();
	cout << "reset()" << endl;

	p = (char*)alloc(5 * char_s);
	cout << "alloc(5)" << endl;

	for( int i = 0; i < 3; ++i )
		*(p + i) = (i+1)*10;

	for( int i = 0; i < 7; ++i ){

		cout << "line " << i;	
		cout << ":  adress = " << (int*)(p + i) << " - " << (int)*(p + i) << endl;
	}
	
	char* p1 = (char*)alloc(5 * char_s); //change 5 to 6,7,... and it'll return nullptr, what -
	cout << "alloc(5)" << endl;// - will lead to Segmentation fault (and it's how it slould be).

	for( int i = 0; i < 6; ++i )
		*(p1 + i) = (i+1)*7;
	for( int i = 0; i < 12; ++i ){

		cout << "line " << i;	
		cout << ":  adress = " << (int*)(p + i) << " - " << (int)*(p + i) << endl;
	}

	return 0;
}
