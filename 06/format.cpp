#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <vector>

using str_vector = std::vector<std::string>;

template <class T>
void type_to_string( str_vector& words, T&& t ){
	
	auto tmp = std::forward<T>(t);
	if( typeid(T) == typeid(bool) ){

		if( tmp )
			words.push_back("true");
		else 
			words.push_back("false");
	}
	else
		words.push_back(std::to_string(std::forward<T>(t)));
}

template <class T, class... ArgsT>
void type_to_string( str_vector& words, T&& t, ArgsT&... args ){


	auto tmp = std::forward<T>(t);
	if( typeid(T) == typeid(bool) ){

		if( tmp )
			words.push_back("true");
		else 
			words.push_back("false");
	}
	else
		words.push_back(std::to_string(std::forward<T>(t)));
	type_to_string(words, args...);
}

template <class... ArgsT>
std::string format( std::string line,  ArgsT&&... args ){ // Change to 'const ArgsT&... args'

	str_vector words;
	type_to_string(words, args...);
	
	std::string formated_line;
	std::string num = "";

	size_t i = 0; 
	while( i < line.size() ){

		if( line[i] == '{' ){
			
			++i;
			num = "";
			while( line[i] != '}' && i < line.size() )
				num += line[i++]; // Looking for mistake here!

			if( i >= line.size() )
				throw std::runtime_error(line);
			
			if( std::atoi(num.c_str()) > words.size() )
				throw std::runtime_error(line);

			formated_line += words[std::atoi(num.c_str())];
		}
		else
		if( line[i] == '}' )
			throw std::runtime_error(line);
		else
			formated_line += line[i];
		++i;
	}
	return formated_line;
}
