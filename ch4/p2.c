#include<stdio.h>
#include<math.h>

int isPrime( int n )
{
  int time = (int)(sqrt(n)+1);
  int index = 2;

  for(; index < time; index++ )
  {
      if (n % index == 0) {
        return 0;
      }
  }

  return 1;
}
int main(int argc, char const *argv[]) {
  int i = 2;
  int num = 1;

  while (i < 101) {

    if( isPrime(i) )
      if( num % 5 != 0 )
      {
        printf("%d\t", i);
        num++;
      }else
      {
        printf("%d\n", i);
        num++;
      }
    i++;
  }
  return 0;
}
/*
使用的编译命令：
  gcc p2.c -lm
*/
