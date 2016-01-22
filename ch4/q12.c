#include<stdio.h>
int main(int argc, char const *argv[]) {
  int leap_year;
  int year;

  printf("请输入一个年份：\n" );
  scanf("%d", &year);

  if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ) {
    leap_year = 1;
    printf( "闰年\n" );
  }else
  {
    printf( "非闰年\n" );
  }

  return 0;
}
