#include<stdio.h>
#include<string.h>

void my_strncat( char *dest, char *src, int dest_len )
{
  int length = (int) strlen( dest );
  dest_len -= length + 1;
  if ( dest_len > 0 )
  {
    strncat( dest, src, dest_len );
  }
}
int main(int argc, char const *argv[]) {
  char dest[10] = "sdfdsf";
  char src[2] = "ww";
  my_strncat( dest, src, 10 );
  printf("%s\n", dest );
  return 0;
}
