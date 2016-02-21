#include<stdio.h>
#include<ctype.h>

int main(int argc, char const *argv[]) {
  int ch;
  int n_cntrl = 0;
  int n_space = 0;
  int n_number = 0;
  int n_lower = 0;
  int n_upper = 0;
  int n_punct = 0;
  int n_not_print = 0;
  int total = 0;

  while ( (ch = getchar() ) != EOF ) {//用ctrl+D结束文本输入
    total++;
    if ( iscntrl( ch ) ) n_cntrl++;
    if ( isspace( ch ) ) n_space++;
    if ( isdigit( ch ) ) n_number++;
    if ( islower( ch ) ) n_lower++;
    if ( isupper( ch ) ) n_upper++;
    if ( ispunct( ch ) ) n_punct++;
    if ( !isprint( ch ) ) n_not_print++;
  }

  if( total == 0 )
    printf("没有输入\n" );
  else
  {
    printf("控制字符占总字符比例为%%%3.0f\n", n_cntrl * 100.0 / total );
    printf("空白字符占总字符比例为%%%3.0f\n", n_space * 100.0 / total );
    printf("数字字符占总字符比例为%%%3.0f\n", n_number * 100.0 / total );
    printf("小写字符占总字符比例为%%%3.0f\n", n_lower * 100.0 / total );
    printf("大写字符占总字符比例为%%%3.0f\n", n_upper * 100.0 / total );
    printf("标点字符占总字符比例为%%%3.0f\n", n_punct * 100.0 / total );
    printf("不可打印字符占总字符比例为%%%3.0f\n", n_not_print * 100.0 / total );
  }
  return 0;
}
