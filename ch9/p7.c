#include<stdio.h>
#define NUL '\0'
char *my_strrchr( char *str, int ch )
{
  char *pre_answer = NULL;
  while( *str != NUL )
  {
    if( *str == ch)
      pre_answer = str;
    str++;
  }
  return pre_answer;
}

int main(int argc, char const *argv[]) {
  char str[13] = "wqerwr";
  int ch = 'w';
  printf("%s\n", my_strrchr( str, ch ) );
  return 0;
}
