#include<stdio.h>
#include<string.h>
#define NUL '\0'

/*
  用指针操作字符数组
*/
void dollars( char *dest, char const *src )
{
  int len;
  //判断指针是否为空，养成必要的习惯
  if( dest == NULL || src == NULL )
    return ;

  *dest++ = '$';
  len = strlen( src );

  if( len >= 3 )
  {
    int i;
    for( i = len - 2; i > 0; )
    {
      *dest++ = *src++;
      if( --i > 0 && i % 3 == 0 )
        *dest = ',';
    }
  }
  else
    *dest++ = '0';

  *dest++ = '.';
  *dest++ = len < 2? '0' : *src++;
  *dest++ = len < 1? '0' : *src;
  *dest = NUL;
}

int main(int argc, char const *argv[]) {
  char src[] = "111";
  char dest[10];
  dollars( dest, src );
  printf( "%s", dest );
  return 0;
}
