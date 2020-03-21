#pragma once

typedef double value_type;

class cont_data{

	size_t block_size;
	int blocks;
	value_type* data;
	mutable value_type* tmp_data;
public:
	cont_data( size_t, int );
	void set_tmp( int ) const;
	value_type& operator[]( int );
	void print();
	value_type& get_elem( int );
	~cont_data();
};

class matrix{

	int num_rows;
	int num_cols;
	cont_data memory_line;

public:
	matrix( const int& r, const int& c );
	const cont_data& operator[]( int ) const;
	cont_data& operator[]( int );
	matrix& operator*=( double );
	bool operator==( const matrix& tmp_matrix );
	int get_rows();
	int get_columns();
	void print();
};
