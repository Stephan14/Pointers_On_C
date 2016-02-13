#include<stdio.h>
#include<string.h>
#include<memory.h>

#define BUFFER_LENGTH 1024
#define CHARS_LENGTH 12

static char *number[] = {"",
                            "one ", "two ", "three ", "four ", "five ",
                            "six ", "seven ", "eight ", "nine ","ten ",
                            "elven ", "twelve ", "thirteen ", "fourteen ", "fifteen ",
                            "sixteen ", "seventeen ", "eighteen ", "nineteen "
                           };
static char *degree[] = {"", "thousand ", "million ", "billion " };
static char *tens[] = {"",
                              "", "twenty ", "thirty ", "forty ", "fifty ",
                              "sixty ", "seventy ", "eighty ", "ninety "
                            };

static void do_one_group( unsigned int amount, char *buffer, char **degree )
{
  int value;

  value = amount / 1000;
  if( value > 0 )
    do_one_group( value, buffer, degree + 1 );
  amount %= 1000;

  value = amount / 100;
  if ( value > 0 ) {
    strcat( buffer, number[ value ]);
    strcat( buffer, "hundred ");
  }
  value = amount % 100;

  if ( value >= 20 )
  {
    strcat( buffer, tens[ value/10 ]);
    value %= 10;
  }

  if( value > 0 )
  {
    strcat( buffer, number[ value ]);
  }
  if ( amount > 0 )
  {
    strcat( buffer, *degree );
  }

}

void written_amount( unsigned int amount, char *buffer )
{
  if ( amount == 0 ) {
    strcpy( buffer, "zero");
  }
  else
  {
    //*buffer = '\0';
    do_one_group( amount, buffer, degree );
  }
}

int main(int argc, char const *argv[]) {
  char buffer[BUFFER_LENGTH];
  memset( buffer, 0, sizeof(buffer) );//声明数组时使用memset将数组置空

  int value = 10245;
  written_amount( value, buffer );
  printf("%s\n", buffer );

  return 0;
}
