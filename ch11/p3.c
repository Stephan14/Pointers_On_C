#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define NUL '\0'

char *readstring()
{
  int ch;
  int buffer_length = 0;
  char *buffer = NULL ;
  int counter = 0;
  char *buffer_ptr = buffer;

  do {
    ch = getchar();
    if( ch == EOF || ch == '\n' )//及时有空格也可以继续输入
      ch = NUL;
    if( counter >= buffer_length )
    {
      buffer_length += 256;
      buffer = (char *)realloc( buffer, buffer_length );
      assert( buffer != NULL );//代替if( buffer == NULL ){}
      buffer_ptr = buffer + counter;//更新buffer_ptr的指针，有可能buffer的地址改变
    }

    *buffer_ptr++ = ch;
    counter++;

  } while( ch != NUL );

  buffer_ptr = (char *) malloc( counter * sizeof( char ));
  assert( buffer_ptr != NULL );
  strcpy( buffer_ptr, buffer );
  free( buffer );
  return buffer_ptr;
}
int main(int argc, char const *argv[]) {

  char *str =  readstring();
  printf("%s\n", str);
  free( str );
  return 0;
}
