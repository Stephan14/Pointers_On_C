#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20		/*所能处理的最大的列数*/
#define MAX_INPUT 1000  /*所能输入的最大的列数*/


/*
 *从命令行读取字符串
*/
int read_column_numbers( int columns[], int max)
{
/*
 *在定义数组参数的时候没有定义数组的长度，这导致函数会处理该指针之后的任意长度
 *的内存中的数据，这是不安全的，所以一般都是同时定义一个表示该数组长度的变量
*/

	int num = 0;
	int ch;  /*防止输入的字符意外被解释成EOF，声明成int类型*/

	while( num < max && scanf( "%d", &columns[num] ) == 1 && columns[num] > 0)
	/*
	 *对于scanf函数来说，除了从标准输出中读取一个字符串之外，其他情况下，
	 *都需要在变量之前加一个&符号
	*/
	{
		num++;/*使用while时通常会忘记++操作*/
	}

	if( num % 2 != 0)/*num可以表示已经读取的个数*/
	{
		puts("Last column number is not paired!");
		/*
		 *gets的输出版本，将字符串输出到标准输出中，并在末尾添加一个换行
		 *gets丢弃换行符，在在字符串的末尾加一个NUL作为终止符
		*/
		exit( EXIT_FAILURE);/*直接退出无返回值*/
	}

	while( (ch = getchar()) != EOF && ch != '\n' );/*过滤掉负数后面的数*/

	return num;
}

/*
 *处理输入的字符串
*/
void rearrange( char *output, char *const input, int const columns[], int num_column )
{
	int length = strlen( input );
	int output_column = 0;     /*output数组的下标*/

	for( int column = 0; column < num_column; column += 2 )
	/*
	 * for循环中第一部分初始化只执行一次，第二部分在每次循环之前执行，
	 * 第三部分在每次循环之后执行
    */
	{
		int nchars = columns[column+1] - columns[column] + 1;
		/*
		 *输入的行结束或者输出的行数组已经满了(通过数组下标来判断)
		*/
		if( columns[column] > length )
		{
			continue;
		}else if( output_column > MAX_INPUT - 1 )
		{
			break;
		}

		/*
		 *输出的数组的空间不够，能存多少就存多少
		*/
		if( nchars > MAX_INPUT - output_column - 1 )
		{
			nchars = MAX_INPUT - output_column - 1;
		}

		strncpy( output + output_column, input + columns[column], nchars );
		output_column += nchars;
	}

	output[output_column] = '\0';/*字符串结束*/
}

int main()
{
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	int num = read_column_numbers( columns, MAX_COLS);
	
	while( fgets( input, sizeof(input), stdin ) != NULL && input[0] != '\n')
	{
		printf("输入字符串：%s\n", input );
		rearrange( output, input, columns, num );
		printf("输出字符串：%s\n", output );
	}
	return EXIT_SUCCESS;
}
