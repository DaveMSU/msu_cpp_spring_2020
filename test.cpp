#include <iostream>
#include "matrix.h"

#define columns_number 6
#define rows_number 4

void fill_matrix( matrix& A, 
		  int rows = rows_number, 
		  int columns = columns_number  ){

	for( int i = 0; i < rows; ++i )
       		for( int j = 0; j < columns; ++j )
       			A[i][j] = i*j;
}

int main(){

	std::cout << std::endl;

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
	std::cout << "Кол-во строк: "    << B.get_rows()    << std::endl;
	std::cout << "Кол-во столбцов: " << B.get_columns() << std::endl;
	std::cout << std::endl;

	std::cout << "Вопрос: A == B?\nОтвет: " << (A == B) << std::endl;
	std::cout << std::endl;

	std::cout << "Вопрос: A != B?\nОтвет: " << (A != B) << std::endl;
	std::cout << std::endl;

	std::cout << "Умножаем матрицу B на " << 5 << "(число):\n";
	B *= 5;
	B.print();
	std::cout << std::endl;

	std::cout << "Вопрос: A == B?\nОтвет: " << (A == B) << std::endl;
	std::cout << std::endl;

	matrix C( 3, 3 );
	std::cout << "Создали матрицу C!" << std::endl;
	std::cout << "Переписываем матрицу: C[i][j] = i*j" << std::endl;
	fill_matrix(C, 3, 3);
	C.print();
	std::cout << "Кол-во строк: "    << C.get_rows()    << std::endl;
	std::cout << "Кол-во столбцов: " << C.get_columns() << std::endl;
	std::cout << std::endl;

	std::cout << "Вопрос: A == C?\nОтвет: " << (A == C) << std::endl;
	std::cout << std::endl;

	std::cout << "Вопрос: A != C?\nОтвет: " << (A != C) << std::endl;
	std::cout << std::endl;


	std::cout << "------------------------" << std::endl;
	std::cout << "PS:" << std::endl;

	double x = A[1][3];
	double z = C[2][2];	
	
	std::cout << "x = A[1][3] = " << x << std::endl;
	std::cout << "B[2][1]  =  " << B[2][1] << std::endl;
	std::cout << "z = C[2][2] = " << z << std::endl;
	std::cout << std::endl;

	std::cout << "x * B[2][1] * z  =  " << x * B[2][1] * z << std::endl;

	return 0;
}

