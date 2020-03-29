#include <iostream>
#include "serializer.h"

// Сериализатор:
//Serializer::Serializer( std::ostream& out ) : out_(out){} // Определеяем куда мы пишем(сохраняем).

template <class T>
Error Serializer::save( T& object ){		// Работаем как с функтором.

	return object.serialize(*this);
}

template <class... ArgsT>
Error Serializer::operator()( ArgsT... args ){	
 
	return process(args...);
}

template <class T, class... ArgsT>
Error Serializer::process( T t, ArgsT... args ){
    	
	one_to_stream(t);
	return process(args...);
}

template <class T>
Error Serializer::process( T t ){

	return one_to_stream(t);
}  

Error Serializer::one_to_stream( bool var ) const {
		
	if( var )
		out_ << "true" << Separator;
	else
		out_ << "false" << Separator;
	return Error::NoError;
}

Error Serializer::one_to_stream( uint64_t var ) const {

	while( var ){ // Попробовать без while!

		out_ << char(var % 10 + '0');
		var /= 10;
	}

	return Error::NoError;
}

// Десериализатор:
//explicit Deserializer::Deserializer( std::ifstream& in ) : in_(in){}

template <class T>
Error Deserializer::load( T& object ){

	return object.Deserializer(*this);
}

template <class... ArgsT>
Error Deserializer::operator()( ArgsT&... args ){

       	return process(args...);
}

template <class T, class... ArgsT>
Error process(T& t, ArgsT&... args){

        if( realize(t) == Error::CorruptedArchive )
            return Error::CorruptedArchive;
        return process(args...);
}

template <class T>
Error Deserializer::process( T& t ){

	return one_from_stream(t);
}

template<class T>
Error Deserializer::one_from_stream( T& t ){

        return Error::CorruptedArchive;
}

Error Deserializer::one_from_stream( bool& var ){

        std::string text;
        in_ >> text;

    	if (text == "true") {

		var = true;
                return Error::NoError;
	}
        else if (text == "false") {

                var = false;
                return Error::NoError;
	}
        return Error::CorruptedArchive;
}

Error Deserializer::one_from_stream( uint64_t& var ){
                
	       	std::string text;
        	in_ >> text;
        
		if (!isdigit(text[0])) {

			return Error::CorruptedArchive;
		}
        
		try {
            		
			var = std::stoull(text);
            		return Error::NoError;
        	} 
		
		catch (std::exception &x) {
			
			return Error::CorruptedArchive;
	        }
}
