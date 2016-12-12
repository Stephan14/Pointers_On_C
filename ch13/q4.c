void swap( char* i, char* j, int resize )
{
    char ch;
    while( resize-- > 0 )
    {
        ch = *i;
        *i++ = *j;
        *j++ = ch;
    }
}

void sort( char* base, int len, int resize, int (*comp)( char* , char* ) )
{
    //最后一个元素的内存地址 
    char* last = base+(len-1)*resize;
    //注意比较的极限值
    for ( char* index1 = 0; index1 < last; index1 += resize ) 
         for ( char* index2 = index1; index2 <= last; index2 += resize )
            if( comp( index1, index2 ) > 0 ) 
                swap( index1, index2, resize );                

    return;
}
