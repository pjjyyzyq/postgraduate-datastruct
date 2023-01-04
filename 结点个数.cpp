#include<iostream>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 计算二叉树T的结点总数(递归算法)
int NodeCount(BiTree T){
    // 如果T是空树返回0
    if(T==NULL){
        return 0;
    }
    // T的结点个数为其左子树结点个数加右子树结点个数加一
    else{
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1
    }
}

// 计算二叉树T的叶子结点个数(递归算法)
int LeafNodeCount(BiTree T){
    // 如果T是空树返回0
    if(T==NULL){
        return 0;
    }
    // 如果当前结点T是叶子结点返回1
    if(T->lchild==NULL&&T->rchild==NULL){
        return 1;
    }
    // 如果当前结点T不是是叶子结点，返回左右子树叶子结点树之和
    else{
        return LeafNodeCount(T->lchild)+LeafNodeCount(T->rchild);
    }
}