#include<stdio.h>

#define NUL '\0'

int del_substr( char *str, char const *substr )
{
  char *pstr = NULL;
  char const *psubstr = NULL;

  while( *str != NUL )
  {
    if( is_substr( str, substr) )
      break;
    str++;
  }
  if ( *str != NUL )
  {
      pstr = str;
      psubstr = substr;
      while ( *substr != NUL )
      {
        str++;
        substr++;
      }
  }
  else
    return 0;
  while ( *pstr++ = *str++ );
  return 1;
}

/*
  判断一个字符串是否与另一个字符串的开始匹配
*/
int is_substr( char *str, char const *substr )
{
  if ( str != NULL && substr != NULL )
  {
    while ( *str != NUL && *substr != NUL )
    {
      if ( *str++ != *substr++ )
          return 0;
    }
    if( *substr == NUL )
      return 1;
    else if ( *substr != NUL )
      return 0;
  }
  else
    return 0;
}


int main(int argc, char const *argv[]) {
  char str[] = "sdfsfsfesfrttreyyr";//声明为数组而非指针
  printf("%s\n", str );

  if ( del_substr( str , "sfe") ) {
    printf("%s\n", str );
  }else{
    printf("sdgfg\n" );
  }
  return 0;
}
