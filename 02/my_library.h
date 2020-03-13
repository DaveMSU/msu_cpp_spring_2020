#ifndef LIB
#define LIB

typedef void (*FunctionNon)();
typedef void (*Function)( const char* );

void register_on_begin_callback( FunctionNon callback );
void register_on_end_callback( FunctionNon callback );
void register_on_number_callback( Function callback );
void register_on_word_callback( Function callback );

void parse( const char* text );

#endif
