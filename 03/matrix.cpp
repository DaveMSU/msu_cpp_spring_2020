#include <iostream>
#include <vector>
#include "matrix.h"

//----------------------------CONT_DATA:--------------------------------
Cont_data::Cont_data( size_t size , size_t amount ) : block_size(size), blocks(amount){

	data = new value_type[block_size * blocks];
}

void Cont_data::set_tmp( size_t step ) const {

	if( step >= blocks )
	       throw std::out_of_range("");	
        tmp_data = data + step * block_size; 
}

value_type& Cont_data::operator[]( size_t index ){
	
	if( index >= block_size )
		throw std::out_of_range("");
	return tmp_data[index];
}	

const value_type& Cont_data::operator[]( size_t index ) const {
	
	if( index >= block_size )
		throw std::out_of_range("");
	return tmp_data[index];
}	

value_type& Cont_data::get_elem( size_t index ){

	return data[index];
}

void Cont_data::print(){
	
	while( tmp_data != (data + blocks * block_size) ){
	
		std::cout << *tmp_data << " ";
		++tmp_data;
	}
	std::cout << std::endl;
}

Cont_data::~Cont_data(){

	delete [] data;
}





//-----------------------------Matrix:----------------------------------
Matrix::Matrix( const size_t r, const size_t c ) : num_rows(r), num_cols(c), memory_line(c,r) {}

Cont_data& Matrix::operator[]( size_t index ){

	memory_line.set_tmp(index);
	return memory_line;
}

const Cont_data& Matrix::operator[]( size_t index ) const {

	memory_line.set_tmp(index);
	return memory_line;
}

Matrix& Matrix::operator*=( double value ){

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			memory_line.get_elem( i * num_cols + j ) *= value;
	return *this;
}

bool Matrix::operator==( const Matrix& right ) const {

	if( right.get_rows() != num_rows 
			|| right.get_columns() != num_cols )
		return false;

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			if( memory_line.get_elem( i * num_cols + j ) != right[i][j] )
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
			std::cout << memory_line.get_elem( i*num_cols + j ) << " ";
		std::cout << "\n";
	}
}
