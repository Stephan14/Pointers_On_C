#include<stdio.h>
#include<limits.h>

#define INI_BITS ( CHAR_BIT * sizeof(int) )
/*
  已经经过测试该编译器中规定int为4个字节
*/

int creat_mask( int starting_bit, int ending_bit )
{
  /*为保证进行逻辑移位而不是算术移位，将掩码声明为无符号类型*/
  unsigned int mask = (unsigned)-1;//强制类型转换
  mask >>= INI_BITS - (starting_bit - ending_bit + 1 );
  mask <<= ending_bit;
  return mask;
}



int store_bit_field( int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit )
{
  unsigned int mask = creat_mask( starting_bit, ending_bit );
  original_value &= ~mask;
  value_to_store <<= ending_bit;
  return original_value | value_to_store & mask;
}
int main(int argc, char const *argv[]) {
  int i = 0xffff;

  //printf("%x\n", store_bit_field( i, 0x123, 13, 9) );
  return 0;
}
