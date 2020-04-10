#include <iostream>
#include "format.cpp"

int main(){

	std::cout << "\ntest 1:";
	bool a1 = true;
	std::string format_line  = "{1} + {1} = {0}";
	std::string line = format(format_line, 2, a1);
	std::cout << "format(\"" << format_line << "\", 2, a1{true})";
	std::cout << " ~ \"" << line << "\""  << std::endl;


	std::cout << "\ntest 2:";
	long long a2 = -1;
	double b2 = 123.456789;
	bool c2 = false;
	format_line  = "{2} == {0} = {1}";
	line = format(format_line, a2, c2, b2);
	std::cout << "format(\"" << format_line << "\", a1{-1}, c2{false}, b2{123.456789})";
	std::cout << " ~ \"" << line << "\""  << std::endl;          	

	std::cout << std::endl;
	
	return 0;
}
