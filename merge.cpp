struct Node
{
    int data;
    Node *next;
};
using Linklist = Node *;
Linklist merge(Linklist &A, Linklist &B)
{
    Node *pa = A->next;
    Node *pb = B->next;
    A->next = nullptr;
    Node *r = A;
    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            r->next = pa;
            pa = pa->next;
        }
        else if (pa->data > pb->data)
        {
            r->next = pb;
            pb = pb->next;
        }
        else
        {
            r->next = pa;
            pa = pa->next;
            pb = pb->next;
        }
        r = r->next;
    }
    r->next = pa ? pa : pb;
    delete (B);
    return A;
}
Linklist ReverseMerge(Linklist &A, Linklist &B)
{
    Node *pa = A->next;
    Node *pb = B->next;
    A->next = nullptr;
    while (pa && pb)
    {
        if (pa->data < pb->data)
        {
            pa->next = A->next;
            A->next = pa;
            pa = pa->next;
        }
        else if (pa->data > pb->data)
        {
            pb->next = A->next;
            A->next = pb;
            pb = pb->next;
        }
        else
        {
            pa->next = A->next;
            A->next = pa;
            pa = pa->next;
            pb = pb->next;
        }
    }
    pa = pa ? pa : pb;
    while (pa)
    {
        pa->next = A->next;
        A->next = pa;
        pa = pa->next;
    }
    delete (B);
    return A;
}