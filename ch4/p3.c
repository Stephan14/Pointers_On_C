#include<stdio.h>
#include<stdlib.h>

/*
  判断输入的三条边能否组成三角形
  1.先给三个边从小到大排序
  2.判断是否有边小于0或者两个小边小于最大边
*/
double* sort( double a, double b, double c)
{
  int temp;
  double *sideFromMaxToMin = (double *) malloc( sizeof( double ) * 3 );
  /*
    排序，使a最大c最小
  */
  if( a < b )
  {
    temp = a;
    a = b;
    b = temp;
  }
  if ( a < c ) {
    temp = a;
    a = c;
    c = temp;
  }
  if ( b < c ) {
    temp = b;
    b = c;
    c = temp;
  }

  printf("%lf %lf %lf\n", a, b, c);
  sideFromMaxToMin[0] = a;
  sideFromMaxToMin[1] = b;
  sideFromMaxToMin[2] = c;

  return sideFromMaxToMin;
}

int isTriangle( double *side )
{
  double a = side[0];
  double b = side[1];
  double c = side[2];
  /*
    最小的小于0或者最小的两个边小于第三个边则不能组成三角形
  */
  if ( c <= 0 || b + c <= a ) {
      return 0;
  }

  return 1;
}

int getKindOfTriangle( double *side )
{
  if( side[0] == side[1] && side[1] == side[2] )
  {
    return 1;//等边三角形
  }
  else if( side[0] == side[1] || side[1] == side[2] )
  {
    return 2;//等腰三角形
  }
  else
  {
      return 3;//斜三角形
  }
}

int main(int argc, char const *argv[]) {


  double *side = sort( 5, 5, 5);
  if ( isTriangle( side ) ) {
    switch ( getKindOfTriangle( side ) ) {
      case 1:
          printf( "等边三角形\n" );
          break;
      case 2:
          printf( "等腰三角形\n" );
          break;
      case 3:
          printf( "普通三角形\n" );
          break;
    }
  }
  else
  {
    printf( "不能组成三角形\n" );
  }
  free( side );
  return 0;
}
