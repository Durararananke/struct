struct Node
{
    int data;
    Node *next;
};
using Linklist = Node *;
void delete_x(Linklist &L, int x){
    Node *p;
    if(!L)
        return;
    if(L->data==x){
        p = L;
        L = L->next;
        delete (p);
        delete_x(L, x);
    }
    else
        delete_x(L->next, x);
}