#include<stdio.h>
#include<string.h>

int count_chars( char const *str, char const *chars )
{
    int counts = 0;

    while( ( str = strpbrk( str, chars ) ) != NULL )
    {
      counts++;
      str++;
    }

    return counts;
}

int main(int argc, char const *argv[]) {
  char str[10] = "wqretwt";
  char chars[3] = "qrr";
  printf("%d\n", count_chars( str, chars ) );
  return 0;
}
