#include<stdio.h>
#include<math.h>

#define MIN_DIFFER 0.0000000005

double getSqrt( int n )
{
  double pre_a = 1.00f;
  double cur_a = 1.00f;

  do {
    pre_a = cur_a;
    cur_a = ( n / pre_a + pre_a ) / 2;
    // printf("cur_a:%lf\n", cur_a );
    // printf("pre_a:%lf\n", pre_a );
    // printf("abs:%lf\n", fabs( pre_a - cur_a ) );
  } while( fabs( pre_a - cur_a ) >= MIN_DIFFER );

  return cur_a;
}
int main(int argc, char const *argv[]) {
  printf("%lf\n", getSqrt( 4 ) );
  return 0;
}

/*
  总结：
    求绝对值时，要引入math.h头文件
    针对整型：abs（）
    针对浮点型：fabs（）
*/
