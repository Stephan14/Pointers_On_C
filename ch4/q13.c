#include<stdio.h>
int main(int argc, char const *argv[]) {

  int which_word;
  char ch;

  scanf("%d", &which_word );
  // scanf("%c", &ch );
  // printf("%d\n", ch );

  switch( which_word )
  {
    case 1:
      printf( "who\n" );
      break;
    case 2:
      printf( "what\n" );
      break;
    case 3:
      printf( "when\n" );
      break;
    case 4:
      printf( "where\n" );
      break;
    case 5:
      printf( "why\n" );
      break;
    default:
      printf( "don't know\n" );
      break;
  }

  return 0;
}
