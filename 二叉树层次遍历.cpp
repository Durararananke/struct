#include <iostream>
#include <queue>
struct BiTNode
{
    int data;
    BiTNode *lchild, *rchild;
    BiTNode(int value) : data(value), lchild(nullptr), rchild(nullptr) {}
};
using BiTree = BiTNode *;
void insert(BiTree &T, int value)
{
    if (!T)
    {
        T = new BiTNode(value);
    }
    else if (value < T->data)
    {
        insert(T->lchild, value);
    }
    else
    {
        insert(T->rchild, value);
    }
}
void visit(BiTNode *p)
{
    std::cout << p->data << " ";
}
void LevelOrder(BiTree T)
{
    std::queue<BiTree> Q;
    Q.push(T);
    while (!Q.empty())
    {
        BiTree p = Q.front();
        Q.pop();
        visit(p);
        if (p->lchild)
        {
            Q.push(p->lchild);
        }
        if (p->rchild)
        {
            Q.push(p->rchild);
        }
    }
}
int main()
{
    BiTree T = nullptr;
    insert(T, 7);
    insert(T, 3);
    insert(T, 8);
    insert(T, 2);
    insert(T, 5);
    insert(T, 4);
    insert(T, 6);
    insert(T, 1);
    insert(T, 9);
    insert(T, 0);
    std::cout << "LevelOrder: ";
    LevelOrder(T);
    return 0;
}