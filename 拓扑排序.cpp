bool TopologicalSort(Graph G){
    InitStack(S);
    for (int i = 0; i < G.vexnum;i++){
        if(indegree[i]==0)
            Push(S, i);//所有入度为0的顶点入栈
    }
    int count = 0;
    while(!IsEmpty(S)){
        Pop(S, i);
        std::cout << i;//输出顶点
        count++;
        for (w = FirstNeighbor(G, i); w>=0;w=NextNeighbor(G,i)){
            indegree[w]--;//删除顶点所指的所有顶点入度减1
            if(indegree[w]==0)
                Push(S, w);//入度为0顶点入栈
        }
    }
    if(count<G.vexnum)
        return 0;//拓扑排序失败
    else
        return 1;
}