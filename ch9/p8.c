#include<stdio.h>
#define NUL '\0'

char *my_strnchr( char  *str, int ch, int which )
{
  int times = 0;

  while ( *str != NUL )
  {
    if( *str == ch ) times++;
    if( times == which ) return str;
    str++;
  }
  
  return NULL;
}

int main(int argc, char const *argv[]) {
  char str[15] = "qerwwrwdsg";
  char ch = 'w';
  printf("%s\n", my_strnchr( str, ch, 3) );
  return 0;
}
