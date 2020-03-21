#include <iostream>
#include "matrix.h"

#define columns_number 6
#define rows_number 4

void fill_matrix( matrix& A ){

	for( int i = 0; i < rows_number; ++i )
       		for( int j = 0; j < columns_number; ++j )
       			A[i][j] = i*j;
}

int main(){

	matrix A( rows_number, columns_number );
	std::cout << "Создали матрицу A!" << std::endl;

	std::cout << "Переписываем матрицу: A[i][j] = i*j" << std::endl;
	fill_matrix(A);
	A.print();

	std::cout << "Кол-во строк: "    << A.get_rows()    << std::endl;
	std::cout << "Кол-во столбцов: " << A.get_columns() << std::endl;

	std::cout << std::endl;

	int val_int = 2;
	std::cout << "Умножаем матрицу на " << val_int << ":\n";
	A *= val_int;
	A.print();
	
	std::cout << std::endl;

	double val_double = 3.1415;
	std::cout << "Умножаем матрицу на " << val_double << ":\n";
	A *= val_double;
	A.print();

	std::cout << std::endl;
	
	fill_matrix(A);
	std::cout << "Переписываем матрицу: A[i][j] = i*j" << std::endl;
	A.print();

	std::cout << std::endl;

	std::cout << "Умножаем матрицу на " << 5 << "(число):\n";
	A *= 5;
	A.print();

	std::cout << std::endl;

	matrix B( rows_number, columns_number );
	std::cout << "Создали матрицу B!" << std::endl;

	std::cout << "Переписываем матрицу: B[i][j] = i*j" << std::endl;
	fill_matrix(B);
	B.print();

	std::cout << "Вопрос: A равно B?\nОтвет: " << (A == B) << std::endl;

	return 0;
}

