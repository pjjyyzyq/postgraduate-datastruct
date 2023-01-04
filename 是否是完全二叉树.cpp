#include<iostream>
using namespace std;

/*二叉树按二叉链表形式存储，
写一个判别给定二叉树是否是完全二叉树的算法*/

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 二叉树层次遍历的引申
bool IsComplete(BiTree T){
    // 初始化辅助队列
    InitQueue(Q);
    // 空树时是满二叉树
    if(!T)
        return 1;
    // 根结点入队
    EnQueue(Q,T);
    // 辅助队列不为空则一直循环
    while(!IsEmpty(Q)){
        // 队头出队
        DeQueue(Q,p);
        // 当前队头结点不为空
        if(p){
            EnQueue(Q,T->lchild);
            EnQueue(Q,T->rchild);
        }
        // 当前队头结点为空
        else{
            // 若是完全二叉树，则空结点后面应全为空
            while(!IsEmpty(Q)){
                DeQueue(Q,p);
                // 若有一个结点不为空，则不是完全二叉树
                if(p)  
                    return 0;
            }
        }
    }
    return 1;
}