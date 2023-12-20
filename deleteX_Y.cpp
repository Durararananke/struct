struct Node
{
    int data;
    Node *next;
};
using Linklist = Node *;
void del_X_Y(Linklist &L,int x,int y){
    Node*p = L;
    while(p->next){
        if(p->next->data>x&&p->next->data<y){
            Node *q = p->next;
            p->next = q->next;
            delete (q);
        }
        else
            p = p->next;
    }
}