#include<stdio.h>
#include<stddef.h>
#define NUL '\0'

size_t my_strnlen( char const *string , int size )
{
  int length = 0;
  for( ; length <= size; length++ )
    if ( *string++ == NUL ) break;
  return length;
}
int main(int argc, char const *argv[]) {
  char string[10] = "sf";
  printf("%ld\n", my_strnlen( string, 10 ) );
  return 0;
}
