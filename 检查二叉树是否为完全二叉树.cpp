bool CBT(BiTree T){
    if(!T)
        return true;
    InitQueue(Q);
    Enqueue(S, T);
    while(!IsEmpty(Q)){
        Dequeue(Q, p);
        if(p){
            EnQueue(Q, p->lchild);
            EnQueue(Q, p->rchild);
        }
        else
            while(!IsEmpty(Q)){
                DeQueue(Q, p);
                if(p)
                    return false;
            }
    }
}