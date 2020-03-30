#include <iostream>
#include <sstream>
#include <cassert>
#include <cctype>
#include "serializer.cpp"

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& source){

        return source(a, b, c);
    }

    Error deserialize(Deserializer& source){

        return source(a, b, c);
    }
};

int main(){

	Data x { 1, true, 2 };

	std::stringstream stream;

	Serializer serializer(stream);
	serializer.save(x);

	Data y { 1, true, 2 };

	Deserializer deserializer(stream);
	const Error err = deserializer.load(y);

	assert( err == Error::NoError );

	assert(x.a == y.a);
	assert(x.b == y.b);
	assert(x.c == y.c);

	return 0;
}
