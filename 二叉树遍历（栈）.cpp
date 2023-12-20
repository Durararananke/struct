void PreOrder(BiTree T)
{
    Stack S;
    Initstack(S);
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            visit(T);
            Push(S,T);
            T = T->lchild;
        }
        if (!IsEmpty(S))
        {
            Pop(S, T);
            T = T->rchild;
        }
    }
}
void InOrder(BiTree T)
{
    Stack S;
    Initstack(S);
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S,T);
            T = T->lchild;
        }
        if (!IsEmpty(S))
        {
            Pop(S, T);
            visit(T);
            T = T->rchild;
        }
    }
}
void PostOrder(BiTree T)
{
    Stack S;
    Initstack(S);
    BiTree pre = nullptr;
    while (T || !IsEmpty(S))
    {
        while (T)
        {
            Push(S,T);
            T = T->lchild;
        }
        if (!S.empty())
        {
            T = S.top();
            if (T->rchild && T->rchild != pre)
            {
                T = T->rchild;
            }
            else
            {
                visit(T);
                S.pop();
                pre = T;
                T = nullptr;
            }
        }
    }
}