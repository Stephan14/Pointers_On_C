#include<stdio.h>
#include<ctype.h>

#define NUL '\0'

int ascii_to_integer( char *string )
{
  int result = 0;

  while( *string  != NUL )
  {
    if( isdigit( *string ) )//判断字符是否为数字
    {
      result *= 10;
      result += *string - '0';
      string++;
    }
    else
    {
      result = 0;
      break;
    }
  }

  return result;
}
int main(int argc, char const *argv[]) {
  char str[] = "1235";
  printf("%d\n", ascii_to_integer( str ) );
  return 0;
}
