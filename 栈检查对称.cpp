#include<Stack.h>
bool isSymmetric(Linklist L){
    if(!L->next||!L->next->next)
        return true;
    Linklist p = L->next, q = L->next;
    char e;
    Stack S;
    InitStack(S);
    while(q&&q->next){
        Push(S, p->data);
        p = p->next;
        q = q->next->next;
    }
    if(q)
        p = p->next;
    while(p){
        if(p->data!=Pop(S,e))
            return false;
        p = p->next;
    }
    return true;
}