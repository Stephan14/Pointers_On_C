#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_MAX 129
#define TRUE 1
#define FALSE 0

int main(int argc, char const *argv[]) {
  FILE *file;
  char pre_Buffer[BUFFER_MAX];
  char cur_Buffer[BUFFER_MAX];
  int flag = FALSE;

  if ((file = fopen("test.txt", "r")) == NULL)
  {
    printf( "打开文件失败！！\n" );
    exit(1);
  }

  if( fgets( pre_Buffer, BUFFER_MAX, file) )
  {
    while ( fgets( cur_Buffer, BUFFER_MAX , file ) )
    {
      if (strcmp(cur_Buffer, pre_Buffer) != 0)
      {
        strcpy(pre_Buffer, cur_Buffer);
        // printf("%s\n", pre_Buffer );
        flag = FALSE;
      }
      else
      {
        if (flag == FALSE)
        {
          printf("%s\n", cur_Buffer);
          flag = TRUE;
        }
      }
    }
  }

  fclose( file );
  return 0;
}

// optimization
void func()
{
  FILE *file;
  char pre_Buffer[BUFFER_MAX];
  char cur_Buffer[BUFFER_MAX];
  int flag = FALSE;

  if ((file = fopen("test.txt", "r")) == NULL)
  {
    printf("打开文件失败！！\n");
    exit(1);
  }

  if (fgets(pre_Buffer, BUFFER_MAX, file))
  {
    while (fgets(cur_Buffer, BUFFER_MAX, file))
    {
      if (strcmp(cur_Buffer, pre_Buffer) == 0)
      {
        if (flag == FALSE)
        {
          printf("%s\n", cur_Buffer);
          flag = TRUE;
        }
      }
      else
      {
        strcpy(pre_Buffer, cur_Buffer);
        flag = FALSE;
      }
    }
  }
}

