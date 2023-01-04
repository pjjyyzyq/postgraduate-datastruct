#include<iostream>
using namespace std;

typedef struct BiTNode{
    char data[10];
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 中序方式实现
void Inorder(BiTree T, int deep){
    // 根节点为空，直接返回
    if(T)
        return;
    // 当前递归结点为叶子结点，输出data
    else if(T->lchild==NULL&&T->rchild==NULL){
        cout<<T->data;
    }
    // 当前递归结点为分支结点
    else{
        if(deep>1){
            cout<<"(";
        }
        // 左
        Inorder(T->lchild,deep+1);
        // 根
        cout<<T->data;
        // 右
        Inorder(T->rchild,deep+1);
        if(deep>1){
            cout<<")";
        }
    }
}