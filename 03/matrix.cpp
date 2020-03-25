#include <iostream>
#include <vector>
#include "matrix.h"

//----------------------------CONT_DATA:--------------------------------
Cont_data::Cont_data( size_t size , value_type* ptr ) : block_size(size), data(ptr){}

value_type& Cont_data::operator[]( size_t index ){
	
	if( index >= block_size )
		throw std::out_of_range("");
	return data[index];
}	

const value_type& Cont_data::operator[]( size_t index ) const {
	
	if( index >= block_size )
		throw std::out_of_range("");
	return data[index];
}	

Cont_data::~Cont_data(){}

//-----------------------------Matrix:----------------------------------
Matrix::Matrix( const size_t r, const size_t c ) : num_rows(r), num_cols(c){

	data = new value_type[r*c];
}

Cont_data Matrix::operator[]( size_t index ){

	if( index >= num_rows )
		throw std::out_of_range("");
	return Cont_data( num_cols, data + index*num_cols );
}

const Cont_data Matrix::operator[]( size_t index ) const {

	if( index >= num_rows )
		throw std::out_of_range("");
	return Cont_data( num_cols, data + index*num_cols );
}

Matrix& Matrix::operator*=( double value ){

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			data[ i * num_cols + j ] *= value;
	return *this;
}

bool Matrix::operator==( const Matrix& right ) const {

	if( right.get_rows() != num_rows 
			|| right.get_columns() != num_cols )
		return false;

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			if( data[ i * num_cols + j ] != right[i][j] )
				return false;
	return true;
}

bool Matrix::operator!=( const Matrix& right ) const {

	return !(*this==right);
}

size_t Matrix::get_rows() const {
	
	return num_rows;
}

size_t Matrix::get_columns() const {

	return num_cols;
}

void Matrix::print(){

	for( int i = 0; i < num_rows; ++i ){
		for( int j = 0; j < num_cols; ++j )
			std::cout << data[ i*num_cols + j ] << " ";
		std::cout << "\n";
	}
}
