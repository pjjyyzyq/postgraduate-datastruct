#include<iostream>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*假设二叉树采用二叉链表存储结构存储，
设计一个算法，求先序遍历序列中第k个结点的值*/

// 记录当前遍历序号
int count=1;

// 二叉树递归实现先序遍历的引申
void PreOrder(BiTree T,int k){
    // 若根结点为空，结束
    if(T==NULL){
        return;
    }
    // 判断当前结点是否是第k个结点
    if(count==k){
        // 是第k个结点，打印结点的值，结束
        cout<<T->data;
        return;
    }
    else{
        count++;
    }
    if(T->lchild)
        PreOrder(T->lchild,k);
    if(T->rchild)
        PreOrder(T->rchild,k);
}