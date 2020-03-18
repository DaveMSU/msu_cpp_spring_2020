#ifndef LIB
#define LIB

typedef void (*OnBeginEnd)();
typedef void (*OnWord)( const char* );
typedef void (*OnNumber)( int );

void register_on_begin_callback( OnBeginEnd callback );
void register_on_end_callback( OnBeginEnd callback );
void register_on_number_callback( OnNumber callback );
void register_on_word_callback( OnWord callback );

void parse( const char* text );

#endif
