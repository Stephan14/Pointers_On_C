#include<stdio.h>
#include<ctype.h>
#include<string.h>

int palindrome( char *string )
{
  char *end_string = string + (int)strlen( string ) - 1;

  while( string < end_string )
  {
    if( isalpha( *string ) && isalpha( *end_string ))
    {
      if( tolower(*string++) != tolower(*end_string--) )
      {
        //string++;
        //end_string--;
        return 0;
      }
    }
    else if( !isalpha( *string ) )
      string++;
    else if( !isalpha( *end_string ) )
      end_string--;
  }

  return 1;
}

int main(int argc, char const *argv[]) {
  char str[10] = "abc,ba";
  if( palindrome( str ) )
    printf( "是回文串。\n" );
  else
    printf( "不是回文串。\n");
  return 0;
}
