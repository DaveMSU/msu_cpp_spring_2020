#include <iostream>
#include "matrix.h"

int main(){

	matrix A(3,5);

	for( int i = 0; i < 3; ++i )
		for( int j = 0; j < 5; ++j )
			std::cout << "i: " << i << ", j: " << j << " = " << A[i][j] << std::endl;
	
//	std::cout << A[0][2] << std::endl;
//	A.print();

	return 0;
}

