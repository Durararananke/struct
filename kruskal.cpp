#include <iostream>
#include <algorithm>

const int MAX_ROADS = 1000;   // 假设最大边数
const int MAX_VERTICES = 100; // 假设最大顶点数

// 边的结构体定义
struct road
{
    int a, b; // 边的两个顶点
    int w;    // 边的权值
};

// 图的结构体定义
struct MGraph
{
    road edges[MAX_ROADS];  // 边的集合
    int vertexNum, edgeNum; // 顶点数和边数
};

int parent[MAX_VERTICES]; // 并查集数组

// 并查集中的查找函数
int find(int i)
{
    if (parent[i] == i)
    {
        return i;
    }
    return parent[i] = find(parent[i]);
}

// 并查集中的合并函数
void unionSet(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB)
    {
        parent[rootA] = rootB;
    }
}

// Kruskal 算法实现
void Kruskal(MGraph &G)
{
    // 对所有边按权值进行排序
    std::sort(G.edges, G.edges + G.edgeNum, [](const road &a, const road &b)
              { return a.w < b.w; });

    // 初始化并查集
    for (int i = 0; i < G.vertexNum; ++i)
    {
        parent[i] = i;
    }

    // 遍历每条边
    for (int i = 0; i < G.edgeNum; ++i)
    {
        int u = find(G.edges[i].a);
        int v = find(G.edges[i].b);

        // 如果两个顶点不在同一个集合中，则没有形成环
        if (u != v)
        {
            // 输出这条边，并在并查集中合并两个顶点
            std::cout << G.edges[i].a << " - " << G.edges[i].b << " : " << G.edges[i].w << std::endl;
            unionSet(u, v);
        }
    }
}

int main()
{
    MGraph G;
    // 填充 G 的 edges、vertexNum 和 edgeNum
    // ...

    // 执行 Kruskal 算法
    Kruskal(G);

    return 0;
}
