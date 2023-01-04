#include<iostream>
using namespace std;

// 邻接矩阵法,常用于存储稠密图,存储稀疏图时浪费大量存储空间
// 顶点数目的最大值
#define MaxVertexNum 100
// 顶点的数据类型
typedef char VertexType;
// 带权图中边上权值的数据类型
typedef int EdgeType;
// 图的邻接矩阵存储结构定义
typedef struct{
    // 顶点表
    VertexType Ver[MaxVertexNum];
    // 邻接矩阵即边表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    // 图当前的顶点数和弧数
    int vexnum,arcnum;
}MGraph;

// 邻接表法,常用于稀疏图
// 邻接表中表对应链表的顶点,可看作边结点
typedef struct_ENode{
    // 该边所指向顶点的位置
    int ivex;
    struct_ENode *next_edge;
}ENode,*PENode;
// 邻接表中表的顶点,可看作顶点结点
typedef struct_VNode{
    // 顶点信息
    char data;
    // 指向第一条依附该顶点的弧
    ENode *first_edge;
}VNode;
// 邻接表
typedef struct_LGraph{
    // 图的顶点的数目
    int vexnum;
    // 图的边的数目
    int edgenum;
    VNode vexs[MaxVertexNum]
}LGraph