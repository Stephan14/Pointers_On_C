#include<stdio.h>
#define NUL '\0'

size_t my_strnlen( char const *string , int size )
{
  int length = 0;
  for( ; length <= size; length++ )
    if ( *string++ == NUL ) break;
  return length;
}

int my_strcat( char *dst, char const *src, int size )
{
  int length = size-- - (int) my_strnlen( src, size );
  if ( length > 0 )
  {
    strncat( dst, src, length );
    dst[length] = NUL;
  }
}


int main(int argc, char const *argv[]) {

  return 0;
}
