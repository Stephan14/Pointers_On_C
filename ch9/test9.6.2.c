#include<stdio.h>
#include<string.h>

void print_tokens( char *line )
{
    static char whitespace[] = " \t\f\r\v\n";
    char *token;

    for( token = strtok( line, whitespace ) ;
      token != NULL;
      token = strtok( NULL, whitespace ) )
    printf("%s\n", token );
}
int main(int argc, char const *argv[]) {
  char str[] = "sdf sdfs sfe ewrwe\n dfgdg";
  print_tokens( str );
  return 0;
}
