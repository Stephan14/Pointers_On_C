#include <stdio.h>
#include <ctype.h>

int unprint( int ch ) 
{
    return !isprint( ch );
}

int (*test[]) ( int ch ) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    unprint
};

#define COUNT ( sizeof( test ) / sizeof( test[ 0 ] ) ) 

char *label[] = {
    "contral",
    "whitespace",
    "digit",
    "lower case",
    "upper case",
    "punction",
    "unprint"
};

int value[ COUNT ];
int total;


int 
main( int argc, char* argv[]  )
{
    int ch;

    while( ( ch = getchar() ) != EOF )
    {
        total++;

        for( int i = 0; i < COUNT; i++)
            if( test[ i ]( ch ) ) 
                value[ i ]++;
    }

    if( total == 0 )
        printf( "no charactor input \n" );
    else
        for( int i = 0; i < COUNT; i++ )
        {
            printf( " %0.3f %% of tatal charactor is %s\n ", value[ i ]* 100.0 / total, label[ i ] ); }
    return 0;
}
