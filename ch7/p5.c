#include<stdio.h>
#include<stdarg.h>

#define NUL '\0'
void print_int( int n )
{
  printf("%d\n", n );
}

void print_float( double n )
{
  printf("%lf\n", n );
}

int  my_printf( char *format , ... )
{
  int num = 0;
  char ch;
  char *str;
  va_list var_list;

  va_start( var_list , format );

  while ( (ch = *format++ ) !=  NUL )
  {
    if ( ch != '%') {
      putchar( ch );
      continue;
    }

    switch ( *format != NUL ?  *format++ : NUL )//使用条件表达式
    {
      case 'd':
        print_int( va_arg( var_list , int ) );
        break;
      case 'f':
        print_float( va_arg( var_list , double ) );
        break;
      case 's':
        str = va_arg( var_list, char * );//可以使用任何类型
        while ( *str != NUL ) {
          putchar( *str++ );
        }
        break;
      case 'c':
        num--;
        break;
    }
    num++;
  }

  va_end( var_list );

  return num;
}
int main(int argc, char const *argv[]) {
  int d = 14;
  printf("%d\n", my_printf("%d===%f sdfds %f%e%f", d, 3.34, 4.55555, 67868, 89.99) );
  return 0;
}
