#pragma once

typedef int value_type;

class cont_data{

	size_t block_size;
	int blocks;
	value_type* data;
	value_type* tmp_data;
public:
	cont_data();
	cont_data( const size_t&, const int& );
	void set_tmp( int );
	value_type operator[]( const int& );
	void print();
	value_type show_elem( int );
	~cont_data();
};

class matrix{

	int num_rows;
	int num_cols;
	cont_data memory_line;

public:
	matrix( const int& r, const int& c );
	cont_data operator[]( const int& );
	void print();
};
