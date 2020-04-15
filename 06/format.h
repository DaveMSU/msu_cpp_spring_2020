#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <type_traits>

using str_vector = std::vector<std::string>;

template <class T>
void push_to( str_vector& words, T&& t ){

	std::stringstream tmp;
	tmp << t;
	std::string tmp_line;
	tmp >> tmp_line;
	words.push_back(tmp_line);
}

template <class T>
void type_to_string( str_vector& words, T&& t ){
	
	push_to(words, t);
}

template <class T, class... ArgsT>
void type_to_string( str_vector& words, T&& t, ArgsT&&... args ){

	push_to(words, t);
	type_to_string(words, args...);
}

template <class... ArgsT>
std::string format( const std::string& line,  ArgsT&&... args ){

	str_vector words;
	type_to_string(words, args...);
	
	std::string formated_line;
	std::string num;

	size_t i = 0; 
	while( i < line.size() ){

		if( line[i] == '{' ){

			++i;                                                  	
		       	num = "";
		      	while( line[i] != '}' && i < line.size() )
		       		num += line[i++];

			if( i >= line.size() )
				throw std::runtime_error("Not found '}' after '{'.");

			if( std::atoi(num.c_str()) >= words.size() )
				throw std::runtime_error("Meet {n} that above the amount of argumets.");
                                                                        
			formated_line += words[std::atoi(num.c_str())];
		}
		else
		if( line[i] == '}' )
			throw std::runtime_error("Meet '}' before '{'.");
		else
			formated_line += line[i];
		++i;
	}
	return formated_line;
}
