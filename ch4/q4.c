#include<stdio.h>

int main( int argc, char* args[])
{
  int i = 9;
  if ( i > 10 );
  else{
    printf("执行空语句之后的else语句\n");
  }

  if(! (i > 10) ){
    printf("执行非情况下的语句\n" );
  }
  return 0;
}
