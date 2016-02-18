#include<stdio.h>


int identity_matrix( int (*matrix)[10], int size )
{
  int x, y;
  for( x = 0, y = 0; x < size; x++,y++ )
  {
    //printf("x = %d, y = %d\n", x , y );
    if( matrix[x][y] != 1 )
      return 0;
  }
  return 1;
}
int main(int argc, char const *argv[]) {
  int matrix[10][10] = {
    { 1},
    { 0, 1},
    { 0, 0, 1},
    { 0, 0, 0, 1},
    { 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
  };
  if ( identity_matrix( matrix, 10 ) ) {
    printf( "该矩阵是单位矩阵\n" );
  }
  else
    printf("该矩阵不是单位矩阵\n");
  return 0;
}
