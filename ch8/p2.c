看到这到题第一个想法就是使用多个if语句进行判断，然后再分别采用公式进行计算。
但是，本题的答案采用另一种方法解决,通过用数组来存储数据来进行计算。
#include<stdio.h>
#include<float.h>

static double income[] = { 0, 23350, 56550, 117950, 256500, DBL_MAX };

static float base_tax[] = { 0, 3502.5, 12798.5, 31832.5, 81710.5 };

static float percentage[] = { 0.15, 0.28, 0.31, 0.36, 0.396 };

int main(int argc, char const *argv[]) {

  return 0;
}
