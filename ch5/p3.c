#include<stdio.h>

unsigned int reverse( unsigned int value )
{
  unsigned int answer = 0;
  unsigned int i;

  /*
  用i来控制循环的次数，利用位操作，增加程序的可移植性
  for( i = 1; i != 0; i <<= 1)
  */
  for ( i = 1; i != 0 ; i <<= 1) {
    answer <<= 1;
    if( value & 1 )
      answer |= 1;
    value >>= 1;
  }

  return answer;
}
int main(int argc, char const *argv[]) {
  printf("%d\n", reverse(25) );
  return 0;
}
