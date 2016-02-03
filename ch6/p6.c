#include<stdio.h>

#define MAX_VALUE 1000

int main(int argc, char const *argv[]) {
  int n_primes = 1;
  int limits = 1000;
  int bit_number;
  int number;

  for( number = 3, bit_number = 0; number <= MAX_VALUE; number += 2, bit_number += 1 )
  {
    if( number > limits )
    {
      printf("%d-%d:%d\n", limits-1000, limits, n_primes );
      n_primes = 0;
      limits += 1000;
    }
    if ( test_bit( sieve, bit_number )) {
      n_primes++;
    }
  }
  printf("%d-%d:%d\n", limits-1000, limits, n_primes );
  return 0;
}
