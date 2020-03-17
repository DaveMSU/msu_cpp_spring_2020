#include <iostream>
#include "my_library.h"

FunctionNon OnBegin = [](){};
FunctionNon OnEnd = [](){};
Function WordFunc = [](const char*){};
Function NumberFunc = [](const char*){};

void register_on_end_callback( FunctionNon callback ){

	OnEnd = callback;
}


void register_on_begin_callback( FunctionNon callback ){

	OnBegin = callback;
}


void register_on_number_callback( Function callback ){

	NumberFunc = callback;
}


void register_on_word_callback( Function callback ){

	WordFunc = callback;
}


void parse( const char* text ){

	OnBegin();

	bool num_flag = false;
	bool sym_flag = false;

	std::string buf = "";
				
	do{
		if( *text != ' ' && 
			*text != '\t' &&
			    *text != '\n' &&
				*text != 0){

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
			if( num_flag & sym_flag )
				throw std::invalid_argument(buf);
			else
			if( num_flag )
				NumberFunc(buf.c_str());
			else
			if( sym_flag )
				WordFunc(buf.c_str());
			
			num_flag = false;
			sym_flag = false;			
			buf = "";
		}
	}
	while(*text++);

	OnEnd();
}	
