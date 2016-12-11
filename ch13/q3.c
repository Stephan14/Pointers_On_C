//在不同的情况下执行不同的工作，这些代码必须移到函数中，主要的困难在于提出一个共同的原型来适应不同需要的函数，要包括任何一个函数使用的所有参数，新的函数都要使用这个共同的原型，已经存在的函数要转换来匹配新的原型，大多数函数至少有一个它们不需要的参数结尾，current必须通过指针来使函数修改它
void (Node *list, Node **current, Transaction *trans);
void delete_trans(Node *list, Node **current, Transaction *trans);
void search(Node *list, Node **current, Transaction *trans);
void edit(Node *list, Node **current, Transaction *trans);

void forword(Node *list, Node **current, Transaction *tran)
{
    *current = (*current)->next;

}

void backword(Node *list, Node **current, Transaction *tran)
{
    *current = (*current)->prev;

}

void (*function[])(Node *, Node **, Transaction *) = {
    add_new_trans,
    delete_trans,
    forword,
    backword,
    search,
    edit

};

#define COUNT (sizeof(function) / sizeof(function[0]));

if(transaction->type >= NEW && transaction <= EDIT)
    function[transaction->type](list, &current, transaction);
else
    printf("Illegal transaction type!\n");
