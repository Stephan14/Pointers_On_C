#include<stdio.h>

long factorial ( int n )
{
  long result = 1;
  while ( n > 1 ) {
    result *= n--;
  }
  return result;
}
int main(int argc, char const *argv[]) {
  printf("%ld\n", factorial( 4 ));
  return 0;
}
