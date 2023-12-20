struct Node
{
    int data;
    Node *next;
};
using Linklist = Node *;
void InsertionSort(Linklist &L)
{
    if(!L->next)
        return;
    Node *p = L->next->next, *q;
    L->next->next = nullptr;
    while (p)
    {
        q = p->next;
        Node *pre = L;
        while(pre->next&&pre->next->data<p->data)
            pre = pre->next;
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}