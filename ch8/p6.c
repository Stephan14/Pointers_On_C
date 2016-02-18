#include<stdio.h>
#include<stdarg.h>

int array_offset( int arrayinfo[], ... )
{
  va_list var_arg;
  int n = 0;
  int loc = 0;

  va_start( var_arg, arrayinfo );

  for( ; n < arrayinfo[0]*2 ; n += 2 )
  {
    int temp  = va_arg( var_arg, int );
    // 进行下标检测
    if ( temp >= arrayinfo[n+1] && temp <= arrayinfo[n+2] ) {
      loc *= arrayinfo[n+2] - arrayinfo[n+1] + 1;
      loc += temp - arrayinfo[n+1];
    }
    else
    {
      return -1;
    }
  }

  va_end( var_arg );

  return loc;
}

int main(int argc, char const *argv[]) {
  int arrayinfo[] = { 3, 4, 6, 1, 5, -3, 3 };

  printf("%d\n", array_offset( arrayinfo, 4, 2, -3 ));
  return 0;
}
