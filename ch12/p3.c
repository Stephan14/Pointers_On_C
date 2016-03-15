#include<stdio.h>
#include<stdlib.h>

// struct DLL_Node;
// struct DLL_Pointers
// {
//   struct DLL_Node *fwd;
//   struct DLL_Node *bwd;
// };
// struct DLL_Node
// {
//   struct DLL_Pointers *pointers;
//   int value;
// };
//
// struct DLL_Pointers *bulid_list()
// {
//   struct DLL_Pointers * Front_Rear = ( struct DLL_Pointers *)malloc( 2 * sizeof( struct DLL_Pointers ) );
//
//   if( Front_Rear == NULL )
//   {
//     printf("malloc error !\n" );
//     return NULL;
//   }
//
//   Front_Rear->fwd = NULL;
//   Front_Rear->bwd = NULL;
//
//   (Front_Rear+1)->fwd = NULL;
//   (Front_Rear+1)->bwd = NULL;
//
//   return Front_Rear;
// }


int insert_node( struct Node **frontp, struct Node ** rearp, int value )
{
  struct Node **fwdp;
  struct Node *next;
  struct Node *new_node;

  if( frontp == NULL || rearp == NULL )
    return 0;
  fwdp = frontp;
  while( (next = *fwdp ) != NULL )
  {
    if( next->value == value )
      return 0;
    if( next->value > value )
      break;
    fwdp = &next->fwd;
  }

  new_node = (struct Node *) malloc( sizeof( struct Node ) );
  if( new_node == NULL )
  {
    printf("malloc error !\n" );
    return 0;
  }

  new_node->value = value;

  new_node->fwd = next;
  *fwdp = new_node;

  if( fwdp !=  frontp )
    if( next != NULL )
      new_node->bwd = next->bwd;
    else
      new_node->bwd = *rearp;
  if( next != NULL )
    next->bwd = new_node;
  else
    *rearp = new_node;

  return 1;
}
int main(int argc, char const *argv[]) {

  return 0;
}
