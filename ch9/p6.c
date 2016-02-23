#include<stdio.h>
#include<string.h>
#define NUL '\0'

char *my_strcpy_end(register char *dest, register char  *src )
{
  while ( (*dest++ = *src++ ) != NUL );
  return dest--;
}

int main(int argc, char const *argv[]) {
  char dest[10] = "qwr";
  char src[3] = "rew";
  printf("%s\n", my_strcpy_end( dest, src )-strlen() );
  return 0;
}
