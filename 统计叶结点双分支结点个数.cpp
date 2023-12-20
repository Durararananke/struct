int countLeaves(BiTree T)
{
    // 如果节点为空，返回 0
    if (T == nullptr)
    {
        return 0;
    }

    // 如果节点为叶子节点，返回 1
    if (T->lchild == nullptr && T->rchild == nullptr)
    {
        return 1;
    }

    // 递归统计左右子树的叶子节点数量
    int leftLeaves = countLeaves(T->lchild);
    int rightLeaves = countLeaves(T->rchild);

    // 返回左右子树叶子节点数量的和
    return leftLeaves + rightLeaves;
}
int countDoubleBranchNodes(BiTree T)
{
    if (!T)
    {
        return 0;
    }

    // 当前结点是双分支结点
    if (T->lchild && T->rchild)
    {
        return 1 + countDoubleBranchNodes(T->lchild) + countDoubleBranchNodes(T->rchild);
    }

    // 递归统计左右子树的双分支结点个数
    return countDoubleBranchNodes(T->lchild) + countDoubleBranchNodes(T->rchild);
}