#include<iostream>
using namespace std;

/*假设二叉树采用二叉链表存储结构存储， 
试设计一个算法，
计算一棵给定二叉树的所有双分支结点个数*/

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 记录二叉树的双分支结点个数
int count=0;

// 二叉树先序遍历的引申
void DSonNode(BiTree T){
    // 当前结点为空，结束
    if(T==NULL)
        return;
    // 当前结点同时有左右孩子
    if(T->lchild!=NULL&&T->rchild!=NULL){
        // 分支结点计数加一
        count++;
    }
    DSonNode(T->lchild);
    DSonNode(T->rchild);
}