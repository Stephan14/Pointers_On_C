#include<stdio.h>
#include<ctype.h>


int main(int argc, char const *argv[]) {
  int ch;

  while ( (ch = getchar()) != EOF ) {
    if ( isalpha(ch) ) {
      if( (ch >= 65 && ch <= 78) || (ch >= 97 && ch <= 110) )
        ch += 13;
      else if( (ch >= 79 && ch <= 90) || (ch >= 111 && ch <= 122))
        ch -= 13;
    }
      putchar(ch);
  }

  return 0;
}
