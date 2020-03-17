#include <iostream>
#include "my_library.h"

int to_int( const char* str ){
	
	int tmp = 0;
	while( *str++ )
		tmp = tmp*10 + int(*(str-1)) - int('0');
	return tmp;
}

void OnNumberFound1( const char* num ){

	std::cout << "Working func: OnNumberFound!1" << std::endl;
        std::cout << to_int(num) << std::endl;
}


void OnNumberFound2( const char* num ){

	std::cout << "Working func: OnNumberFound!2" << std::endl;
	int tmp = to_int(num);
        std::cout << tmp << "**2 = " << tmp*tmp << std::endl;
}


void OnWordFound( const char* word ){

	int cnt = 0;
	std::cout << "len(" << word << ") = ";
	while(*word++)
		cnt++;
	std::cout << cnt << std::endl;
}

void OnBeginFunc(){

	std::cout << "Parsing begin!" << std::endl;
}

void  OnEndFunc(){

	std::cout << "Parsing end!" << std::endl;
}

int main(){
	
	register_on_begin_callback(OnBeginFunc);
	register_on_end_callback(OnEndFunc);

	char line[] = "Hello dude, my name is David. 123 + 321 equalle 444	!!!";
	std::cout << "input: " << line << std::endl;
        register_on_number_callback(OnNumberFound1);
	parse(line);

	char str[] = " sinx/n = si(n)x/(n) = six = 6\n\nIt's math, bro!";
	std::cout << "input: " << str << std::endl;
	register_on_number_callback(OnNumberFound2);
	register_on_word_callback(OnWordFound);
        parse(str);



        return 0;
}	
