#include<stdio.h>

#define TRUE '1'
#define FALSE '0'

int main(int argc, char const *argv[]) {
  char num[1001];
  int index = 0;
  char *pstr = NULL;

  for(; index <= 1000; index++ )
  {
    num[index] = TRUE;
  }
  pstr = num;

  for( index = 2; index <= 1000; index++ )
  {
    if ( num[index] == TRUE ) {
      int  temp = index+1;
      for( ; temp <= 1000; temp++ )
      {
        if( num[temp] == TRUE && temp % index == 0 )
        {
          num[temp] = FALSE;
        }
      }
    }
  }

  int number = 0;
  for( index = 2; index <= 1000; index++)
  {
    if( num[index] == TRUE )
    {
      if( number % 5 == 0) printf( "\n" );
      printf("%d\t", index );
      number++;
    }
  }
  printf("\n");
  return 0;
}
