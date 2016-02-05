#include<stdio.h>

long fibonacci ( int n )
{
  long result = 1;
  long pre_result = 1;
  long temp_result = 0;

  while ( n-- > 2)
  {
    temp_result = result;
    result += pre_result;
    pre_result = temp_result;
  }

  return result;
}
int main(int argc, char const *argv[]) {
  printf("%ld\n", fibonacci( 5 ) );
  return 0;
}
