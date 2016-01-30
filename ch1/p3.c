#include<stdio.h>
#include<string.h>/* strlen函数在这个文件中  */
#include<stdlib.h>/* EXIT_SUCESS在stdlib.h文件中*/
#define MAX_INPUT 1000
/*
 *当checksunm溢出的时候，由于该类型为有符号的字符行，所有以整数输出的时候
 * 将会是负值
 */
int main()
{
  char input[MAX_INPUT];
  signed char checksum  = -1;

  if( fgets( input, sizeof(input), stdin ) != NULL )
  {
      int index = 0;
      int length = strlen( input );/* strlen显示的字符串长度包括\0的长度 */
      printf("字符串的长度为： %d，sizeof（input）= %ld \n", length, sizeof( input ) );

      while ( input[ index ] != '\0') {
        checksum += input[ index ];
		index++;/* s使用while循环时切记要进行索引的自增设置 */
      }

      printf("输入的字符串为：%s", input );
      printf("checksum为：%d\n", checksum );
  }
  return EXIT_SUCCESS;
}
