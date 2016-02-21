#include<stdio.h>
#include<string.h>
#define NUL '\0'

char *my_strcpy( char * dst, char const *src, int size )
{
  strncpy( dst, src, size );
  *(dst+size-1) = NUL;
  return dst;
}
int main(int argc, char const *argv[]) {
  char string[5] = "sdf";
  char dst[10];
  printf("%s\n", my_strcpy( dst, string, 10) );
  return 0;
}
