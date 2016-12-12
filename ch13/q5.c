#define TRUE 1
#define FALSE 0
//C语言中'\0'与NULL没有区别
#define NUL '\0'

enum{ NONE, FLAG, ARG };

//判断参数是一个标志还是一个值
int argtype( int ch, char* control )
{
    while ( control != NUL )
    {
        if( ch == *control++ )
            return *control == '+'? ARG : FLAG;
    }

    return NONE;
}

//处理参数
char *
do_args( int argc, char *argv[], char* control, void (*do_arg)( int ch, char* value ), void (*illegal_arg)( int ch ) )
{
    char *argvp = NUL;
    int skip_arg;//加一个标记变量
    int ch;

    while ( ( argvp = *argv ) != NUL && *argvp == '-'  )
    {
        skip_arg = FALSE;
        while ( !skip_arg && ( ch = *++argvp ) != NUL ){
            switch ( argtype( *++argvp, control ) ) 
            {
                case FLAG:
                    do_arg( ch, control );  
                    break;
                case ARG:
                    if( *++argvp != NUL || ( argvp = *++argv ) != NUL  )
                    {
                        ( *do_arg )( ch, argvp );
                        skip_arg = TRUE;
                        break;
                    }
                    ( *illegal_arg )( ch );
                    return argv;

                case NONE:
                    illegal_arg( ch );
                    break;
            }
        }
            
    }
    return argv;
}
