#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 判断是否是二叉排序树，如果是二叉排序树，flag返回1，否则返回0
void judgeBST(BiTree T,int &flag){
    // 静态变量在多层递归中只执行一次即第一次
    static BiTNode *pre=NULL;
    // 中序方式实现
    if(T&&flag){
        // 左
        judgeBST(T->lchild,flag);
        // 根
        if(pre){
            pre=T;
        }
        else if(pre->data<T->data){
            pre=T;
        }
        else{
            flag=0;
        }
        // 右
        judgeBST(T->rchild,flag);
    }
}