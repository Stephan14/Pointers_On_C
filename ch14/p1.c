#include <stdio.h>

void print_ledger_long( int arg )
{
    printf("print_ledger_long");
}


void print_ledger_detailed( int arg )
{
    printf("print_ledger_detailed");
}

void print_ledger_default( int arg )
{
    printf("print_ledger_default"); 
}

void print_ledger( int arg  )
{
#if defined OPTION_LONG
    print_ledger_long( arg );
#elif defined OPTION_DETAILED
    print_ledger_detailed( arg );
#else
    print_ledger_default( arg );
#endif
}
int main( int argc, char* argv[] )
{
    print_ledger( 5 );
    return 0;
}
