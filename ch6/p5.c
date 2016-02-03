#include<stdio.h>
#include<limits.h>

#define MAX_VALUE 1000
#define MAX_BIT_NUMBER ( (MAX_VALUE - 3) / 2)
#define SIZE ( MAX_BIT_NUMBER / CHAR_BIT + 2)
/*
  对字符数组的位操作
*/
unsigned bit_offset( unsigned bit_number )
{
  return bit_number % CHAR_BIT;
}

unsigned character_offset ( unsigned bit_number )
{
  return bit_number / CHAR_BIT;
}
/*
  测试指定位为1还是为0
*/
int test_bit( char bit_array[], unsigned int bit_number )
{
  return ( bit_array[ character_offset( bit_number ) ] & 1 << bit_offset( bit_number )) != 0;
}

/*
  置位
*/
void set_bit( char bit_array[], unsigned int bit_number )
{
    bit_array[ character_offset( bit_number ) ] |= 1 << bit_offset( bit_number );
}

/*
  清零
*/
void clear_bit( char bit_array[], unsigned int bit_number )
{
  bit_array[ character_offset( bit_number )] &= ~(1 << bit_offset( bit_number ));
}


int main(int argc, char const *argv[]) {
  char sieve[ SIZE ];
  int number;
  int bit_number;
  char *sp;
  /*
    初始化
  */
  for( sp = &sieve[0]; sp < &sieve[ SIZE ]; )
    *sp++ = 0xff;//使用16进制初始化字符变量


  for( number = 3; number <= MAX_VALUE; number += 2 )
  {
    bit_number = ( number - 3 ) / 2;//偶数
    if( !test_bit(sieve, bit_number) )
      continue;
    while ( (bit_number += number) <= MAX_BIT_NUMBER )
    {
      clear_bit( sieve, bit_number );
    }
    /*以上部分代码可以这样写
    if( test_bit(sieve, bit_number) )
    {
      while ( (bit_number += number) <= MAX_BIT_NUMBER )
      {
        clear_bit( sieve, bit_number );
      }
    }
    */
  }

  /*
    输出
  */
  printf("2\t" );
  for(bit_number = 0, number = 3; number <= MAX_VALUE; bit_number +=1, number += 2 )
  {
    if( test_bit( sieve, bit_number ))
      printf("%d\t", number);
  }
  return 0;
}
