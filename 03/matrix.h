#pragma once

typedef double value_type;

class Cont_data{
	

	size_t block_size;
	size_t blocks;
	value_type* data;
public:
	Cont_data( size_t, value_type* );
	value_type& operator[]( size_t );
	const value_type& operator[]( size_t ) const;
	~Cont_data();
};

class Matrix{

	size_t num_rows;
	size_t num_cols;
	value_type* data;
public:
	Matrix( const size_t r, const size_t c );
	Cont_data operator[]( size_t );
	const Cont_data operator[]( size_t ) const;
	Matrix& operator*=( double );
	bool operator==( const Matrix& tmp_matrix ) const;
	bool operator!=( const Matrix& tmp_matrix ) const;
	size_t get_rows() const;
	size_t get_columns() const;
	void print();
	~Matrix();
};
