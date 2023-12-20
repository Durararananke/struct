void DFSTraverse(Graph G) // 对图G进行深度优先遍历
{
    for (v = 0; v < G.vexnum; ++v) // 访问标志数组初始化
    {
        visited[v] = false;
    }
    for (v = 0; v < G.vexnum; ++v) // 对尚未访问的顶点调用DFS
    {
        if (!visited[v])
        {
            DFS(G, v);
        }
    }
}
void DFS(Graph G, int v) // 从第v个顶点出发递归地深度优先遍历图G
{
    visit(v);
    visited[v] = true;
    for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) // 依次检查v的所有邻接点
    {
        if (!visited[w])
            DFS(G, w); // 对v的尚未访问的邻接点w递归调用DFS
    }
}