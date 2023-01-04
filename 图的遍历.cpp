#include<iostream>
using namespace std;

#define MaxSize 10

bool visited[MaxSize];

// 广度优先遍历函数，从顶点v出发，广度优先遍历图G
void BFS(Graph G, int v){
    // 先访问v
    visit(v);
    // 对已访问的v做标记
    visited[v]=true;
    // v入队
    Enqueue(Q,v);
    // 队不为空则一直循环
    while(!isEmpty(Q)){
        // v出队
        Dequeue(Q,v);
        // 与v相邻且未被访问的结点入队
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
            if(!visited[w]){
                visit(v);
                visited[w]=true;
                EnQueue(Q,w);
            }
        }
    }
}

// 图G的广度优先遍历
void BFSTraverse(Graph G){
    // 初始化访问数组
    for(int i=0;i<G.vexnum;i++){
        visited[i]=false;
    }
    // 初始化辅助队列
    InitQueue(Q);
    // 遍历访问数组，找到未访问的顶点
    for(int i=0;i<G.vexnum;i++){
        // 对未访问的邻接顶点调用广度优先遍历函数
        if(!visited[i])
            BFS(G,i);
    }

}

// 深度优先遍历函数，从顶点v出发，深度优先遍历图G
void DFS(Graph G, int v){
    // 访问顶点v
    visit(v);
    // 将顶点v在访问数组中对应的值置为1，表示已访问
    visited[v]=true;
    // 遍历顶点v的邻接顶点
    for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w)){
        // 对未被访问的邻接顶点递归的调用深度优先遍历函数
        if(!visited[w]){
            DFS(G,w);
        }
    }
}

// 图G的深度优先遍历
void DFSTraverse(Graph G){
    // 初始化访问数组
    for(int v=0;v<G.vexnum;v++){
        visited[v]=false;
    }
    // 遍历访问数组，找到未访问顶点
    for(int v=0;v<G.vexnum;v++){
        // 从0开始，对未被访问的顶点调用深度优先遍历函数
        if(!visited[v])
            DFS(G,v);
    }
}