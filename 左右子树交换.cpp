#include<iostream>
using namespace std;

/*设树B是一颗采用链式结构存储的二叉树， 
编写一个把树B中所有结点的左、右子树进行交换的函数*/

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 二叉树后序遍历的引申
void swap(BiTree B){
    if(B){
        // 递归的交换左子树
        swap(B->lchild);
        // 递归的交换右子树
        swap(B->rchild);
        // 当前结点左右孩子交换
        BiTree temp=B->lchild;
        B->lchild=B->rchild;
        B->rchild=temp;
    }
}
