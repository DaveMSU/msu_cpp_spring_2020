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
		char str[1010];
		fin.getline(str, 1000);
		std::string s(str);

		for (auto c : s){

			if( isspace(c) ){

				num = atoi(buf.c_str());
				buf = "";
				sum += num;
				std::cout << num << std::endl;
			}
			else
				buf += c;

		}

		if( !buf.empty() )
			sum += atoi(buf.c_str());
	}

	std::cout << "SUM " << sum;

	fin.close();
	
	return 0;
}
