#include<stdio.h>


int main(int argc, char const *argv[]) {
    int len1, len2;
    char buffer[] = "25,142,330,Smith,J,239-4123";
    char *ptr = buffer + strspn( buffer, "\n\r\f\t\v");
    len1 = strspn( buffer, "1" );
    len2 = strcspn( buffer, "1" );

    printf("len1 = %d, len2 = %d\n", len1, len2 );
    printf("%s\n", ptr );
  return 0;
}
