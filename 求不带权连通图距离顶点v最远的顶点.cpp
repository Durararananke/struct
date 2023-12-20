bool visited[MaxNum];
int BFSTraverse(Graph G, int v)
{
    for (i = 0; i < G.vexnum; i++)
    {
        visited[i] = false;
    }
    InitQueue(Q);
    visit(v);
    visited[v] = true;
    Enqueue(Q, v);
    int u = v;
    while (!IsEmpty(Q))
    {
        Dequeue(Q, v);
        u = v;
        for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
        {
            if (!visited[w])
            {
                visit(w);
                visited[w] = true;
                Enqueue(Q, w);
            }
        }
    }
    return u;
}