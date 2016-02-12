#include<stdio.h>

                          /* 辗转相除法求最大公约数*/
/*
  用递归计算M和N的最大公约数
  输入：
    m，n（m和n之间大小无所谓）
  输出：
    int类型的最大公约数
*/
int gcd( int m, int n )
{
  int r;
  if( m <= 0 || n <= 0 )   return 0;
  r = m % n;
  return r > 0 ? gcd( n, r ) : n;
}


/*
  用迭代计算M和N的最大公约数
  输入：
    m，n
  输出：

*/
int gcd2( int m, int n )
{
  int r;

  if ( m <= 0 || n <= 0 )
  {
    return 0;
  }

  do {
    r = m % n;
    m = n;
    n = r;
  } while( r > 0 );

  return m;
}


int main(int argc, char const *argv[]) {
  printf("%d\n",  gcd2( 5, 12 ) );
  return 0;
}
