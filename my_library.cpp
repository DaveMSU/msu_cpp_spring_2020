#include <iostream>
#include <cctype> // для isspace().
#include <cstdlib>
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

void check_flags( const bool& num_flag, const bool& sym_flag, const std::string& buf ){

	if( num_flag && sym_flag ) throw std::invalid_argument(buf);
	else if( num_flag ) NumberFunc( atoi(buf.c_str()) );
	else if( sym_flag ) WordFunc(buf.c_str());
}

void parse( const char* text ){

	BeginFunc();

	bool num_flag = false;
	bool sym_flag = false;
	std::string buf = "";
				
	do{
		if( !isspace(*text) ){

			if( *text >= '0' && *text <= '9' ){

				if( !num_flag )
					num_flag = true;
			}
			else
				if( !sym_flag )
					sym_flag = true;
			buf += *text;
		}
		else{
			check_flags( num_flag, sym_flag, buf );
			num_flag = false;
			sym_flag = false;			
			buf = "";
		}
	}
	while(*text++);

	EndFunc();
}
