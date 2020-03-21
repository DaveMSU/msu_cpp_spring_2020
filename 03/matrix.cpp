#include <iostream>
#include <vector>
#include "matrix.h"

//----------------------------CONT_DATA:--------------------------------
cont_data::cont_data( size_t size , int amount ) : block_size(size), blocks(amount){

	std::cout << "Я в конструкторе!" << std::endl;
	data = new value_type[block_size * blocks];
}

void cont_data::set_tmp( int step ) const {

	if( step >= blocks )
	       throw std::out_of_range("");	
        tmp_data = data + step * block_size; 
}

value_type& cont_data::operator[]( int index ){
	
	if( index >= block_size )
		throw std::out_of_range("");
	return tmp_data[index];
}	

const value_type& cont_data::operator[]( int index ) const {
	
	if( index >= block_size )
		throw std::out_of_range("");
	return tmp_data[index];
}	

value_type& cont_data::get_elem( int index ){

	return data[index];
}

void cont_data::print(){
	
	while( tmp_data != (data + blocks * block_size) ){
	
		std::cout << *tmp_data << " ";
		++tmp_data;
	}
	std::cout << std::endl;
}

cont_data::~cont_data(){

	std::cout << "Я в деструкторе!" << std::endl; 
	delete [] data;
}





//-----------------------------Matrix:----------------------------------
matrix::matrix( const int& r, const int& c ) : num_rows(r), num_cols(c), memory_line(c,r) {}

cont_data& matrix::operator[]( int index ){

	memory_line.set_tmp(index);
	return memory_line;
}

const cont_data& matrix::operator[]( int index ) const {

	memory_line.set_tmp(index);
	return memory_line;
}

matrix& matrix::operator*=( double value ){

	for( int i = 0; i < num_rows; ++i )
		for( int j = 0; j < num_cols; ++j )
			memory_line.get_elem( i * num_cols + j ) *= value;
	return *this;
}

bool matrix::operator==( const matrix& right ) const {

	if( right.get_rows() != num_rows 
			|| right.get_columns() != num_cols )
		return false;

	for( int i = 0; i < num_rows; ++i )
		for( int j = 0; j < num_cols; ++j )
			if( memory_line.get_elem( i * num_cols + j ) != right[i][j] )
				return false;
	return true;
}

bool matrix::operator!=( const matrix& right ) const {

	return ~(*this==right);
}

int matrix::get_rows() const {
	
	return num_rows;
}

int matrix::get_columns() const {

	return num_cols;
}

void matrix::print(){

	for( int i = 0; i < num_rows; ++i ){
		for( int j = 0; j < num_cols; ++j )
			std::cout << memory_line.get_elem( i*num_cols + j ) << " ";
		std::cout << "\n";
	}
}
