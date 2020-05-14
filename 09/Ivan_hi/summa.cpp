#include <iostream>
#include <cctype>      
#include <fstream>
#include <cstdlib>
#include <thread>

int main(){

	std::ifstream fin("numbers");

	int num;
	int sum = 0;
	char c = 'A';
	std::string buf;

	while( !fin.eof() ){

		buf = "";

		while( c != '\n' ){

			fin >> c;
			std::cout << c;
			if( isspace(c) ){
			
				num = atoi(buf.c_str());
				buf = "";
				sum += num;
				std::cout << sum << " " << num;
			}
			else
				buf += c;
		}
	}

	std::cout << sum;


	
	return 0;
}
