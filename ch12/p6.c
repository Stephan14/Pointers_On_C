int dll_remove( struct Node *rootp, struct Node *node )
{
  struct Node * pre = NULL;
  struct Node *this = rootp;

  if( node == NULL || rootp == NULL )
    return 0;
  pre = this;
  this = this->next;

  while( this != NULL && this != node )
  {
    pre = this;
    this = this->next;
  }

  if( this == NULL )
    return 0;
  else
  {
    if( this->next == NULL )
      rootp->before = pre;
    else
      this->next->before = pre;
    pre->next = this->next;
    free( this );
    return 1;
  }
}
