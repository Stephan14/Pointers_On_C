#include<iostream>
#include<stack>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
  stack <char> s;
  FILE *file = NULL;
  int ch = 0;

  if(!(file = fopen("q3.c", "r")))
  {
      cout<<"打开文件失败！！！"<<endl;
      exit(1);
  }

  while( (ch = fgetc(file)) != EOF)
  {
    printf("%c\n", ch);
    if( ch == '{')
    {
      s.push(ch);
    }else if( ch == '}')
    {
      s.pop();
    }
  }

  if( s.empty())
  {
    printf( "所有花括号都正确的出现！！！" );
  }else{
    printf( "花括号错误的出现！！！");
  }

  fclose(file);
  return 0;
}
