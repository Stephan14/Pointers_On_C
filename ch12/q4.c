1) Node *root;
  root = malloc( sizeof( Node ) - sizeof( ValueType ) );

2)struct DLL_Node;
  struct DLL_Pointers
  {
    struct DLL_Node *fwd;
    struct DLL_Node *bwd;
  };
  struct DLL_Node
  {
    struct DLL_Pointers *pointers;
    int value;
  };
