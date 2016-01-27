#include<stdio.h>
#include<string.h>

void set_bit( char bit_array[], unsigned int bit_number )
{
    int length = strlen( bit_array );
    if( bit_number < length )
    {
      bit_array[length - bit_number - 1] = '1';
    }
}

void clear_bit( char bit_array[], unsigned int bit_number )
{
  int length = strlen( bit_array );
  if( bit_number < length )
  {
    bit_array[length - bit_number - 1] = '0';
  }
}

void assign_bit( char bit_array[], unsigned int bit_number, int value )
{
  int length = strlen( bit_array );
  if ( bit_number < length )
  {
    if ( value == 0)
    {
      bit_array[length - bit_number - 1] = '0';
    }
    else if( value == 1)
    {
      bit_array[length - bit_number - 1] = '1';
    }
  }
}

int test_bit( char bit_array[], unsigned bit_number )
{
  int length = strlen( bit_array );
  if ( bit_number < length )
  {
    if ( bit_array[bit_number] != '0')
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
int main(int argc, char const *argv[]) {
  char str[] = "0000";
  set_bit( str, 1 );
  printf("%s\n", str );
  return 0;
}
