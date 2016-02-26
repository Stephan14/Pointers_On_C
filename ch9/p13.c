#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define KEY_LENGTH 27
#define NUL '\0'

int prepare_key( char *key )
{
  char *p_key = NULL;
  char *dup = NULL;
  int character;

  if( *key == NUL )
    return 0;

  for( p_key = key; ( character = *p_key ) != NUL; p_key++ )
  {
    if( !islower( character ) )
    {
      if( !isupper( character ) )
        return 0;
      *p_key = tolower( character );
    }
  }
  //检查一个字符串中是否有重复字符
  for( p_key = key; ( character = *p_key ) != NUL; )
  {
    dup = ++p_key;
    while ( (dup = strchr( dup, character )) != NULL )
      strcpy( dup, dup+1 );//复制字符串
  }

  for( character = 'a'; character <= 'z'; character++ )
  {
    if( strchr( key, character ) == NULL )
    {
      *p_key++ = character;
      *p_key = NUL;//重点
    }
  }
}

void encrypt( char *data, char const *key )
{
  while( *data != NUL )
  {
    if( isalpha( *data ) )
    {
      if( isupper( *data ) )
        *data = toupper( *( key + *data - 'A') );
      else
        *data = *( key + *data - 'a' );
    }
    data++;
  }
}
int main(int argc, char const *argv[]) {

  return 0;
}
