#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
  int n;
  int *array, *ptr;

  scanf("%d", &n);
  array = malloc( (n+1) * sizeof( int ) );
  ptr = array;

  while( scanf("%d", ptr++ ) != EOF);

  int index;
  for( index = 0; index < n; index++ )
    printf("%d\n", array[index] );
    
  return 0;
}
