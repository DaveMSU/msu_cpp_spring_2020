#include <iostream>
#include "format.cpp"

int main(){

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "test 1:" << std::endl;
	bool a1 = true;
	std::string format_line  = "{1} + {1} = {0}";
	std::string line = format(format_line, 2, a1);
	std::cout << "format(\"" << format_line << "\", 2, a1{true})";
	std::cout << " ~ \"" << line << "\""  << "\n\n";


	std::cout << "test 2:" << std::endl;
	long long a2 = -1;
	double b2 = 123.456789;
	bool c2 = false;
	format_line  = "{2} == {0} = {1}";
	line = format(format_line, a2, c2, b2);
	std::cout << "format(\"" << format_line << "\", a1{-1}, c2{false}, b2{123.456789})";
	std::cout << " ~ \"" << line << "\""  << "\n\n";          	


	std::cout << "test 3:" << std::endl;
	size_t a3;
	a3 = 1;
	unsigned int b3 = 12345;
	unsigned long long c3 = 123456789;
	format_line = "{2} == {0} = {1";
	std::cout << "format(\"" << format_line << "\", a3{1}, b3{12345}, c3{123456789})" << std::endl;

	try{ line = format(format_line, a3, b3, c3); }
	catch( const std::runtime_error& error ){ std::cerr  << error.what(); }
	catch(...){ std::cerr << "Unknown exeption."; }	
	std::cout << "\n\n";


	std::cout << "test 4:" << std::endl;
	char a4;
	a4 = 255;
	format_line = "{1} + {1} - {1} and {2}";
	std::cout << "format(\"" << format_line << "\", a4{255}, false)" << std::endl;

	try{ line = format(format_line, a4, false); }
	catch( const std::runtime_error& error ){ std::cerr  << error.what(); }
	catch(...){ std::cerr << "Unknown exeption."; }	
	std::cout << "\n\n";


	std::cout << "test 5:" << std::endl;
	long long a5 = -1;
	format_line = "}{0} + {1} - {1} and {0}";
	std::cout << "format(\"" << format_line << "\", a4{-1}, false)" << std::endl;

	try{ line = format(format_line, a5, false); }
	catch( const std::runtime_error& error ){ std::cerr  << error.what(); }
	catch(...){ std::cerr << "Unknown exeption."; }	
	std::cout << "\n-------------------------------------" << std::endl;

	return 0;
}
