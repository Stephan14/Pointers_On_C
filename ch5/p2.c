#include<stdio.h>
#include<ctype.h>

int encrypt( int ch, int base )
{
  ch -= base;
  ch += 13;
  ch %= 26;
  return ch + base;
}

int main(int argc, char const *argv[]) {
  int ch;

  while ( (ch = getchar()) != EOF ) {
    if ( isalpha(ch) ) {
      if( ch >= 65 && ch <= 90 )
        ch = encrypt( ch, 'A');
      else if( ch >= 97 && ch <= 122 )
        ch = encrypt( ch, 'a');
    }
      putchar(ch);
  }

  return 0;
}
