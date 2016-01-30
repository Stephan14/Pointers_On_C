#include<stdio.h>
#include<math.h>
/*
  该方法对1和2两个数数不适用
*/
int isPrime( int n )
{
  int time = (int)(sqrt(n)+1);
  int index = 3;//从奇数开始计算，每次都加2

  for(; index < time; index = index + 2 )
  {
      if (n % index == 0) {
        return 0;
      }
  }

  return 1;
}
int main(int argc, char const *argv[]) {
  int i = 3;
  int num = 2;

  printf("2\t");

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
    i = i + 2;
  }
  return 0;
}
/*
使用的编译命令：
  gcc p2.c -lm
*/
