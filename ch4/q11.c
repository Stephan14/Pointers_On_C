#include<stdio.h>
int main(int argc, char const *argv[]) {
  int x, y;
  
  printf("x=" );
  scanf("%d", &x);

  printf("y=" );
  scanf("%d", &y);

  if( x < y || x == y || x > y )
  {
    printf( "WRONG\n" );
  }else
  {
    printf("RIGHT\n" );
  }

  return 0;
}
