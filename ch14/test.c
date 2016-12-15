#include <stdio.h>

//#的作用
#define PRINT(FORMAT, VLALUE)  \
        printf( "The value is " FORMAT "\n", VLALUE )
//##的作用
#define ADD_TO_SUM( sum_number, value  )    \
        sum ## sum_number += value
//宏参数的副作用,多次执行同一个命令
#define MAX( a, b )  ( (a) > (b) ? (a) : (b) )


int main( int argc, char *argv[] )
{
    int a = 3;
    PRINT( "%d", a + 3 );
    int sum5 = 5;
    ADD_TO_SUM( 5, 25 );
    printf( "sum5 = %d\n", sum5 );

    int x = 5;
    int y = 8;
    int z = MAX( x++, y++ );
    printf( " x = %d, y = %d, z = %d\n", x, y, z );

    //测试字符串连接
    printf("test1"
           "test2\n");
    printf("test3 \
     test4\n");

    printf("__FILE__ : %s\n", __FILE__ );
    printf("__DATE__ : %s\n", __DATE__ );
    printf("__LINE__ : %d\n", __LINE__ );
    printf("__TIME__ : %s\n", __TIME__ );
    printf("__STDC__ : %d\n", __STDC__ );
    return 0;
} 
