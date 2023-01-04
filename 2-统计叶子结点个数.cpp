#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

static int count=0;

// 先序方式实现
void LeafNode1(BiTree &T){
    if(T){
        // 根，执行算法操作，即判断是否是叶子结点
        if(T->lchild==NULL&&T->rchild==NULL){
            count++;
        }
        // 左
        LeafNode1(T->lchild);
        // 右
        LeafNode1(T->rchild);
    }
}

// 中序方式实现
void LeafNode1(BiTree &T){
    if(T){
        // 左
        LeafNode2(T->lchild);
        // 根，执行算法操作，即判断是否是叶子结点
        if(T->lchild==NULL&&T->rchild==NULL){
            count++;
        }
        // 右
        LeafNode2(T->rchild);
    }
}

// 后序方式实现
void LeafNode3(BiTree &T){
    if(T){
        // 左
        LeafNode3(T->lchild);
        // 右
        LeafNode3(T->rchild);
        // 根，执行算法操作，即判断是否是叶子结点
        if(T->lchild==NULL&&T->rchild==NULL){
            count++;
        }
    }
}