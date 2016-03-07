#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
  int n, count = 0;
  int *array, *ptr;

  scanf("%d", &n);
  array = malloc( (n+1) * sizeof( int ) );
  if( array == NULL )
  {
    printf(" malloc error\n" );
    return ;
  }

  ptr = array;
  *ptr++ = n;
  count++;

  while( scanf("%d", ptr++ ) != EOF)
  {
    count++;
    if( count >= n )
    {
      array = realloc( array,  (n = 2 * n + 1) );
      if( array == NULL )
      {
        printf( " realloc errror \n" );
        return ;
      }
      else
        ptr = array + n / 2;
    }
  }
  int index;
  for( index = 0; index < count ;index++ )
  {
    printf(" %d \n", array[index]);
  }

  return 0;
}
