void swapLeftAndRight(BiTree T)
{
    if (!T)
    {
        return;
    }

    // 递归交换左右子树
    swapLeftAndRight(T->lchild);
    swapLeftAndRight(T->rchild);

    // 交换当前节点的左右子树
    BiNode *p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
}