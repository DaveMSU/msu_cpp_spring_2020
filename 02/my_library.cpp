#include <sstream>
#include <iostream>
#include <regex> 
#include "my_library.h"

OnBeginEnd BeginFunc = [](){};
OnBeginEnd EndFunc = [](){};
OnWord WordFunc = [](const char*){};
OnNumber NumberFunc = [](int){};

void register_on_end_callback( OnBeginEnd callback ){
	EndFunc = callback;
}

void register_on_begin_callback( OnBeginEnd callback ){
	BeginFunc = callback;
}


void register_on_number_callback( OnNumber callback ){
	NumberFunc = callback;
}

void register_on_word_callback( OnWord callback ){
	WordFunc = callback;
}

int to_int( const std::string& str ){

	int tmp = 0;
	for( int i = 0; i < str.size(); ++i )
		tmp = tmp*10 + int(str[i]) - int('0');
	return tmp;
}

void parse( const char* text ){

	BeginFunc();

	bool num_flag, sym_flag;
	std::string str;

	std::stringstream stream(text);
	std::regex isNum("[0-9]");
	std::regex isSym("[a-z|A-Z]");

	while( stream >> str ){
	
		num_flag = std::regex_search( str, isNum );
		sym_flag = std::regex_search( str, isSym );

		if( num_flag && sym_flag ) throw std::invalid_argument(str);
		if( num_flag ) NumberFunc( to_int(str) );
		if( sym_flag ) WordFunc( str.c_str() );
	}
	
	EndFunc();
}
