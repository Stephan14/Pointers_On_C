#include <stdio.h>


void traverse_list( struct node* head, void (*print_node )( struct node* node ) {
    
    if ( head == NULL )
        printf("头结点为空");
    else
        while( head != NULL )
        {
            print_node( head )
            head = head->next;
        }
    
    return;
} 
int main( int argc, char* argv[] )
{
    return 0;
}
