#include<iostream>
using namespace std;

/*假设二叉树采用二叉链表存储结构，
试用层次遍历法求出该二叉树的深度。
请写出使用非递归算法求该二叉树的深度的代码*/
#define MaxSize 100

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


// 用层次遍历的非递归方法求二叉树的高度
int Depth(BiTree T){
    // T==NULL即树为空时返回0
    if(!T)
        return 0;
    // 设置辅助队列Q，队列中元素是指向二叉树结点的指针
    BiTNode *Q[MaxSize];
    // 初始化队头，队尾
    int front=-1,rear=-1;
    // 二叉树根节点入队
    Q[++rear]=T;

    // 设置一个二叉树结点扫描指针
    BiTNode *p;

    // 设置一个变量记录当前层的最右结点下标
    int last=0;

    // 设置一个变量记录二叉树层数
    int level=0;

    // 辅助队列非空则一直循环
    while(front<rear){
        // 队头结点出队为p结点
        p=Q[++front];
        // p结点有左孩子
        if(p->lchild)
            Q[++rear]=p->lchild;
        // p结点有右孩子
        if(p->rchild)
            Q[++rear]=p->rchild;
        if(front==last){
            level++;
            last=rear;   
        }
    }
    return level;
}