#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define INPUT_MAX 129

int main(int argc, char const *argv[]) {
  char input[INPUT_MAX];
  int index = 0;
  int length = 0;

  while( fgets(input, INPUT_MAX, stdin )!= NULL )
  {

      for ( index = 0, length = strlen( input ); index < length ; index++) {
        input[index] = tolower( input[index] );
      }
      printf("%s\n", input );
  }

  return 0;
}
