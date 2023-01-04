#include<iostream>
using namespace std;

typedef int ElemType; 

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 先序方式
void changeLR1(BiTree &T){
    if(T){
        // 遍历根时做相应算法操作，交换左右子树
        BiTNode *temp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=temp;

        // 左
        changeLR1(T->lchild);

        // 右
        changeLR1(T->rchild);
    }
}

// 中序方式，错误代码
void changeLR2(BiTree &T){
    if(T){
        // 左
        changeLR2(T->lchild);

        // 遍历根时做相应算法操作，交换左右子树
        BiTNode *temp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=temp;
        
        // 右
        changeLR2(T->rchild);
    }
}

// 后序方式
void changeLR3(BiTree &T){
    BiTNode *temp;
    if(T){
        // 左
        changeLR3(T->lchild);

        // 右
        changeLR3(T->rchild);

        // 遍历根时做相应算法操作，交换左右子树
        temp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=temp;
    }
}