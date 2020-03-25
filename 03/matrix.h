#pragma once

typedef double value_type;

class Cont_data{
	

	size_t block_size;
	size_t blocks;
	value_type* data;
	mutable value_type* tmp_data;
public:
	Cont_data( size_t, size_t );
	void set_tmp( size_t ) const;
	value_type& operator[]( size_t );
	const value_type& operator[]( size_t ) const;
	void print();
	value_type& get_elem( size_t );
	~Cont_data();
};

class Matrix{

	size_t num_rows;
	size_t num_cols;
	mutable Cont_data memory_line;
public:
	Matrix( const size_t r, const size_t c );
	const Cont_data& operator[]( size_t ) const;
	Cont_data& operator[]( size_t );
	Matrix& operator*=( double );
	bool operator==( const Matrix& tmp_matrix ) const;
	bool operator!=( const Matrix& tmp_matrix ) const;
	size_t get_rows() const;
	size_t get_columns() const;
	void print();
};
