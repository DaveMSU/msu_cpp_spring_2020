#include <iostream>
#include <vector>
#include "matrix.h"

//----------------------------CONT_DATA:--------------------------------
cont_data::cont_data(){}

cont_data::cont_data( const size_t& size , const int& amount ) : block_size(size), blocks(amount){

	data = new value_type[block_size * blocks];
}

void cont_data::set_tmp( int step ){

	if( step >= blocks )
	       throw std::out_of_range("");	
        tmp_data = data + step * block_size; 
//	std::cout << "data point: " << data << std::endl;
//	std::cout << "tmp  point: " << tmp_data << std::endl;
}

value_type cont_data::operator[]( const int& index ){
	
	if( index >= block_size )
		throw std::out_of_range("");
	return tmp_data[index];
}	

value_type cont_data::show_elem( int index ){// Try const int&;

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
	delete data;
}





//-----------------------------Matrix:----------------------------------
matrix::matrix( const int& r, const int& c ){

	num_rows = r;
	num_cols = c;
	memory_line = cont_data( num_cols, num_rows );
	//memory_line( num_cols, num_rows );
}

cont_data matrix::operator[]( const int& index ){

	memory_line.set_tmp(index);
	return  memory_line;
}

void matrix::print(){

	for( int i = 0; i < num_rows; ++i ){
		for( int j = 0; j < num_cols; ++j )
			std::cout << memory_line.show_elem( i*num_cols + j ) << "\t";
		std::cout << "\n\n";
	}
}
