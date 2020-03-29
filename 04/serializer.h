#pragma onec

#include <sstream>
#include <iostream>

enum class Error
{
        NoError,
        CorruptedArchive
};

// Сериализатор:
class Serializer{

        static constexpr char Separator = ' ';
        std::ostream& out_;
public:
        explicit Serializer( std::ostream& out ) : out_(out){}
        template <class T>
        Error save( T& object );

        template <class... ArgsT>
        Error operator()( ArgsT... args );

private:
        // process использует variadic templates
        template<class T, class... ArgsT>
        Error process( T t, ArgsT... args );

        template<class T>
        Error process( T t );

        Error one_to_stream( bool     var ) const;
        Error one_to_stream( uint64_t var ) const;
};


// Десериализатор:
class Deserializer{

	std::istream& in_;
public:
	explicit Deserializer( std::istream& in ) : in_(in){};

	template<class T>
	Error load( T& object );
private:
	template <class... ArgsT>
	Error operator()( ArgsT&... args );

	template <class T, class... ArgsT>
	Error process( T& t, ArgsT&... args );

	template <class T>
	Error process( T& t );

	template<class T>
	Error one_from_stream( T& t );

	Error one_from_stream(bool& var);
	Error one_from_stream( uint64_t& var );
};

