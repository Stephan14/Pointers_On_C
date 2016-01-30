#include<stdio.h>
#include<string.h>

#define NUL '\0'



void copy_n( char dst[], char src[], int n )
{
  int index = 0;

  while ( index < n && src[index] != NUL )
  {
    dst[index] = src[index];
    index++;
  }

  while ( index < n )
  {
    dst[index] = NUL;
    index++;
  }

  dst[index] = NUL;
}
int main(int argc, char const *argv[]) {
  char str[] = "asfsdsdfdsfsdf sdf";
  char dst[30];
  printf("%ld\n", strlen(str) );
  copy_n( dst, str, 10 );
  printf("%s\n", dst );
  return 0;
}
