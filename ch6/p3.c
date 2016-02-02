#include<stdio.h>

#define NUL '\0'

void reverse_string( char *string )
{
  char *last_string = string;
  char *pre_string = string;
  char temp_ch = 0;

  while ( *last_string++ != NUL );
  last_string -= 2;

  while ( pre_string < last_string ) {
    temp_ch = *pre_string;
    *pre_string++ = *last_string;
    *last_string-- = temp_ch;
  }
}

int main(int argc, char const *argv[]) {
  char str[] = "abcdefghi";
  reverse_string( str );
  printf("%s\n", str );
  return 0;
}
