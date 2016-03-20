#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};


struct Node *build_list( int value )
{
  struct Node *top = (struct Node *)malloc( sizeof( struct Node ) );
  top->value = value;

  if( top != NULL )
    return top;
  else
    return NULL;
}

int destroy_list( struct Node * top )
{
  if( top == NULL )
    return -1;
  while( top != NULL )
  {
    struct Node *node_ptr = top;
    top = top->next;
    printf("释放%d结点\n", node_ptr->value );
    free( node_ptr );
  }
}

int insert_node( struct Node **top, int new_value )
{
  while( *top != NULL && (*top)->value < new_value )
    top = &(*top)->next;
  struct Node *temp_node = (struct Node *)malloc( sizeof(struct Node ) );

  if( temp_node == NULL )
  {
    printf("malloc error !\n" );
    return -1;
  }

  temp_node->value = new_value;
  temp_node->next = *top;
  *top = temp_node;
  return 1;
}

void print_list( struct Node *top )
{
  while( top != NULL )
  {
    printf("%d\n", top->value );
    top = top->next;
  }
}

struct Node *revert_list( struct Node *top )
{
  struct Node *last = NULL;
  struct Node *current = NULL;

  while( top != NULL )
  {
    current = top;
    top = top->next;
    current->next = last;
    last = current;
  }

  return last;
}

int delete_node( struct Node ** top, struct Node * node )
{
  // struct Node *pre_node = NULL;
  //
  // while( *top != NULL )
  // {
  //   if( *top == node )
  //   {
  //     if( pre_node != NULL )
  //     {
  //       pre_node->next = (*top)->next;
  //       free(*top);
  //     }
  //     else
  //       top = &(*top)->next;
  //     return 1;
  //   }
  //   pre_node = *top;
  //   top = &(top->next);
  // }

  struct Node *current = NULL;

  while( (current = *top) != NULL && current != node )
    top = &current->next;

  if( current == node )
  {
    *top = current->next;
    free( current );
    return 1;
  }
  else
    return 0;

}


int main(int argc, char const *argv[]) {
  struct Node *top = build_list(2);
  insert_node( &top, 4);
  insert_node( &top, 1);
  insert_node( &top, 7);
  insert_node( &top, 2);
  printf("删除之前的链表\n" );
  print_list( top );
  delete_node( &top, top );
  printf("删除之后的链表\n" );
  print_list( top );
  //print_list( revert_list( top ) );
  destroy_list( top );
  return 0;
}
