#include<stdio.h>
#include<string.h>
#define INPUT_MAX 101


int main(int argc, char const *argv[]) {
  char buffer[INPUT_MAX];
  char whitespace[] = " \t\n\r\v\f";
  int counts = 0;

  while( fgets( buffer, INPUT_MAX, stdin ) )
  {
    char *word;
    for ( word = strtok( buffer, whitespace );
     word != NULL;
     word = strtok( NULL, whitespace ) )
    {
      if( strcmp( word, "the" ) == 0 )
        counts++;
    }
  }

  printf("%d\n", counts );
  return 0;
}
