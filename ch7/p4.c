#include<stdio.h>
#include<stdarg.h>

int max_list( int first_num, ... )
{
  int max = first_num;
  va_list var_arg;//1

  if( first_num >= 0 )
  {
    int temp_arg;

    va_start( var_arg, first_num );//2
    
    while ( (temp_arg = va_arg( var_arg , int )) > 0 )//3
    {
      if ( temp_arg > max )
      {
        max = temp_arg;
      }
    }

    va_end( var_arg );//4
  }

  return max;
}

int main(int argc, char const *argv[]) {
  printf("%d\n",  max_list( 6, 1, 12, 234, 56, 344, 45, -1 ));
  return 0;
}
