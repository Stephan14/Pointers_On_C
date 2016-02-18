#include<stdio.h>
#include<stdarg.h>

int array_offset( int arrayinfo[], ... )
{
  va_list var_arg;
  int n = arrayinfo[0]*2;
  int loc = 0;
  int temp_index[10], index = 0;

  va_start( var_arg, arrayinfo );

  while( index < arrayinfo[0] )
  {
    temp_index[index++] = va_arg( var_arg ,int );
  }

  for( ; n > 0 ; n -= 2 )
  {
    // 进行下标检测
    if ( temp_index[--index] >= arrayinfo[n-1] && temp_index[index] <= arrayinfo[n] ) {
      loc *= arrayinfo[n] - arrayinfo[n-1] + 1;
      loc += temp_index[index] - arrayinfo[n-1];
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

  printf("%d\n", array_offset( arrayinfo, 4, 1, -1 ));
  return 0;
}
