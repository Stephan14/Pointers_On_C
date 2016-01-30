#include<stdio.h>
int main( int argc, char *args[])
{
  int  line_number = 0;
  printf("请输入行数：");
  scanf("%d", &line_number );

  int index = 0;
  for( ; index < line_number; index++ )
  {
    printf("%d.\n", index+1 );
  }
  return 0;
}
