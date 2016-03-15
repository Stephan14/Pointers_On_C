while( *linkp != NULL && (*linkp)->value < new_value )
  linkp = &(*linkp)->link;
new_node = malloc( sizeof( Node) );
if( new_node == NULL )
{
  printf("malloc error ！");
  return 0;
}
new_node->value = new_value;
new_node->link = *linkp;
*linkp = new_node;//前一个节点的link字段
renturn 1;
