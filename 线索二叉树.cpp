#include <iostream>
struct ThreadNode
{
    int data;
    ThreadNode *lchild;
    ThreadNode *rchild;
    bool ltag;
    bool rtag;
    ThreadNode(int value) : data(value), lchild(nullptr), rchild(nullptr), ltag(0), rtag(0) {}
};
using ThreadTree = ThreadNode *;
void visit(ThreadNode *p)
{
    std::cout << p->data << " ";
}
void InOrderThread(ThreadTree &T, ThreadTree &pre)//中序遍历线索化二叉树
{
    ThreadTree p = T;
    if (p)
    {
        InOrderThread(p->lchild, pre);//递归左子树线索化
        if (!p->lchild)//左子树为空，建立前驱线索
        {
            pre = p->lchild;
            p->ltag = 1;
        }
        if (pre && !pre->rchild)//前驱结点的右子树为空，建立后继线索
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;//保持pre指向p的前驱
        InOrderThread(p->rchild, pre);//递归右子树线索化
    }
}
ThreadNode *FirstNode(ThreadNode *p)//找到中序遍历的第一个结点
{
    while (p && !p->ltag)
    {
        p = p->lchild;
    }
    return p;
}
ThreadNode *NextNode(ThreadNode *p)//找到中序遍历的下一个结点
{
    if (p && p->rtag)
    {
        return p->rchild;
    }
    else
    {
        return FirstNode(p->rchild);
    }
}
void InOrder(ThreadNode *T)//中序遍历
{
    for (ThreadNode *p = FirstNode(T); p; p = NextNode(p))
    {
        visit(p);
    }
}
int main()
{
    ThreadTree T = new ThreadNode(1);
    T->lchild = new ThreadNode(2);
    T->rchild = new ThreadNode(3);
    T->lchild->lchild = new ThreadNode(4);
    T->lchild->rchild = new ThreadNode(5);
    T->rchild->lchild = new ThreadNode(6);
    T->rchild->rchild = new ThreadNode(7);
    T->lchild->lchild->lchild = new ThreadNode(8);
    ThreadTree pre = nullptr;
    InOrderThread(T, pre);
    InOrder(T);
    return 0;
}